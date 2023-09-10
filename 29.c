/*
============================================================================
Name : 29.c
Author : Deepanjali Ghosh
Description :Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,
SCHED_RR)
Date: 6 Sept, 2023.
============================================================================
*/






#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <unistd.h>
#include <errno.h>

int main() {
    int policy;
    struct sched_param p;
    int pid = getpid();

    int get_policy = sched_getscheduler(0);
    if (get_policy == -1) {
        perror("sched_getscheduler");
        
    }

   
    if (sched_getparam(pid, &p) == -1) {
        perror("sched_getparam");
        
    }

    printf("Current scheduling policy: ");
    switch (get_policy) {
        case SCHED_FIFO:
            printf("SCHED_FIFO\n");
            break;
        case SCHED_RR:
            printf("SCHED_RR\n");
            break;
        case SCHED_OTHER:
            printf("SCHED_OTHER\n");
            break;
        default:
            printf("Unknown\n");
            break;
    }

    printf("Current priority: %d\n", p.sched_priority);

    
    struct sched_param new_p;
    new_p.sched_priority = 50;

    if (sched_setscheduler(pid, SCHED_FIFO, &new_p) == -1) {
        perror("sched_setscheduler");
        
    }
    else
    printf("\nScheduling policy changed to SCHED_FIFO\n");
    
     struct sched_param new_pp;
    new_pp.sched_priority = 50;

    if (sched_setscheduler(pid, SCHED_RR, &new_pp) == -1) {
        perror("sched_setscheduler");
        
    }
    else
    printf("\nScheduling policy changed to SCHED_RR\n");
    
    

    return 0;
}


/*Sample Output:
deepa@deepa-virtual-machine:~/lab2$ gedit 29.c
deepa@deepa-virtual-machine:~/lab2$ gcc 29.c -o 29
deepa@deepa-virtual-machine:~/lab2$ ./29
Current scheduling policy: SCHED_OTHER
Current priority: 0
sched_setscheduler: Operation not permitted
sched_setscheduler: Operation not permitted*/

