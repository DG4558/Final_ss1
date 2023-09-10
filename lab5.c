/*
============================================================================
Name : 5.c
Author : Deepanjali Ghosh
Description : Write a prog to create five files in infinite loop.Run the process in background
Date: 10 Aug, 2023.
============================================================================
*/





#include<stdio.h> 
#include<unistd.h>
#include<fcntl.h>
int main(void){
	int fd1, fd2, fd3 ,fd4 ,fd5;
	while(1){
	fd1=open("f1", O_RDWR | O_CREAT);
	fd2=open("f2", O_RDWR | O_CREAT);
	fd3=open("f3", O_RDWR | O_CREAT);
        fd4=open("f4", O_RDWR | O_CREAT);
        fd5=open("f5", O_RDWR | O_CREAT);
	}
	return 0;
}


