/*
============================================================================
Name :17_1.c
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

printf("\nEnter ticket no:\n");
scanf("%d",&t.ticketno);
fd = open("ticketreservation.txt",O_RDWR); 
write(fd, &t,sizeof(t)); 
close(fd);
 fd = open("ticketreservation.txt",O_RDONLY); 
 read(fd, &t, sizeof(t));
printf("\nTicket no stored is: %d\n",t.ticketno);
 close(fd);
return 0;
}

/*Sample output:
deepa@deepa-virtual-machine:~/lab2$ gcc 17_1.c -o 17_1
deepa@deepa-virtual-machine:~/lab2$ ./17_1

Enter ticket no:
16

Ticket no stored is: 16*/

