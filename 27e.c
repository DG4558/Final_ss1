/*
============================================================================
Name : 27e.c
Author : Deepanjali Ghosh
Description :Write a program to execute ls -Rl by the following system calls
a. execl
b. execlp
c. execle
d. execv
e. execvp
Date: 6 Sept, 2023.
============================================================================
*/



#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    
    char *cmd = "ls";
    char *args[] = {"ls", "-Rl", NULL};

    
    if (execvp(cmd, args) == -1) {
        perror("execvp");
        
    }
	printf("\nHello");
    return 0;
}


/*Sample Output:
deepa@deepa-virtual-machine:~/lab2$ gcc 27e.c -o 27e
deepa@deepa-virtual-machine:~/lab2$ ./27e
.:
total 712
-rwxrwxr-x 1 deepa deepa 16304 Sep  9 11:23 16a
-rwxrwxr-x 1 deepa deepa 16312 Sep  9 11:23 16a2
-rw-rw-r-- 1 deepa deepa   774 Sep  9 11:22 16a2.c
-rw-rw-r-- 1 deepa deepa  1750 Sep  9 11:29 16a.c
-rwxrwxr-x 1 deepa deepa 16304 Sep  9 11:34 16b
-rw-rw-r-- 1 deepa deepa  1249 Sep  9 11:36 16b.c
-rwxrwxr-x 1 deepa deepa 16272 Sep  9 12:20 17_1
-rw-rw-r-- 1 deepa deepa  1190 Sep  9 12:27 17_1.c
-rwxrwxr-x 1 deepa deepa 16304 Sep  9 12:21 17_2
-rw-rw-r-- 1 deepa deepa  1594 Sep  9 12:27 17_2.c
-rwxrwxr-x 1 deepa deepa 16352 Sep  9 13:37 18a
-rw-rw-r-- 1 deepa deepa  1418 Sep  9 14:00 18a.c
-rwxrwxr-x 1 deepa deepa 16352 Sep  9 13:53 18b
-rw-rw-r-- 1 deepa deepa  1415 Sep  9 13:59 18b.c
-rw-rw-r-- 1 deepa deepa  2640 Sep  9 13:03 18.txt
-rwxrwxr-x 1 deepa deepa 16096 Sep  9 13:31 18txt
-rw-rw-r-- 1 deepa deepa   817 Sep  9 13:59 18txt.c
-rw-rw-r-- 1 deepa deepa  2640 Sep  9 13:06 19.txt
-rwxrwxr-x 1 deepa deepa 16088 Sep  5 10:04 21
-rw-rw-r-- 1 deepa deepa   880 Sep  5 10:03 21.c
-rwxrwxr-x 1 deepa deepa 16216 Sep  5 10:18 22
-rw-rw-r-- 1 deepa deepa  1150 Sep  5 10:18 22.c
-rwxrwxr-x 1 deepa deepa 16128 Sep  5 10:28 23
-rw-rw-r-- 1 deepa deepa  1010 Sep  5 10:28 23.c
-rwxrwxr-x 1 deepa deepa 16080 Sep  5 10:37 24
-rw-rw-r-- 1 deepa deepa  1022 Sep  5 10:37 24.c
-rwxrwxr-x 1 deepa deepa 16216 Sep  5 11:18 25
-rw-rw-r-- 1 deepa deepa  1589 Sep  5 11:21 25.c
-rwxrwxr-x 1 deepa deepa 16040 Sep  9 19:17 27a
-rw-rw-r-- 1 deepa deepa  4701 Sep  9 19:25 27a.c
-rwxrwxr-x 1 deepa deepa 16048 Sep  9 19:22 27b
-rw-rw-r-- 1 deepa deepa  3067 Sep  9 19:26 27b.c
-rwxrwxr-x 1 deepa deepa 16056 Sep  9 19:31 27c
-rw-rw-r-- 1 deepa deepa  2502 Sep  9 19:47 27c.c
-rwxrwxr-x 1 deepa deepa 16096 Sep  9 19:47 27d
-rw-rw-r-- 1 deepa deepa  2538 Sep  9 19:49 27d.c*/

