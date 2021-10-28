Simple shell
In this project we'll create a simple UNIX command interpreter in C programming language.

Table of Contents
Introduction

What is Shell
What is it for
Project Information

General requirements
Allowed functions
Documentation

Download
Compilation
Testing
Files
Show flowchart
Extra Information

Resources
Authors

Introduction
What is Shell
A shell is a command-line interpreter, it is the computer program that provides a user interface to access the services of the operating system. Depending on the type of interface they use, shells can be of various types, in this case, a shell program of the type sh (Bourne Shell) will be developed. Users typically interact with a shell using a terminal emulator that is used for entering data into and displaying or printing data from, a computer or a computing system.

What is it for
This consists of interpreting orders. It incorporates features such as process control, input/output redirection, law listing and reading, protection, communications, and a command language for writing batch programs or scripts. All Unix-type systems have at least one interpreter compatible with the Bourne shell. The Bourne shell program is found within the Unix file hierarchy at /bin/sh.

Project Information
General requirements
Allowed editors: vi, vim, emacs
All your files will be compiled on Ubuntu 14.04 LTS
Your C programs and functions will be compiled with gcc 4.8.4 using the flags -Wall -Werror -Wextra and -pedantic
Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
No more than 5 functions per file
All your header files should be include guarded
This shell should not have any memory leaks
Unless specified otherwise, your program must have the exact same output as sh (/bin/sh) as well as the exact same error output.
Allowed functions
access (man 2 access)
chdir (man 2 chdir)
close (man 2 close)
closedir (man 3 closedir)
execve (man 2 execve)
exit (man 3 exit)
_exit (man 2 _exit)
fflush (man 3 fflush)
fork (man 2 fork)
free (man 3 free)
getcwd (man 3 getcwd)
getline (man 3 getline)
isatty (man 3 isatty)
kill (man 2 kill)
malloc (man 3 malloc)
open (man 2 open)
opendir (man 3 opendir)
perror(man 3 perror)
read (man 2 read)
readdir (man 3 readdir)
signal (man 2 signal)
stat (__ xstat) (man 2 stat)
lstat (__ lxstat) (man 2 lstat)
fstat (__ fxstat) (man 2 fstat)
strtok (man 3 strtok)
wait (man 2 wait)
waitpid (man 2 waitpid)
wait3 (man 2 wait3)
wait4 (man 2 wait4)
write (man 2 write)
Documentation
Download
You can clone this repository this way: git clone https://github.com/nathsotomayor/simple_shell.git

Compilation
Your shell will be compiled this way:

gcc -Wall -Werror -Wextra -pedantic *.c -o hsh

Testing
Your shell should work like this in interactive mode:

$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
Also in non-interactive mode:

$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
Files
##	File	Description
1	README.md	Readme
2	man_1_simple_shell	Man page Simple Shell based in sh(1) - Linux man page
3	main.c	Entry point
4	holberton.h	Header file
5	interactive.c	It runs when it receives input through the non-interactive modes echo and cat, in addition to real-time execution.
6	non_interact.c	Error message when you receive parameters using the argc and argv arguments.
7	create_process.c	This function validates the existence of a file locally, and $PATH, if the file exists, creates a child process that validates all its error states. Using the stat() , fork() , execve() and waitpid() functions
8	validate_file.c	This function validates if a file is found in the paths of the system PATH by means of the stat system call.
9	_getenv.c	This function returns a specified environment variable.
10	_exit.c	This function return a value especific of exit.
11	printf_env.c	This function emulates the operation of the env function, printing the environment variables.
12	str_function.c	Auxiliary functions for handling character strings: strlen() , _strcat() , _strcpy() and _strdup() .
13	strcmp_function.c	Auxiliary functions for character string comparison: _strcmp() and _strncmp() .
14	_calloc.c	This function emulates the operation of the calloc() function. Allocate and zero-initialize array
Flowchar
Flowchar

Extra information
Resources
Read or watch:

The Magic Behind the Command ls -l
Thompson shell
Ken Thompson
man or help:

sh (Run sh as well)

