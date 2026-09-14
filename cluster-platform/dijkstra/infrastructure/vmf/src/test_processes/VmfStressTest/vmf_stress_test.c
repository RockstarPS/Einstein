#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif
#include <stdio.h>
#include <stdlib.h>
#include <spawn.h>
#include <errno.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>


#define MAX_FAR_DATA_LEN        8192
#define MAX_TEST_CNT            100

/*prototype*/
bool get_options(int argc, char *argv[]);
void usage(void);
pid_t check_process(char *process_name);

typedef struct
{
    unsigned char  	index;
    unsigned char   wait;
    unsigned char   message_group;
    unsigned char   event;
    unsigned char   near_data[4];
    unsigned int  	far_data_len;
    unsigned char   far_data[MAX_FAR_DATA_LEN];
    bool        	send_time_snap;
    unsigned int  	message_count;
    unsigned int  	message_delay;
    char            path[100];
}options_t;

options_t           options;

char VMF_Bin[200];
char *VMF[] = { VMF_Bin, NULL};
char VMF_Listener_Bin[200];
char VMF_index[5] = { ""};
char VMF_group_id[5] = { ""};
char VMF_msg_count[6] = { ""};
char *VMF_Listener[] = { VMF_Listener_Bin, "-i", VMF_index, "-g", VMF_group_id, "-c", VMF_msg_count, "-s", NULL};
char VMF_Sender_Bin[200];
char VMF_event_id[5] = { ""};
char VMF_Data_Len[5] = { ""};
char *VMF_Sender[] = { VMF_Sender_Bin, "-g", VMF_group_id, "-e", VMF_event_id, "-l", VMF_Data_Len, "-c", VMF_msg_count, "-d", "0", "-w", "10", NULL};

int main(int argc, char *argv[])
{
	pid_t   pid;
	int     ret;
	int len;
	int i;
	int j;

	if (false == get_options(argc,argv))
	{
		printf("Enter appropriate options...\n");
		return -1;
	}

	len = strlen(options.path);
	if(options.path[len-1] != '/')
	{
		options.path[len] = '/';
	}
	
	sprintf(VMF_Bin, "%s%s",  options.path, "vmf");
	sprintf(VMF_Listener_Bin, "%s%s",  options.path, "vmf_listener");
	sprintf(VMF_Sender_Bin, "%s%s",  options.path, "vmf_sender");
	sprintf(VMF_group_id, "%d",  options.message_group);
	sprintf(VMF_event_id, "%d",  options.event);
	sprintf(VMF_msg_count, "%d",  options.message_count);	
	sprintf(VMF_Data_Len, "%d",  options.far_data_len);

	//Check if vMF is running and kill it if running	
	if((pid = check_process(VMF_Bin)) == -1)
	{
		printf("No VMF process running\n");
	}
	else
	{
		printf("kill the running VMF(%d)..\n", pid);
		ret = kill(pid, SIGKILL);
		if(ret == -1)
		{
			printf("unable to kill VMF...\n");
		}
		else
		{
			sleep(2);//delay to update /proc
		}
	}
		
	//Check if vMF_listener is running and kill it if running
	if((pid = check_process(VMF_Listener_Bin)) == -1)
	{
		printf("No VMF_Listener process running\n");
	}
	else
	{	
		ret = kill(pid, SIGKILL);
		if(ret == -1)
		{
			printf("unable to kill VMF_Listener...\n");
		}
		else
		{
			sleep(2);//delay to update /proc
		}
	}
	
	//Check if vMF_Sender is running and kill it if running
	if((pid = check_process(VMF_Sender_Bin)) == -1)
	{
		printf("No VMF_Sender process running\n");
	}
	else
	{		
		ret = kill(pid, SIGKILL);
		if(ret == -1)
		{
			printf("unable to kill VMF_Sender...\n");
		}
		else
		{
			sleep(2);//delay to update /proc
		}
	}
	
	//spawn VMF 
	ret = posix_spawn( &pid, VMF_Bin, NULL, NULL, (char* const*)VMF, NULL);
	if( ret == 0)
	{
		// started
		printf( "Started %s with pid %u \n", VMF_Bin, pid);
	}
	else
	{
		printf( "Failed to start %s ....\n Error: %s \n", VMF_Bin, strerror(errno));
	}
	
	sleep(2);

	printf("\n\n");
	printf("#######################################################################\n");
	for(i = 0; i < 10; i++)
	{
		sprintf(VMF_index, "%d", i);

		ret = posix_spawn( &pid, VMF_Listener_Bin, NULL, NULL, (char* const*)VMF_Listener, NULL);
		if( ret == 0)
		{
			// started
			printf( "Started %s instance %d with pid %u \n", VMF_Listener_Bin, i, pid);
		}
		else
		{
			printf( "Failed to start %s instance %d ....\n Error: %s \n", VMF_Listener_Bin, i, strerror(errno));
		}
	}
	printf("#######################################################################\n");
	printf("\n\n");
	
	sleep(5);
	//Starting VMF_Sender
	ret = posix_spawn( &pid, VMF_Sender_Bin, NULL, NULL, (char* const*)VMF_Sender, NULL);
	if( ret == 0)
	{
		// started
		 printf( "Started %s with pid %u \n", VMF_Sender_Bin, pid);
	}
	else
	{
		printf( "Failed to start %s....\n Error: %s \n", VMF_Sender_Bin, strerror(errno));
	}
}

