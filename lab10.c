/*
============================================================================
Name : 10 a.c and 10 b.c
Author : Deepanjali Ghosh
Description :Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
a. check the return value of lseek
b. open the file with od and check the empty spaces in between the data.
Date: 15 Aug, 2023.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
	int filedp=open("testfile.txt",O_RDWR|O_CREAT,0644);
	if(filedp==-1)
	{
		printf("Error opening file");
		return 1;
	}
	
	//writing 10 bytes
	write(filedp,"123456789a",10);
	
	off_t newpos=lseek(filedp,10,SEEK_CUR);
	
	if(newpos==-1)
	{
		printf("\nError movind file pointer");
		close(filedp);
		return 1;
	}
	
	printf("\nNew file pointer position:%ld\n",newpos);
	
	write(filedp,"1234567891",10);
	
	 close(filedp);
	 
	  system("od -tc testfile.txt");
	  return 0;
	 
	 }
	
/*Sample Output:	
deepa@deepa-virtual-machine:~/lab2$ gedit lab10.c
deepa@deepa-virtual-machine:~/lab2$ gcc lab10.c -o lab10
deepa@deepa-virtual-machine:~/lab2$ ./lab10

New file pointer position:20
0000000   1   2   3   4   5   6   7   8   9   a       s   u   n   n   y
0000020       d   a   y   1   2   3   4   5   6   7   8   9   1
0000036
*/	
