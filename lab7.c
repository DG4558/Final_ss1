/*
============================================================================
Name : 7.c
Author : Deepanjali Ghosh
Description :Write a prog to copy file1 into file2
Date: 15 Aug, 2023.
============================================================================
*/






#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
int main(){

int fd1=open("tt1.txt", O_RDONLY);
int fd2=open("tt.txt",O_WRONLY);
if(fd1==-1 || fd2==-1)
	printf("Your system is useless\n");

while(1){
char buf;
int read_byte=read(fd1,&buf,1);
printf("Reading byte:%d\n",read_byte);
if(read_byte==0)
	break;
int write_bytes=write(fd2,&buf,1);
printf("Writing byte:%d\n",write_bytes);
}
close(fd1);
close(fd2);
return 0;
}


/*Sample Output:
deepa@deepa-virtual-machine:~/lab2$ gedit lab7.c
deepa@deepa-virtual-machine:~/lab2$ gcc lab7.c -o lab7
deepa@deepa-virtual-machine:~/lab2$ ./lab7
Reading byte:1
Writing byte:1
Reading byte:1
Writing byte:1
Reading byte:1
Writing byte:1
Reading byte:1
Writing byte:1
Reading byte:1
Writing byte:1
Reading byte:1
Writing byte:1
Reading byte:1
Writing byte:1
Reading byte:1
Writing byte:1
Reading byte:0*/

