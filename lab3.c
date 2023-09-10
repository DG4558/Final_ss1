/*
============================================================================
Name : 3.c
Author : Deepanjali Ghosh
Description : Write a prog to create file and print file descriptor value.Use creat system call
Date: 10 Aug, 2023.
============================================================================
*/





#include<stdio.h>
#include<unistd.h>
#include <fcntl.h>
int main()
{

       int c;
       mode_t mode=S_IRUSR|S_IRWXU|S_IRWXG;
       char *fn= "testfile.txt";
       c = creat(fn,mode);
       int fd = open(fn, O_RDONLY);

       printf("fd = %d\n" , fd);
       if(c<0){
	       perror("Error");
       }
       close(fd);
       return 0;

}

/*Sample Output:
deepa@deepa-virtual-machine:~/lab2$ gedit lab3.c
deepa@deepa-virtual-machine:~/lab2$ gcc lab3.c -o lab3
deepa@deepa-virtual-machine:~/lab2$ ./lab3
fd = 4*/

