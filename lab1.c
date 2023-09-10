
/*
============================================================================
Name :1.c
Author : Deepanjali Ghosh
Description :Create the following types of a files using (i) shell command (ii) system call
a. soft link (symlink system call)
b. hard link (link system call)
c. FIFO (mkfifo Library Function or mknod system call)
Date: 25 Aug, 2023.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main(){
	int a=symlink("deepa.txt","bba");
	printf("Symlink=%d\n",a);
	if(a<0)
	{
	perror("Softlink Failed");
	return 1;
	}

	int f=link("dona.txt","aab");
	printf("hardlink=%d\n",f);
	  if(f<0)
	  {perror(" Hard Failed");
	  }

	int b= mknod("ababa",S_IFIFO,0);

	if(b<0)
		perror("Failed");
		
	return 0;
}	
