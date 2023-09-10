/*
============================================================================
Name : 27a.c
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
    
    char *command = "ls";
    char *arg1 = "-Rl";

    // Use execl to execute the command
    if (execl("/bin/ls", command, arg1, NULL) == -1) {
        perror("execl");
        
    }
	printf("Hello\n");
    return 0;
}

/*Sample Output:
deepa@deepa-virtual-machine:~/lab2$ gedit 27a.c
deepa@deepa-virtual-machine:~/lab2$ gcc 27a.c -o 27a
deepa@deepa-virtual-machine:~/lab2$ ./27a
.:
total 628
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
-rwxrwxr-x 1 deepa deepa 16040 Sep  9 19:15 27a
-rw-rw-r-- 1 deepa deepa   347 Sep  9 19:14 27a.c
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
-rw-rw-r-- 1 deepa deepa  1407 Sep  8 11:30 lab10.c
-rwxrwxr-x 1 deepa deepa 16248 Sep  8 11:28 lab11
-rw-rw-r-- 1 deepa deepa  1515 Sep  8 11:32 lab11.c
-rwxrwxr-x 1 deepa deepa 16128 Sep  8 11:37 lab12
-rw-rw-r-- 1 deepa deepa  1339 Sep  8 11:41 lab12.c
-rwxrwxr-x 1 deepa deepa 16096 Sep  8 12:05 lab13
-rw-rw-r-- 1 deepa deepa  1341 Sep  8 12:05 lab13.c
-rwxrwxr-x 1 deepa deepa 16136 Sep  9 18:42 lab14
-rw-rw-r-- 1 deepa deepa  1662 Sep  9 18:45 lab14.c
-rwxrwxr-x 1 deepa deepa 16008 Sep  9 18:46 lab15
-rw-rw-r-- 1 deepa deepa  3151 Sep  9 18:52 lab15.c
-rw-rw-r-- 1 deepa deepa   930 Aug 29 16:50 lab16.c
-rwxrwxr-x 1 deepa deepa 16128 Sep  8 09:34 lab3
-rw-rw-r-- 1 deepa deepa   839 Sep  8 09:35 lab3.c
-rwxrwxr-x 1 deepa deepa 16088 Sep  8 09:43 lab4
-rw-rw-r-- 1 deepa deepa   869 Sep  9 18:21 lab4.c
-rwxrwxr-x 1 deepa deepa 15960 Sep  9 18:22 lab5
-rw-rw-r-- 1 deepa deepa   637 Sep  9 18:22 lab5.c
-rwxrwxr-x 1 deepa deepa 16096 Sep  8 10:16 lab6
-rw-rw-r-- 1 deepa deepa   785 Sep  5 11:58 lab6.c
-rwxrwxr-x 1 deepa deepa 16216 Sep  8 10:31 lab7
-rw-rw-r-- 1 deepa deepa  1173 Sep  8 10:31 lab7.c
-rwxrwxr-x 1 deepa deepa 16136 Sep  8 10:37 lab8
-rw-rw-r-- 1 deepa deepa  1100 Sep  8 10:37 lab8.c
-rwxrwxr-x 1 deepa deepa 16056 Sep  9 18:30 lab9
-rw-rw-r-- 1 deepa deepa  1561 Sep  9 18:30 lab9.c
-rw-rw-r-- 1 deepa deepa    21 Sep  9 11:24 lock.txt
-rw-r--r-- 1 deepa deepa    39 Sep  5 10:18 output22.txt
-rw-rw-r-- 1 deepa deepa    24 Sep  9 13:37 record1.txt
-rw-rw-r-- 1 deepa deepa    24 Sep  9 13:36 record.txt
-r-xrws--T 1 deepa deepa     0 Sep  8 10:20 test1.txt
---------- 1 deepa deepa     0 Sep  8 10:20 test2.txt*/

