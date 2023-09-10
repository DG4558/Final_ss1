/*
============================================================================
Name : 27b.c
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
    
    if (execlp("ls", "ls", "-Rl", NULL) == -1) {
        perror("execlp");
        
    }
	printf("\nHello");
    return 0;
}
/*Sample Output:
deepa@deepa-virtual-machine:~/lab2$ gcc 27b.c -o 27b
deepa@deepa-virtual-machine:~/lab2$ ./27b
.:
total 652
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
-rw-rw-r-- 1 deepa deepa  4353 Sep  9 19:17 27a.c
-rwxrwxr-x 1 deepa deepa 16048 Sep  9 19:22 27b
-rw-rw-r-- 1 deepa deepa   205 Sep  9 19:22 27b.c
-rwxrwxr-x 1 deepa deepa 15960 Sep  8 09:52 a.out
-rw-rw-r-- 1 deepa deepa   379 Sep  8 11:28 dup2.txt
-rw-rw-r-- 1 deepa deepa    36 Sep  8 11:28 dup3.txt
-rw-rw-r-- 1 deepa deepa   396 Sep  8 11:28 dup.txt
---xrws--T 1 deepa deepa     0 Sep  8 09:52 f1
---------- 1 deepa deepa     0 Sep  8 09:52 f2
---------- 1 deepa deepa     0 Sep  8 09:52 f3
---------- 1 deepa deepa     0 Sep  8 09:52 f4
---------- 1 deepa deepa     0 Sep  8 09:52 f5
-rw-rw-r-- 1 deepa deepa    36 Sep  8 11:28 fcntl.txt
---srws--T 1 deepa deepa     0 Sep  8 09:59 ff1.txt
---------- 1 deepa deepa     0 Sep  8 09:59 ff2.txt
-rw-rw-r-- 1 deepa deepa    19 Sep  5 12:02 file1.txt
---------- 1 deepa deepa    19 Sep  5 12:02 file2.txt
-rwxrwxr-x 1 deepa deepa 16176 Sep  8 11:08 lab10
-rw-rw-r-- 1 deepa deepa  1407 Sep  8 11:30 lab10.c*/

