import os
import sys
import getopt
import copy
import csv

g_num_samples = 0
prev_cpu_load  = list()
curr_load_list = list()

cpu_load_data  = list()
mem_load_data  = list()
proc_load_data = dict()
pmem_load_data  = list()

def process_pmem_data(line):
	string_array = line[line.find("PID-"):].split(':')
	pid = string_array[0]
	mem = string_array[1][:-1]
	proc_load_data[pid]["pmem"].insert(g_num_samples, int(mem))

def process_kgsl_pmem_data(line):
	string_array = line[line.find("PID-"):].split(':')
	pid = string_array[0]
	mem = string_array[1][:-1]
	proc_load_data[pid]["kgsl_pmem"].insert(g_num_samples, int(mem))

def process_cpu_data(line):
	global prev_cpu_load
	global cpu_load_list
	global cpu_load_data

	if "CPU-" in line:
		string_array = line[line.find("CPU-"):].split()
		curr_load_list.append(string_array)
	elif "CPU:" in line:
		if(len(curr_load_list) > 0):
			if(len(prev_cpu_load) > 0):
				temp_cpu_load_data = list()
				temp_cpu_load_data.append(len(cpu_load_data))
				for prev_cpu, curr_cpu in zip(prev_cpu_load, curr_load_list):
					temp1 = int(curr_cpu[1][:-1]) - int(prev_cpu[1][:-1])
					temp2 = int(curr_cpu[2]) - int(prev_cpu[2])
					temp_cpu_load_data.append(abs(round(100 - (temp2 * 100 / temp1), 2)))
				cpu_load_data.append(temp_cpu_load_data)
			prev_cpu_load = copy.deepcopy(curr_load_list)
			curr_load_list.clear()

def process_mem_data(line):
	string_array = line[line.find("MEM:"):].split()
	temp_mem_load_data = list()
	temp_mem_load_data.append(len(mem_load_data))
	temp_mem_load_data.append(string_array[1][:-1])
	temp_mem_load_data.append(string_array[2][:-1])
	mem_load_data.append(temp_mem_load_data)

def process_proc_data(line):
	global proc_load_data
	global prev_proc_cpu_load
	
	string_array = line[line.find("PID-"):].split(':')
	pid = string_array[0]
	name = string_array[1]
	if(len(proc_load_data) > 0) and (pid in proc_load_data):
		string_array_mem = string_array[4].split(',')
		stack_sz = int(string_array_mem[0])
		text_sz  = int(string_array_mem[1])
		data_sz  = int(string_array_mem[2])
		proc_load_data[pid]["mem"].insert(g_num_samples, stack_sz + text_sz + data_sz)
		
		string_array_res = string_array[2].split(',')
		proc_load_data[pid]["num_thread"].insert(g_num_samples, int(string_array_res[0]))
		proc_load_data[pid]["num_timer"].insert(g_num_samples, int(string_array_res[1]))
		proc_load_data[pid]["num_fd"].insert(g_num_samples, int(string_array_res[2]))
		proc_load_data[pid]["num_channel"].insert(g_num_samples, int(string_array_res[3]))
		proc_load_data[pid]["num_irq"].insert(g_num_samples, int(string_array_res[4]))
		
		string_array_cpu = string_array[3].split(',')
		if(len(proc_load_data[pid]["prev_cpu"]) > 0):
			t_delta = int(string_array_cpu[0]) - int(proc_load_data[pid]["prev_cpu"][0])
			su_delta = (int(string_array_cpu[2]) + int(string_array_cpu[3])) - (int(proc_load_data[pid]["prev_cpu"][2]) + int(proc_load_data[pid]["prev_cpu"][3]))
			proc_cpu_load = 0
			if t_delta > 0:
				proc_cpu_load = abs(round(su_delta * 100 / t_delta, 2))
			proc_load_data[pid]["cpu"].insert(g_num_samples, proc_cpu_load)
		proc_load_data[pid]["prev_cpu"] = copy.deepcopy(string_array_cpu)
	else:
		proc_load_data[pid] = dict();
		proc_load_data[pid]["name"] = os.path.basename(name).strip()
		proc_load_data[pid]["cpu"] = list()
		proc_load_data[pid]["mem"] = list()
		proc_load_data[pid]["num_thread"] = list()
		proc_load_data[pid]["num_timer"] = list()
		proc_load_data[pid]["num_fd"] = list()
		proc_load_data[pid]["num_channel"] = list()
		proc_load_data[pid]["num_irq"] = list()
		proc_load_data[pid]["prev_cpu"] = list()
		proc_load_data[pid]["pmem"] = list()
		proc_load_data[pid]["kgsl_pmem"] = list()

def export_proc_data(filename, param):
	global proc_load_data

	print("Exporting PROC " + param + " load...")

	header = list() 
	header.append("S.No")
	for key in proc_load_data.keys():
		header.append(key + "," + proc_load_data[key]["name"])

	with open(filename, 'w', newline='') as file:
		writer = csv.writer(file)
		writer.writerow(header)
		for idx in range(g_num_samples):
			row = list()
			row.append(idx)
			for element in proc_load_data:
				if( idx < len (proc_load_data[element][param]) ):
					row.append( proc_load_data[element][param][idx] )
				else:
					row.append( 0 )
			writer.writerow( row )
		file.close()

