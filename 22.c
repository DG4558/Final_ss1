/*
============================================================================
Name : 22.c
Author : Deepanjali Ghosh
Description : Write a prog to open a file call fork and then write to file by both parent and child process
Date: 2 Sept, 2023.
============================================================================
*/





#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>


int main()
{

	int fd=open("output22.txt",O_CREAT|O_WRONLY,0644);
	if(fd==-1)
	{
		perror("\nError in opening file\n");
		exit(0);
	}
	
	int pid=fork();
	
	if(pid==0)
	{
		char msg[]="I am child process";
		write(fd,msg,sizeof(msg));
		printf("\nI am child and writing to file\n");
	}
	else if(pid>1)
	{
		char msg[]="I am parent process";
		write(fd,msg,sizeof(msg));
		printf("\nI am parent and writing to file\n");
	}
	else
	{
		printf("\nError in fork\n");
	}
	return 0;
}


/* Sample output

deepa@deepa-virtual-machine:~/lab2$ gcc 22.c -o 22
deepa@deepa-virtual-machine:~/lab2$ ./22

I am parent and writing to file

I am child and writing to file

output22.txt:

I am parent process\00I am child process\00*/



	
