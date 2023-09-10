/*
============================================================================
Name :12.c
Author : Deepanjali Ghosh
Description :Write a program to check opening mode of file using fcntl
Date: 23 Aug, 2023.
============================================================================
*/








#include<stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include<string.h>
int main(){
	
	const char *fn = "lab12.c"; 

       
        int fd= open(fn,O_RDWR);
        if (fd == -1) {
        perror("Error opening file");
        return 1;
         }

        
        int flags = fcntl(fd, F_GETFL) & O_ACCMODE;

	
        if (flags == -1) {
        perror("Error getting file flags");
        close(fd);
        } 
        
        if (flags==0) 
	{
        printf("File is opened in read-only mode.\n");
        }
	else if (flags==1) 
	{
        printf("File is opened in write-only mode.\n");
        } 
	else if (flags==2) 
	{
        printf("File is opened in read-write mode.\n");
        }
	else 
	{
        printf("Unknown file access mode.\n");
        }

        
        close(fd);

    return 0;
}

/*Sample Output:
deepa@deepa-virtual-machine:~/lab2$ gedit lab12.c
deepa@deepa-virtual-machine:~/lab2$ gcc lab12.c -o lab12
deepa@deepa-virtual-machine:~/lab2$ ./lab12
File is opened in read-write mode.*/

