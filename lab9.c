/*
============================================================================
Name : 9.c
Author : Deepanjali Ghosh
Description :Write a program to print the following information about a given file.
a. inode
b. number of hard links
c. uid
d. gid
e. size
f. block size
g. number of blocks
h. time of last access
i. time of last modification
j. time of last change
Date: 15 Aug, 2023.
============================================================================
*/








#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include <sys/sysmacros.h>
#include <time.h>
int main(){


   struct stat sf;
   stat("lab3.c", &sf);


 
  printf("\ninode number:%ld",sf.st_ino);
  printf("\nsize of the file:%ld",sf.st_size);
  printf("\ntotal number of hard link:%lu", sf.st_nlink);
  printf("\nuserid:%d", sf.st_uid);
  printf("\nblock size:%ld", sf.st_blksize);
  printf("\ngroup id:%d", sf.st_gid);
  printf("\ntotal number of blocks:%ld", sf.st_blocks);
  printf("\ntime of last access:%ld", sf.st_atime);
  printf("\ntime of recent modification:%ld", sf.st_mtime);
  printf("\ntime of last change:%ld\n",sf.st_ctime);
}


/*Sample Output:
deepa@deepa-virtual-machine:~/lab2$ gedit lab9.c
deepa@deepa-virtual-machine:~/lab2$ gcc lab9.c -o lab9
deepa@deepa-virtual-machine:~/lab2$ ./lab9

inode number:0
size of the file:1
total number of hard link:0
userid:0
block size:1
group id:0
total number of blocks:94188600135744
time of last access:140584333121628
time of recent modification:140723014723561
time of last change:1103823372288*/

