/*
============================================================================
Name :13.c
Author : Deepanjali Ghosh
Description :Write a program to wait for stdin for 10 secs using select.Write a print statement 
to verify whether input available within 10 sec
Date: 25 Aug, 2023.
============================================================================
*/






#include<sys/types.h>
#include<sys/stat.h>
#include<sys/select.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>

int main()
{
    int val;
    fd_set rd;
    //timer variable
    struct timeval t;
    
    FD_ZERO(&rd);
    
    FD_SET(0,&rd);
   

    t.tv_sec =10;
    printf("please wait for 10 seconds\n");
    val = select(1, &rd, NULL, NULL, &t);
 
   
    if (val == -1)
         perror("select()");
    else if (val)
         printf("Data is available now.\n");
         
    else
         printf("Time exceeded\n");

   return 0;

}

/*Sample output:
deepa@deepa-virtual-machine:~/lab2$ gedit lab13.c
deepa@deepa-virtual-machine:~/lab2$ gcc lab13.c -o lab13
deepa@deepa-virtual-machine:~/lab2$ ./lab13
please wait for 10 seconds
abba
Data is available now.


deepa@deepa-virtual-machine:~/lab2$ gedit lab13.c
deepa@deepa-virtual-machine:~/lab2$ gcc lab13.c -o lab13
deepa@deepa-virtual-machine:~/lab2$ ./lab13
please wait for 10 seconds
Time exceeded*/


