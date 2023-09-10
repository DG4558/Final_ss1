/*
============================================================================
Name : 20.c
Author : Deepanjali Ghosh
Description :Find out the priority of your running program. Modify the priority with nice command
Date: 6 Sept, 2023.
============================================================================
*/









#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/time.h>
#include<sys/resource.h>


int main()
{
	int niceval;
	int pid=getpid();
	
	niceval=getpriority(PRIO_PROCESS,0);
	printf("Pid:%d and nive val=%d\n",pid,niceval);
	 printf("\nPress enter to see changed priority\n");
	 getchar();
	 nice(10);
	 niceval=getpriority(PRIO_PROCESS,0);
	printf("Pid:%d and nive val=%d\n",pid,niceval);
	return 0;
}
/*Sample output:
deepa@deepa-virtual-machine:~/lab2$ ./20
Pid:32875 and nive val=0

Press enter to see changed priority

Pid:32875 and nive val=10*/

