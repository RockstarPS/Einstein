#! python3
"""Fetches latest snapshot data from Coverity server and creates a csv file
containing the list of defects.

Also categorizes the defects based on their 'impact' and logs the impact count
in another csv file for Jenkins to consume.
"""

__author__ = "ssulaim1"
__date__ = "13-Jan-2019"

import os
import json
import string
import urllib
import requests
import csv
import sys

import lib.ce as ce
import lib.error_handler as error
from lib.l_utils import path_safe
from lib.l_utils import read_config
from lib.l_utils import add_date_to_filename


ci_user = 'buildsystem'
ci_pass = 'buildsystem'


def send_request(cov_params, stream):
	stream_name = cov_params['streams'][stream.lower()]
	view_id = urllib.parse.quote(cov_params['plot']['view_id'])
	view_type = urllib.parse.quote(cov_params['plot']['view_type'])
	rows = cov_params['plot']['rows']
	host = cov_params['host']
	port = cov_params['port']

	creds = (ci_user, ci_pass)
	headers = {'Accept': 'text/csv'}
	payload = {'projectId' : stream_name, 'rowCount' : rows}
	url_format = string.Template(cov_params['plot']['url_template_string'])
	url = url_format.substitute(
		host=host, port=port, view_type=view_type, view_id=view_id
	)
	return requests.get(url, auth=creds, headers=headers, params=payload)


@path_safe()
def fetch_view(stream, details_file, count_file):
	try:
		config = read_config(cov_config_file)
		response = send_request(config, stream)
	except KeyError as key:
		raise ce.InvalidStreamError(stream) if str(key)==f'{repr(stream)}' else ce.ConfigFileParamError(str(key))
	except FileNotFoundError as fof:
		raise ce.NoConfigFileError(config_file=cov_config_file)
	if not response.ok:
		raise ce.HTTPRequestFailError(response.status_code)
	rows = tuple(map(bytes.decode, response.content.splitlines()))
	contents = tuple(tuple(row.split(',')) for row in rows)

	def write_defects_list():
		with open(details_file, 'w+') as df:
			for line in rows:
				print(line, file=df)

	def write_defects_count():
		if (stream=="misra") or (stream=="misra_cpp") or (stream=="misra_gip"):
			try: impact_index = contents[0].index('"Standard: MISRA Category"')
			except ValueError: raise ce.NoImpactColumnError
			impact_counter = {'Advisory': 0, 'Mandatory': 0, 'Required': 0, 'None': 0}
		elif (stream=="cert_c") or (stream=="cert_cpp"):
			try: impact_index = contents[0].index('"Standard: CERT Category"')
			except ValueError: raise ce.NoImpactColumnError
			impact_counter = {'L1': 0, 'L2': 0, 'L3': 0, 'None': 0}
		else:
			try: impact_index = contents[0].index('"Impact"')
			except ValueError: raise ce.NoImpactColumnError
			impact_counter = {'Low': 0, 'High': 0, 'Medium': 0}
		for row in set(contents[1:]):
			impact_counter[row[impact_index].strip('"')] += 1
		with open(count_file, 'w+') as cf:
			count = [[key, str(val)] for key, val in impact_counter.items()]
			count_for_csv = [*zip(*count)]
			print(','.join(count_for_csv[0]), file=cf)
			print(','.join(count_for_csv[1]), file=cf)

	if details_file: write_defects_list()
	if count_file: write_defects_count()


@path_safe()
def build_breaker():
	with open(static_defects_count_file, 'r') as file:
		reader = list(csv.reader(file))
		if (int(reader[1][1]) != 0) or (int(reader[1][2]) != 0):
			print(f'High defects in static analysis = {reader[1][1]}')
			print(f'Medium defects in static analysis = {reader[1][2]}')
			exit(0)
		else:
			print(f'Zero High & Medium defects in static analysis')


