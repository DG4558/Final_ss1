/*
============================================================================
Name : 23.c
Author : Deepanjali Ghosh
Description : Write a prog to create zombie state of running process
Date: 3 Sept, 2023.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    int pid;

    pid = fork();

    if (pid == 0) {
        
        printf("Child process is exiting.\n");
        exit(0);
    } 
    else if (pid > 0) {
        
        printf("Parent process is going to sleep.\n");
        sleep(10);
        printf("Parent process is exiting.\n");
    } 
    else {
        perror("Fork error");
        exit(1);
    }

    return 0;
}


/* Sample output:
deepa@deepa-virtual-machine:~/lab2$ gedit 23.c
deepa@deepa-virtual-machine:~/lab2$ gcc 23.c -o 23
deepa@deepa-virtual-machine:~/lab2$ ./23
Parent process is going to sleep.
Child process is exiting.
Parent process is exiting.*/


