/*
============================================================================
Name : 25.c
Author : Deepanjali Ghosh
Description : Write a prog to create 3 child process.The parent should wait for a particular child using waitpid
Date: 3 Sept, 2023.
============================================================================
*/





#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {

    int p;
    
    p=fork();
    
    if(p==0)
    {
    	printf("\nI am child 1 pid %d\n",getpid());
    	printf("\nMy child1 parent id is %d\n",getppid());
    }
    else if(p>0)
    {
    	int q;
    	q=fork();
    	if(q==0)
    	{
    		printf("\nI am child 2 and my pid is%d\n",getpid());
    		printf("\nI am child2 and my parent id is%d\n",getppid());
    	}
    	else
    	{
    		int q;
    		q=fork();
    		if(q==0)
    		{
    			printf("\nI am child3 and  my pid is %d and going to sleep\n",getpid());
    			sleep(5);
    		}
    		else
    		{
    			waitpid(q,WIFEXITED(2),WCONTINUED);
    			printf("\n I am parent of all and my pid =%d\n",getpid());
    		}
    	}
    }
    else
    {
    	printf("\nFork error\n");
    }
    return 0;
   }


/* Sample Output:
deepa@deepa-virtual-machine:~/lab2$ gedit 25.c
deepa@deepa-virtual-machine:~/lab2$ gcc 25.c -o 25
deepa@deepa-virtual-machine:~/lab2$ ./25

I am child 1 pid 6384

My child1 parent id is 6383

I am child3 and  my pid is 6386 and going to sleep

I am child 2 and my pid is6385

I am child2 and my parent id is6383

 I am parent of all and my pid =6383*/

