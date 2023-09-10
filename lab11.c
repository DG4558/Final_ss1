/*
============================================================================
Name : 11 a.c  ,11 b.c ,11 c.c
Author : Deepanjali Ghosh
Description :Write a program to open a file ,duplicate thw file descriptor and append file with both descriptor 
a.use dup
b. use dup2
c.use fcntl
Date: 15 Aug, 2023.
============================================================================
*/






#include<stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include<string.h>
int main(){

	//Dup()
	int f = open("dup.txt", O_WRONLY | O_APPEND);
	
	if(f< 0)
		printf("Error opening the file\n");
	


	int copy_f= dup(f);
		
	

	write(copy_f,"written by new fd\n" ,strlen("written by new fd\n"));
		
	write(f,"written by old fd\n",strlen("written by old fd\n"));
	
	//Dup2()

	int fd = open("dup2.txt",O_WRONLY | O_APPEND);
      
	int copy_fd;
       copy_fd=dup2(fd,1) ; 
       
       write(copy_fd," written by new fd\n", strlen("written by new fd\n"));
		
	write(fd,"written by old fd\n",strlen("written by old fd\n"));
	
	
	//Fcntl()
	
	int ff = open("fcntl.txt",O_WRONLY | O_APPEND);
	if(ff<0)
		perror("Error");	
	int copy_ff=fcntl(ff,F_DUPFD,0);
		if(copy_ff<0)
		perror("Error in duplicating");
	
	 write(copy_ff," written by new fd\n", strlen("written by new fd\n"));
		
	write(ff,"written by old fd\n",strlen("written by old fd\n"));
          
        
       close(f);
       close(copy_f);
       close(fd);
       close(copy_fd);
       close(ff);
       close(copy_ff);

	
	return 0;
}
