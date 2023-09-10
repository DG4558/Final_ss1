/*
============================================================================
Name :16b.c
Author : Deepanjali Ghosh
Description :Write a program to implement mandatory locking
b)implement read lock
Date: 27 Aug, 2023.
============================================================================
*/







#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<fcntl.h>


int main()
{
	char buff[512];
	int fd=open("lock.txt",O_RDONLY);
	struct flock lock;
	lock.l_start=0;
	lock.l_len=0;
	lock.l_type=F_RDLCK;
	lock.l_pid=getpid();
	lock.l_whence=SEEK_SET;
	printf("\nBefore critical sec:\n");
	
	 int lck=fcntl(fd,F_SETLKW,&lock);
	if(lck==-1)
	{
		printf("\nError");
	}
	else
	{
		printf("\nRead lock acquired:\n");
	}
	printf("Reading from file\n:");
	while(read(fd,&buff,1))
		printf("%s",buff);
	printf("\nPress any key to release lock");
	getchar();
	lock.l_type=F_UNLCK;
	lck=fcntl(fd,F_SETLK,&lock);
	printf("\nReleasing readlock\n");
	
	close(fd);
	return 0;
}

/*Sample Output:
deepa@deepa-virtual-machine:~/lab2$ gcc 16b.c -o 16b
deepa@deepa-virtual-machine:~/lab2$ ./16b

Before critical sec:

Read lock acquired:
Reading from file
:Locking and Writing

Press any key to release lock

Releasing readlock*/