bool get_options(int argc, char *argv[])
{
	int c;

	/* initialize options */
	options.index = 0;
	options.message_group = 10;
	options.event = 20;
	options.far_data_len = 10;
	options.send_time_snap = false;
	options.message_count = 10;
	options.message_delay = 100;
	options.wait = 0;
	sprintf(options.path,"%s", "/usr/bin");


	if (1==argc)
	{
			/* call without any argument */
			printf("NO command line parameters -- using defaults! Try '-h' for more info.");
			return false;
	}

	while ((c = getopt(argc, argv, "hp:g:c:e:l:")) != -1)
	{
		switch (c)
		{
			case 'h':
				usage();
				return false;
				break;
			 case 'p':
				sprintf(options.path,"%s", optarg);
				break;
			 case 'g':
				options.message_group = atoi(optarg);				
				break;
				/* number of messages (loop counter) */
			case 'c':
				options.message_count=strtoul(optarg, NULL, 0);
				if (options.message_count > MAX_TEST_CNT)
				{
					options.message_count = MAX_TEST_CNT;
				}				
				break;
			 case 'e':
				options.event = atoi(optarg);				
				break;
			 case 'l':
				options.far_data_len = atoi(optarg);
				if (options.far_data_len > MAX_FAR_DATA_LEN)
				{
					options.far_data_len = MAX_FAR_DATA_LEN;
				}				
				break;
			default :
				/* unknown option */
				printf("get_options: %c is an unknown option!", c);
				usage();
				return false;
		}
	}
	return true;
}

pid_t check_process(char *process_name)
{
	const char* directory = "/proc";
	DIR* dir = opendir(directory);
	size_t      taskNameSize = 2048;
	char taskName[taskNameSize];	
	pid_t pid = -1;
	//bool process_status = fail;

	if (dir)
	{
		struct dirent* de = 0;
		
		while ((de = readdir(dir)) != 0)
		{
			if (strcmp(de->d_name, ".") == 0 || strcmp(de->d_name, "..") == 0)
            continue;
			
			int res = sscanf(de->d_name, "%d", &pid);

			if (res == 1)
			{
				// we have a valid pid

				// open the cmdline file to determine what's the name of the process running
				char cmdline_file[1024] = {0};
				sprintf(cmdline_file, "%s/%d/cmdline", directory, pid);				
				FILE* cmdline = fopen(cmdline_file, "r");
		
				if(fscanf(cmdline,"%[^\n]", taskName) > 0)
				{
					// is it the process we care about?
					if (strstr(taskName, process_name) != 0)
					{						
						fprintf(stdout, "A %s process, with PID %d, has been detected.\n", process_name, pid);
						fclose(cmdline);
						//process_status = true;
						break;
					}
					else					
					{						
						pid = -1;
					}
				}
				fclose(cmdline);
			}            
		}
		
		closedir(dir);
	}
	return pid;
}

void usage(void)
{
    printf("******************************************************************************\n");
    printf("** VMF_Stress_Test                                                          **\n");
    printf("******************************************************************************\n");
    printf("**                                                                          **\n");
    printf("**                                                                          **\n");
    printf("**     Opt.   Description                                    Default        **\n");
    printf("**     -h     this help                                                     **\n");
    printf("**     -p     Path to VMF Binary                             %s             **\n", options.path);
    printf("**     -g     message group                                  %d             **\n", options.message_group);
    printf("**     -e     event                                          %d             **\n", options.event);
    printf("**     -l     length of far data                             %d             **\n", options.far_data_len);
    printf("**     -c     message count                                  %d             **\n", options.message_count);
    printf("**                                                                          **\n");
    printf("******************************************************************************\n");
}

