/*
============================================================================
Name :17_2.c
Author : Deepanjali Ghosh
Description : Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.
Date: 25 Aug, 2023.
============================================================================
*/






#include<sys/types.h>
#include<sys/stat.h>
#include<sys/select.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>

int main() {

struct flock lock; 
int fd; 


struct
{ 
int ticketno;
}t;


fd = open("ticketreservation.txt", O_RDWR);

lock.l_pid=getpid();
lock.l_type=F_WRLCK;
lock.l_start=0;
lock.l_len=0;
lock.l_whence=SEEK_SET;

printf("\nBefore entering into critical");
fcntl(fd, F_SETLKW, &lock);
printf("\nInside the critical section\n");

read(fd, &t, sizeof(t)); 
printf("\nCurrent ticket number read is: %d\n", t.ticketno); 
t.ticketno++;

printf("New ticket no is:%d\n",t.ticketno);

printf("\nPress enter to unlock\n"); 

getchar();

lock.l_type = F_UNLCK;
fcntl(fd, F_SETLK, &lock);
printf("\nExited critical section\n");

close(fd);
return 0;

}



/*Sample Output:
eepa@deepa-virtual-machine:~/lab2$ gcc 17_2.c -o 17_2
deepa@deepa-virtual-machine:~/lab2$ ./17_2

Before entering into critical
Inside the critical section

Current ticket number read is: 16
New ticket no is:17

Press enter to unlock


Exited critical section*/


