/*
============================================================================
Name : 30.c
Author : Deepanjali Ghosh
Description:Write a program to run a script at a specific time using a Daemon process
Date: 6 Sept, 2023.
============================================================================
*/



#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/stat.h>



void main(int argc,char *argv[])
{
	time_t curr,deadlinetime;
	struct tm *deadline;
	pid_t child;
	 if(argc<2)
	 	printf("\nLess argument\n");
	 else
	 {
	 	time(&curr);
	 	deadline=localtime(&curr);
	 	deadline->tm_hour=atoi(argv[1]);
	 	deadline->tm_min=argv[2]==NULL?0:atoi(argv[2]);
	 	deadline->tm_sec=argv[3]==NULL?0:atoi(argv[3]);
	 	
	 	deadlinetime=mktime(deadline);
	 	
	 	int pid=fork();
	 	if(pid==0)
	 	{
	 		setsid();
	 		chdir("/");
	 		umask(0);
	 		do
	 		{
	 			time(&curr);
	 		}while(difftime(deadlinetime,curr)>0);
	 		
	 	printf("\nHello how was your day?\n");
	 	exit(0);
	 }
	 exit(0);
	 }
	}
	
/*Sample Output:	
deepa@deepa-virtual-machine:~/lab2$ gcc 30.c -o 30
deepa@deepa-virtual-machine:~/lab2$ ./30 1
deepa@deepa-virtual-machine:~/lab2$ 
Hello how was your day?
^C*/
	