def main():
	Read_Variant = sys.argv[1].strip()
	try:
		if (Read_Variant.find("VIP") != -1):
			fetch_view('static', static_defects_file, static_defects_count_file)
			fetch_view('misra', misra_defects_file, misra_defects_count_file)
			#fetch_view('his', his_defects_file, his_defects_count_file)
			#fetch_view('cert_c', cert_c_defects_file, cert_c_defects_count_file)
		elif (Read_Variant.find("BL") != -1):
			fetch_view('bl_static', static_defects_file, static_defects_count_file)
			fetch_view('bl_misra', misra_defects_file, misra_defects_count_file)
			fetch_view('bl_his', his_defects_file, his_defects_count_file)
			fetch_view('bl_cert_c', cert_c_defects_file, cert_c_defects_count_file)
		elif (Read_Variant.find("HSM") != -1):
			fetch_view('hsm_static', static_defects_file, static_defects_count_file)
			fetch_view('hsm_misra', misra_defects_file, misra_defects_count_file)
			fetch_view('hsm_cert_c', cert_c_defects_file, cert_c_defects_count_file)
		else:
			fetch_view('static_gip', static_defects_file, static_defects_count_file)
			fetch_view('misra_gip', misra_defects_file, misra_defects_count_file)
			fetch_view('misra_cpp', misra_cpp_defects_file, misra_cpp_defects_count_file)
			fetch_view('cert_cpp', cert_cpp_defects_file, cert_cpp_defects_count_file)
			fetch_view('cert_c', cert_c_defects_file, cert_c_defects_count_file)
	except Exception as e:
		error.visit(e, config_file=cov_config_file)
	else:
		print('Generated defect files and defect count files')
		print(f'Static defects: {static_defects_file}')
		print(f'MISRA defects: {misra_defects_file}')		
		if (Read_Variant.find("GIP") != -1):
			print(f'MISRACPP defects: {misra_cpp_defects_file}')
			#print(f'CERTCPP defects: {cert_cpp_defects_file}')
		#else:
			#print(f'CERT_C defects: {cert_c_defects_file}')
		
		#build_breaker()


if __name__ == '__main__':
	path_config_file = 'logfile_paths.json'
	cov_config_file = 'cov_params.json'

	try:
		Read_Variant=sys.argv[1].strip()
		paths = read_config(path_config_file)
		if (Read_Variant.find("VIP") != -1):
			static_defects_file = add_date_to_filename(paths['backup_files']['coverity_static'])
			misra_defects_file = add_date_to_filename(paths['backup_files']['coverity_misra'])
			#his_defects_file = add_date_to_filename(paths['backup_files']['coverity_his'])
			#cert_c_defects_file = add_date_to_filename(paths['backup_files']['coverity_cert_c'])
			static_defects_count_file = paths['csv_plot_files']['coverity_static']
			misra_defects_count_file = paths['csv_plot_files']['coverity_misra']
			#his_defects_count_file = paths['csv_plot_files']['coverity_his']
			#cert_c_defects_count_file = paths['csv_plot_files']['coverity_cert_c']
		elif (Read_Variant.find("BL") != -1):
			static_defects_file = add_date_to_filename(paths['backup_files']['bl_coverity_static'])
			misra_defects_file = add_date_to_filename(paths['backup_files']['bl_coverity_misra'])
			his_defects_file = add_date_to_filename(paths['backup_files']['bl_coverity_his'])
			cert_c_defects_file = add_date_to_filename(paths['backup_files']['bl_coverity_cert_c'])
			static_defects_count_file = paths['csv_plot_files']['bl_coverity_static']
			misra_defects_count_file = paths['csv_plot_files']['bl_coverity_misra']
			his_defects_count_file = paths['csv_plot_files']['bl_coverity_his']
			cert_c_defects_count_file = paths['csv_plot_files']['bl_coverity_cert_c']
		elif (Read_Variant.find("HSM") != -1):
			static_defects_file = add_date_to_filename(paths['backup_files']['hsm_coverity_static'])
			misra_defects_file = add_date_to_filename(paths['backup_files']['hsm_coverity_misra'])
			cert_c_defects_file = add_date_to_filename(paths['backup_files']['hsm_coverity_cert_c'])
			static_defects_count_file = paths['csv_plot_files']['hsm_coverity_static']
			misra_defects_count_file = paths['csv_plot_files']['hsm_coverity_misra']
			cert_c_defects_count_file = paths['csv_plot_files']['hsm_coverity_cert_c']
		else:
			static_defects_file = add_date_to_filename(paths['backup_files']['coverity_static_gip'])
			misra_defects_file = add_date_to_filename(paths['backup_files']['coverity_misra_gip'])
			misra_cpp_defects_file = add_date_to_filename(paths['backup_files']['coverity_misra_cpp'])
			cert_cpp_defects_file = add_date_to_filename(paths['backup_files']['coverity_cert_cpp'])
			cert_c_defects_file = add_date_to_filename(paths['backup_files']['coverity_cert_c'])
			static_defects_count_file = paths['csv_plot_files']['coverity_static_gip']
			misra_defects_count_file = paths['csv_plot_files']['coverity_misra_gip']
			misra_cpp_defects_count_file = paths['csv_plot_files']['coverity_misra_cpp']
			cert_cpp_defects_count_file = paths['csv_plot_files']['coverity_cert_cpp']
			cert_c_defects_count_file = paths['csv_plot_files']['coverity_cert_c']

		backup_dirname = os.path.dirname(static_defects_file)
		if not os.path.isdir(backup_dirname):
			os.mkdir(backup_dirname)
	except Exception as e:
		error.visit(e, config_file=path_config_file, exit_code=0)
	else:
		main()
