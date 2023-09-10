/*
============================================================================
Name :18b.c
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

    
    fd = open("student1.txt",O_RDWR|O_CREAT);
 

    
    for (int i = 0; i < 3; i++) {
        printf("Enter data for record %d: \n", i + 1);
        scanf("%d", &records[i].marks);
        write(fd,&records[i].marks,sizeof(int));
    }
	int recordno;
	printf("\nEnter 1/2/3 student marks to read\n");
	scanf("%d",&recordno);
    struct flock lock;
    lock.l_type = F_RDLCK; 
    lock.l_whence = SEEK_SET;
    lock.l_start = (recordno-1) * sizeof(struct student);
    lock.l_len = sizeof(struct student);

    fcntl(fd, F_SETLKW, &lock); 
   

    
    lseek(fd, (recordno-1)* sizeof(struct student), SEEK_SET);
    read(fd, &records[recordno-1], sizeof(struct student));
    printf("Reading marks =%d\n",records[recordno-1].marks);

    
    lock.l_type = F_UNLCK;
    lock.l_start = (recordno-1) * sizeof(struct student);
    lock.l_len = sizeof(struct student);

    fcntl(fd, F_SETLK, &lock); 


    
    

    
    
    close(fd);

    return 0;
}


/*Sample Output:
deepa@deepa-virtual-machine:~/Handonlist1$ gcc lab18b.c -o lab18b
deepa@deepa-virtual-machine:~/Handonlist1$ ./lab18b
Enter data for record 1: 
11
Enter data for record 2: 
22
Enter data for record 3: 
33

Enter 1/2/3 student marks to read
1
Reading marks =11
deepa@deepa-virtual-machine:~/Handonlist1$ ./lab18b
Enter data for record 1: 
44
Enter data for record 2: 
55
Enter data for record 3: 
66

Enter 1/2/3 student marks to read
3
Reading marks =66*/
