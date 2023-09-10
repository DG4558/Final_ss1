/*
============================================================================
Name :16a.c
Author : Deepanjali Ghosh
Description :Write a program to implement mandatory locking
a)implement write lock
Date: 27 Aug, 2023.
============================================================================
*/







#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>

int main()
{
	struct flock lock;
	int fd;
	lock.l_start=0;//mandatory locking
	lock.l_len=0;//mandatory locking
	lock.l_whence=SEEK_SET;
	lock.l_pid=getpid();
	lock.l_type=F_WRLCK;
	fd=open("lock.txt",O_RDWR);
	printf("\nBefore critical sec:\n");
	int lck=fcntl(fd,F_SETLKW,&lock);
	if(lck==-1)
	{
		printf("\nError");
	}
	else
	{
		printf("write lock acquired:\n");
	}
	int w=write(fd,"Locking and Writing\n",sizeof("Locking and Writing\n"));
	if(w<0)
		perror("Write failed:");
	else
		printf("Write successful\n");
		
	printf("\nPress any key to release lock");
	
	getchar();
	lock.l_type=F_UNLCK;
	lck=fcntl(fd,F_SETLK,&lock);
	printf("\nReleasing write lock\n");
	close(fd);
	return 0;
}


/*Sample Output:
deepa@deepa-virtual-machine:~/lab2$ gedit 16a.c
deepa@deepa-virtual-machine:~/lab2$ gcc 16a.c -o 16a
deepa@deepa-virtual-machine:~/lab2$ ./16a

Before critical sec:
write lock acquired:
Write successful

Press any key to release lock

Releasing write lock


terminal1:
deepa@deepa-virtual-machine:~/lab2$ gedit 16a2.c
deepa@deepa-virtual-machine:~/lab2$ gcc 16a2.c -o 16a2
deepa@deepa-virtual-machine:~/lab2$ ./16a2

Before critical sec:
write lock acquired:
Write successful

Press any key to release lock

terminal2:
deepa-virtual-machine:~/lab2$ gcc 16a.c -o 16a
deepa@deepa-virtual-machine:~/lab2$ ./16a

Before critical sec:*/





