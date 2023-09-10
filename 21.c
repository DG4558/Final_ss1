/*
============================================================================
Name : 21.c
Author : Deepanjali Ghosh
Description : Write a prog call fork() and print parent and child process id
Date: 2 Sept, 2023.
============================================================================
*/





#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
	int pid=fork();
	if(pid==0)
	{
		int p_pid=getpid();
		printf("\nI am child process and my id is %d\n",p_pid);
	}
	else if(pid>0)
	{
		int p_pid=getpid();
		printf("\nI am parent process and my id is %d\n",p_pid);
	}
	else
	{ 
		printf("\nError\n");
	}
	return 0;
}


/*Sample Output:

deepa@deepa-virtual-machine:~/lab2$ gedit 21.c
deepa@deepa-virtual-machine:~/lab2$ gcc 21.c -o 21
deepa@deepa-virtual-machine:~/lab2$ ./21

I am parent process and my id is 3081

I am child process and my id is 3082 */

