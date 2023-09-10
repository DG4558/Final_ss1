/*
============================================================================
Name : 8.c
Author : Deepanjali Ghosh
Description :Write a prog to open a file in read mode read line by line and display each line as we read.Close while end of file reached
Date: 15 Aug, 2023.
============================================================================
*/


#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>

 

 int main() {
    
    char buf[512];
     
    int f = open("testfile.txt", O_RDONLY);
    if(f== -1)
        printf("Error in opening file");


    while(read(f, &buf, sizeof(buf))){
        printf("%s",buf);
    }

     
    close(f);
    return 0;
}

/* Sample Output:
deepa@deepa-virtual-machine:~/lab2$ gedit testfile.txt
deepa@deepa-virtual-machine:~/lab2$ gcc lab8.c -o lab8
deepa@deepa-virtual-machine:~/lab2$ ./lab8
Today is a sunny day


deepa@deepa-virtual-machine:~/lab2$ gedit testfile.txt
deepa@deepa-virtual-machine:~/lab2$ gcc lab8.c -o lab8
deepa@deepa-virtual-machine:~/lab2$ ./lab8
Today is Sunday.
Today is Sunny Day*/


