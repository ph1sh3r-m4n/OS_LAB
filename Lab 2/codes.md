```bash
student@MIT-ICT-LAB8-7:~/Suniket_230953372/LAB_2$ cat exercise1
student@MIT-ICT-LAB8-7:~/230953372/LAB_2$ cat learn_grep
bunch of words
aaaa
bbbb
cccc
dddd

student@MIT-ICT-LAB8-7:~/230953372/LAB_2$ cat learn_grep | grep 'aaaa'
aaaa
student@MIT-ICT-LAB8-7:~/230953372/LAB_2$ cat learn_sort
cucumber
banana
watermelon
apple
papaya
student@MIT-ICT-LAB8-7:~/230953372/LAB_2$ sort learn_sort
apple
banana
cucumber
papaya
watermelon

student@MIT-ICT-LAB8-7:~/230953372/LAB_2$ echo this is top tier > file4
student@MIT-ICT-LAB8-7:~/230953372/LAB_2$ cat file4
this is top tier
student@MIT-ICT-LAB8-7:~/230953372/LAB_2$ sed -e 's/is/was/g' file4
thwas was top tier


student@MIT-ICT-LAB8-7:~/230953372/LAB_2$ nano exercise1
student@MIT-ICT-LAB8-7:~/230953372/LAB_2$ cat file1
12345678
student@MIT-ICT-LAB8-7:~/230953372/LAB_2$ wc file1
1 1 9 file1
student@MIT-ICT-LAB8-7:~/230953372/LAB_2$ cut -c 1-3 file1
123

student@MIT-ICT-LAB8-7:~/230953372/LAB_2$ cat learn_sort | tr "[a-z]" "[A-Z]"
CUCUMBER
BANANA
WATERMELON
APPLE
PAPAYA

ps -aux
student     4103  0.0  0.0   8228   516 pts/0    T    14:46   0:00 cat
student     4104  0.0  0.0  11684  3496 pts/0    R+   14:46   0:00 ps -aux
student@MIT-ICT-LAB8-7:~/230953372/LAB_2$ kill 4103
The process has been removed!

student@MIT-ICT-LAB8-7:~/230953372/LAB_2$ nano run.sh
student@MIT-ICT-LAB8-7:~/230953372/LAB_2$ ls -l
total 24
-rw-rw-r-- 1 student student 965 Jan 14 14:47 exercise1
-rw-rw-r-- 1 student student   9 Jan 14 14:23 file1
-rw-rw-r-- 1 student student   4 Jan 14 14:46 file2
-rw-rw-r-- 1 student student  36 Jan 14 14:14 learn_grep
-rw-rw-r-- 1 student student  40 Jan 14 14:36 learn_sort
-rw-rw-r-- 1 student student  81 Jan 14 14:48 run.sh
student@MIT-ICT-LAB8-7:~/230953372/LAB_2$ chmod +x run.sh
student@MIT-ICT-LAB8-7:~/230953372/LAB_2$ ./run.sh
This is a test to show the working of shell scripts and demonstrate chmod

student@MIT-ICT-LAB8-7:~/230953372/LAB_2$ bc
bc 1.07.1
Copyright 1991-1994, 1997, 1998, 2000, 2004, 2006, 2008, 2012-2017 Free Software Foundation, Inc.
This is free software with ABSOLUTELY NO WARRANTY.
For details type `warranty'. 
40*40
1600
35*43/21
71

student@MIT-ICT-LAB8-7:~/Suniket_230953372/LAB_2$ cat exercise2
2. Write grep commands to do the following activities:
• To select the lines from a file that have exactly two characters.
• To select the lines from a file that start with the upper case letter.
• To select the lines from a file that end with a period.
• To select the lines in a file that has one or more blank spaces.
• To select the lines in a file and direct them to another file which has digits as
one of the characters in that line.


1. student@MIT-ICT-LAB8-7:~/230953372/LAB_2$ grep -iE ^[a-z][a-z]$ file4
hi

2.student@MIT-ICT-LAB8-7:~/230953372/LAB_2$ grep -E ^[A-Z] file4
This is great
Hello Sir you are awarded

3.student@MIT-ICT-LAB8-7:~/230953372/LAB_2$ grep -E [.] file4
period.

4.student@MIT-ICT-LAB8-7:~/230953372/LAB_2$ grep -E " " file4
This is great
Hello Sir you are awarded

5.student@MIT-ICT-LAB8-7:~/230953372/LAB_2$ grep -E [0-9] file5 | cat file4 > file5
student@MIT-ICT-LAB8-7:~/230953372/LAB_2$ cat file5
hi
This is great
period.
Hello Sir you are awarded
    
student@MIT-ICT-LAB8-7:~/Suniket_230953372/LAB_2$ cat exercise3
cat: exercise3: No such file or directory
student@MIT-ICT-LAB8-7:~/Suniket_230953372/LAB_2$ cat exercise4
student@MIT-ICT-LAB8-7:~/230953372/LAB_2$ ls *[0-9]
exercise1  exercise2  exercise5  file1  file2  file3  file4  file5
student@MIT-ICT-LAB8-7:~/230953372/LAB_2$ wc *[0-9]
  73  237 2076 exercise1
  30  153 1002 exercise2
   3   11  122 exercise5
   1    1    9 file1
   1    1   11 file2
   2    3   34 file3
   4   10   51 file4
   4   10   51 file5
 118  426 3356 total
student@MIT-ICT-LAB8-7:~/Suniket_230953372/LAB_2$ cat exercise5
student@MIT-ICT-LAB8-7:~/230953372/LAB_2$ pkill -9 wc
[4]-  Killed                  wc -
[5]+  Killed                  wc
student@MIT-ICT-LAB8-7:~/Suniket_230953372/LAB_2$ Executed a bunch of commands like 
Executed: command not found
student@MIT-ICT-LAB8-7:~/Suniket_230953372/LAB_2$ cat - display file content
d. ls [!aeiou]*tain any of the vowels as the start letter.

```