def export_res_data(filename):
	print("Exporting RES load...")

	header = list()
	num_cpus = len(cpu_load_data[1])
	header.append("S.No")
	header.append("Threads")
	header.append("Timers")
	header.append("FDs")
	header.append("Channels")
	header.append("IRQs")
	
	with open(filename, 'w', newline='') as file:
		writer = csv.writer(file)
		writer.writerow(header)
		for idx in range(g_num_samples):
			res_row = list()
			res_row.append(idx)
			num_thread = 0;
			num_timer = 0;
			num_fd = 0;
			num_channel = 0;
			num_irq = 0;
			for element in proc_load_data:
				if( idx < len (proc_load_data[element]["num_thread"]) ):
					num_thread = num_thread + int(proc_load_data[element]["num_thread"][idx])
				if( idx < len (proc_load_data[element]["num_timer"]) ):
					num_timer = num_timer + int(proc_load_data[element]["num_timer"][idx])
				if( idx < len (proc_load_data[element]["num_fd"]) ):
					num_fd = num_fd + int(proc_load_data[element]["num_fd"][idx])
				if( idx < len (proc_load_data[element]["num_channel"]) ):
					num_channel = num_channel + int(proc_load_data[element]["num_channel"][idx])
				if( idx < len (proc_load_data[element]["num_irq"]) ):
					num_irq = num_irq + int(proc_load_data[element]["num_irq"][idx])
			res_row.append(num_thread)
			res_row.append(num_timer)
			res_row.append(num_fd)
			res_row.append(num_channel)
			res_row.append(num_irq)
			writer.writerow(res_row)

	file.close()

def export_cpu_data(filename):
	global cpu_load_data

	print("Exporting CPU load...")

	header = list()
	num_cpus = len(cpu_load_data[1])
	header.append("S.No")
	for x in range(num_cpus):
		header.append("CPU-" + str(x))

	with open(filename, 'w', newline='') as file:
		writer = csv.writer(file)
		writer.writerow(header)
		for element in cpu_load_data:
			writer.writerow(element)
	file.close()

def export_mem_data(filename):
	global cpu_load_data

	print("Exporting MEM load...")

	header = list()
	header.append("S.No")
	header.append("Total Memory")
	header.append("Used Memory")

	with open(filename, 'w', newline='') as file:
		writer = csv.writer(file)
		writer.writerow(header)
		for element in mem_load_data:
			writer.writerow(element)
	file.close()

def main():
	global g_num_samples
	filename = ""

	try:
		opts, args = getopt.getopt(sys.argv[1:], "f:",["file="])
	except getopt.GetoptError as err:
		print ("Usage : ")
		sys.exit(2)
	for o, a in opts:
		if o in ("-f", "--file"):
			filename = a
		else:
			assert False, "unhandled option"
	
	if(len(filename) == 0):
		print ("Usage : ")
		sys.exit(2)
	
	print ("Processing " + filename)
	
	resmon_start = False
	pmem_start = False
	kgsl_pmem_start = False
	try:
		with open(filename, 'r') as f:
			lines = f.readlines()
			for line in lines:
				if "RESMON: START" in line:
					resmon_start = True
				elif "RESMON: END" in line:
					resmon_start = False
					g_num_samples = g_num_samples + 1
				elif "KGSL_PMEM: START" in line:
					kgsl_pmem_start = True
				elif "KGSL_PMEM: END" in line:
					kgsl_pmem_start = False
				elif "PMEM: START" in line:
					pmem_start = True
				elif "PMEM: END" in line:
					pmem_start = False
				elif resmon_start == True:
					if "CPU:" in line or "CPU-" in line:
						process_cpu_data(line)
					elif "MEM:" in line:
						process_mem_data(line)
					elif "PID-" in line:
						if pmem_start == True:
							process_pmem_data(line)
						elif kgsl_pmem_start == True:
							process_kgsl_pmem_data(line)
						else:
							process_proc_data(line)
	except IOError as e:
		print("I/O error({0}): {1}".format(e.errno, e.strerror))
	except UnboundLocalError as e:
		print("File doesn't have valid data!!!")
	except:
		print("Unexpected error:", sys.exc_info()[0])

	if(os.path.isdir("output") == False):
		os.mkdir("output")

	print("Total samples " + str(g_num_samples));
	export_cpu_data( "output/sys_cpu_load.csv" )
	export_mem_data( "output/sys_mem_load.csv" )
	export_res_data( "output/sys_res_load.csv" )
	export_proc_data( "output/proc_cpu_load.csv", "cpu" )
	export_proc_data( "output/proc_mem_load.csv", "mem" )
	export_proc_data( "output/proc_thread_load.csv", "num_thread" )
	export_proc_data( "output/proc_timer_load.csv", "num_timer" )
	export_proc_data( "output/proc_fd_load.csv", "num_fd" )
	export_proc_data( "output/proc_channel_load.csv", "num_channel" )
	export_proc_data( "output/proc_pmem_load.csv", "pmem" )
	export_proc_data( "output/proc_kgsl_pmem_load.csv", "kgsl_pmem" )

if __name__ == "__main__":
	main()
