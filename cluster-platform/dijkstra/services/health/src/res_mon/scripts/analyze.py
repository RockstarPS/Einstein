import sys
import getopt
import copy
import csv

def analyze_proc_rsource_leaks(filename):
	threshold = 10
	samples = 10

	values = dict()
	header = list()
	prev_value = list()
	with open(filename, newline='') as file:
		reader = csv.reader(file)
		for row in reader:
			row.pop(0)
			if len(header) > 0:
				if len(prev_value) > 0:
					for proc, prev, curr in zip(header, prev_value, row):
						if proc in values:
							if float(prev) < float(curr):
								values[proc] = values[proc] + 1
							elif float(prev) > float(curr):
								values[proc] = values[proc] - 1
							else:
								pass
						else:
							values[proc] = 1
				prev_value = copy.deepcopy(row)
			else:
				header = copy.deepcopy(row)

	for proc in values:
		if values[proc] > 1:
			print (proc + " " + str(values[proc]))

def analyze_proc_restarts(filename):
	proc_name = dict()
	with open(filename, newline='') as file:
		reader = csv.reader(file)
		row = next(reader)
		for item in row[1:]:
			string_array = item.split(',')
			pid  = string_array[0]
			name = string_array[1]
			if name in proc_name:
				proc_name[name].append(pid)
			else:
				proc_name[name] = list()
				proc_name[name].append(pid)
	for name in proc_name:
		if len(proc_name[name]) > 1:
			print( name + ",", end =" "),
			for pid in proc_name[name]:
				print (pid, end =" ")
			print("")

def analyze_proc_top_consumers(filename, threshold):
	top_list = dict()
	header = list()
	with open(filename, newline='') as file:
		reader = csv.reader(file)
		for row in reader:
			if(len(header) == 0):
				header = copy.deepcopy(row)
			else:
				idx = 1
				for item in row[1:]:
					value = float(item)
					if value >= threshold:
						if header[idx] in top_list:
							if top_list[header[idx]] < value:
								top_list[header[idx]] = value
						else:
							top_list[header[idx]] = value
					idx = idx + 1
	
	for element in top_list:
		print (element + ", " + str(top_list[element]))

def main():
	cpu_load = 0
	mem_load = 0
	pmem_load = 0
	kgsl_pmem_load = 0
	thread_load = 0
	timer_load = 0
	fd_load = 0
	channel_load = 0
	
	try:
		opts, args = getopt.getopt(sys.argv[1:], "c:m:p:k:t:T:f:C",["cpu=", "mem=", "pmem=", "kgsl_pmem=", "thread=", "timer=", "fd=", "channel=" ])
	except getopt.GetoptError as err:
		print ("Usage : ")
		sys.exit(2)
	for o, a in opts:
		if o in ("-c", "--cpu"):
			cpu_load = float(a)
		elif o in ("-m", "--mem"):
			mem_load = float(a)
		elif o in ("-p", "--pmem"):
			pmem_load = float(a)
		elif o in ("-k", "--kgsl_pmem"):
			kgsl_pmem_load = float(a)
		elif o in ("-k", "--thread"):
			thread_load = float(a)
		elif o in ("-T", "--timer"):
			timer_load = float(a)
		elif o in ("-f", "--fd"):
			fd_load = float(a)
		elif o in ("-C", "--channel"):
			channel_load = float(a)
		else:
			assert False, "unhandled option"
	
	if(cpu_load > 0):
		print ("**********************")
		print ("Top CPU consumers")
		print ("**********************")
		analyze_proc_top_consumers("output/proc_cpu_load.csv", cpu_load)
		print ("")
	if(mem_load > 0):
		print ("**********************")
		print ("Top MEM consumers")
		print ("**********************")
		analyze_proc_top_consumers("output/proc_mem_load.csv", mem_load*1024*1024)
		print ("")
	if(pmem_load > 0):
		print ("**********************")
		print ("Top PMEM consumers")
		print ("**********************")
		analyze_proc_top_consumers("output/proc_pmem_load.csv", mem_load*1024*1024)
		print ("")
	if(kgsl_pmem_load > 0):
		print ("**********************")
		print ("Top PMEM ( KGSL ) consumers")
		print ("**********************")
		analyze_proc_top_consumers("output/proc_kgsl_pmem_load.csv", mem_load*1024*1024)
		print ("")
	if(thread_load > 0):
		print ("**********************")
		print ("Top Thread creators ")
		print ("**********************")
		analyze_proc_top_consumers("output/proc_thread_load.csv", thread_load)
		print ("")
	if(timer_load > 0):
		print ("**********************")
		print ("Top Timer creators ")
		print ("**********************")
		analyze_proc_top_consumers("output/proc_timer_load.csv", timer_load)
		print ("")
	if(fd_load > 0):
		print ("**********************")
		print ("Top File Desc creators")
		print ("**********************")
		analyze_proc_top_consumers("output/proc_fd_load.csv", fd_load)
		print ("")
	if(channel_load > 0):
		print ("**********************")
		print ("Top Channel creators ")
		print ("**********************")
		analyze_proc_top_consumers("output/proc_timer_load.csv", channel_load)
		print ("")
	
	print ("***********************************")
	print ("Potential Issues - Process Restarts")
	print ("***********************************")
	analyze_proc_restarts("output/proc_cpu_load.csv")
	print ("")
	
	print ("***********************************")
	print ("Potential Issues - Resource Leaks  ")
	print ("***********************************")
	print ("Memory                             ")
	print ("-----------------------------------")
	analyze_proc_rsource_leaks("output/proc_mem_load.csv")
	print ("")
	print ("Threads                            ")
	print ("-----------------------------------")
	analyze_proc_rsource_leaks("output/proc_thread_load.csv")
	print ("")
	print ("Timers                             ")
	print ("-----------------------------------")
	analyze_proc_rsource_leaks("output/proc_timer_load.csv")
	print ("")
	print ("Channels                           ")
	print ("-----------------------------------")
	analyze_proc_rsource_leaks("output/proc_channel_load.csv")
	print ("")
	print ("File Descriptors                   ")
	print ("-----------------------------------")
	analyze_proc_rsource_leaks("output/proc_fd_load.csv")
	print ("")

if __name__ == "__main__":
	main()
