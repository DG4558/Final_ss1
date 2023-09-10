/*
============================================================================
Name :18a.c
Author : Deepanjali Ghosh
Description :Write a program to perform Record locking.
a. Implement write lock
b. Implement read lock
Create three records in a file. Whenever you access a particular record, first lock it then modify/access
Date: 25 Aug, 2023.
============================================================================
*/





#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>


struct student {
    int marks;
};

int main() {
    int fd;
    struct student records[3];

    
    fd = open("student.txt",O_RDWR|O_CREAT);
 

    
    for (int i = 0; i < 3; i++) {
        printf("Enter data for record %d: \n", i + 1);
        scanf("%d", &records[i].marks);
        write(fd,&records[i].marks,sizeof(int));
    }
	int recordno;
	printf("\nEnter 1/2/3 student marks to modify\n");
	scanf("%d",&recordno);
    struct flock lock;
    lock.l_type = F_WRLCK; 
    lock.l_whence = SEEK_SET;
    lock.l_start = (recordno-1) * sizeof(struct student);
    lock.l_len = sizeof(struct student);

    fcntl(fd, F_SETLKW, &lock); 
   

    
    lseek(fd, (recordno-1)* sizeof(struct student), SEEK_SET);
    read(fd, &records[recordno-1], sizeof(struct student));
    printf("Reading marks before modify=%d\n",records[recordno-1].marks);

    records[recordno-1].marks=50;
    write(fd, &records[recordno-1], sizeof(struct student));
    
    lock.l_type = F_UNLCK;
    lock.l_start = (recordno-1) * sizeof(struct student);
    lock.l_len = sizeof(struct student);

    fcntl(fd, F_SETLK, &lock); 
    
	lseek(fd, (recordno-1) * sizeof(struct student), SEEK_SET);
    read(fd, &records[recordno-1], sizeof(struct student));
    printf("Reading marks after modify=%d\n",records[recordno-1].marks);

    
    
    close(fd);

    return 0;
}

/*Sample Output 1:
deepa@deepa-virtual-machine:~/Handonlist1$ gcc lab18a.c -o lab18a
deepa@deepa-virtual-machine:~/Handonlist1$ ./lab18a
Enter data for record 1: 
35
Enter data for record 2: 
68
Enter data for record 3: 
79

Enter 1/2/3 student marks to modify
3
Reading marks before modify=79
Reading marks after modify=50



Sample Output 2:
deepa@deepa-virtual-machine:~/Handonlist1$ ./lab18a
Enter data for record 1: 
55
Enter data for record 2: 
67
Enter data for record 3: 
89

Enter 1/2/3 student marks to modify
2
Reading marks before modify=67
Reading data=50*/


