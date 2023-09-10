/*
============================================================================
Name :14.c
Author : Deepanjali Ghosh
Description :Write a program to find the type of a file.
a. Input should be taken from command line.
b. program should be able to identify any type of a file
Date: 25 Aug, 2023.
============================================================================
*/







#include<sys/types.h>
#include<sys/stat.h>
#include<sys/select.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>

int main(int argc, char *argv[]) {
      if(argc !=2){
        printf("not enough argument");
        return 1;
      }
      
      struct stat f;
      if(stat(argv[1], &f)==-1){
        perror("Error");
        return 1;
      }

  
      if (S_ISREG(f.st_mode)) {
          printf("Regular file\n");
      } 
      else if (S_ISDIR(f.st_mode)) {
          printf("Directory\n");
      }
      else if (S_ISLNK(f.st_mode)) {
          printf("Symbolic link\n");
      } 
      else if (S_ISFIFO(f.st_mode)) {
          printf("FIFO\n");
      } 
      else if (S_ISCHR(f.st_mode)) {
          printf("Character file\n");
      } 
      else if (S_ISBLK(f.st_mode)) {
          printf("Block file\n");
      } 
      else if (S_ISSOCK(f.st_mode)) {
          printf("Socket\n");
      } 
      else {
          printf("Unknown file type\n");
      }
  
} 

 /*Sample output 
deepa@deepa-virtual-machine:~/lab2$ gcc lab14.c -o lab14
deepa@deepa-virtual-machine:~/lab2$ ./lab14 lab13
Regular file*/
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
