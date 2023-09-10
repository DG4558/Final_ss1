/*
============================================================================
Name : 4.c
Author : Deepanjali Ghosh
Description : Write a prog to open an existing file with read and write mode.Try O-EXCL flag
Date: 10 Aug, 2023.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main(){
	int f= open("testfile1.txt", O_RDWR | O_CREAT | O_EXCL);
	if(f==0)
	{
		printf("already has file");
	}
        printf("f= %d\n", f);
	if(f<0)
	{
		perror("Error");
	}
	close(f);
	return 0;
}	

/*Sample Output:
deepa@deepa-virtual-machine:~/lab2$ gedit lab4.c
deepa@deepa-virtual-machine:~/lab2$ gcc lab4.c -o lab4
deepa@deepa-virtual-machine:~/lab2$ ./lab4
f= 3

deepa@deepa-virtual-machine:~/lab2$ gcc lab4.c -o lab4
deepa@deepa-virtual-machine:~/lab2$ ./lab4
f= -1
Error: File exists*/


