

/*
============================================================================
Name : 6.c
Author : Deepanjali Ghosh
Description :Write a prog to take i/p from stdin and display on stdout using read/write system calls
Date: 15 Aug, 2023.
============================================================================
*/


#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


int main()
{
    char buf[512];
    
    
    printf("\nEnter input\n");
    
    
    
    read(0, buf, 32);
    
    
    printf("\nThe output is:\n");
    write(1, buf, 32);
    return 0;
}

/* Sample output
deepa@deepa-virtual-machine:~/lab2$ gedit lab6.c
deepa@deepa-virtual-machine:~/lab2$ gcc lab6.c -o lab6
deepa@deepa-virtual-machine:~/lab2$ ./lab6

Enter input
abbbc

The output is:
abbbc*/

