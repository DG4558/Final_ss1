/*
============================================================================
Name : 24.c
Author : Deepanjali Ghosh
Description : Write a prog to create an orphan process
Date: 3 Sept, 2023.
============================================================================
*/



#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {

    int pid = fork(); 
    
    if (pid == 0) {
      
        printf("Child process created.\n");
        
        
        sleep(5);
        
        printf("Child process exiting.\n");
    } 
    else if (pid > 0) {
        
        printf("Parent process created\n");
        printf("Parent process is terminating.\n");exit(0);
        
        
    } 
    else {
        
        perror("Fork Error");
        return 1;
    }

    return 0;
}

/* Sample output:
deepa@deepa-virtual-machine:~/lab2$ gcc 24.c -o 24
deepa@deepa-virtual-machine:~/lab2$ ./24
Parent process created
Parent process is terminating.
Child process created.
deepa@deepa-virtual-machine:~/lab2$ Child process exiting.*/

