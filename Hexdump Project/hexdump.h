/**************************************************************
Megan Chua & Ko Takahashi 
cssc0453 & cssc0452
CS 530 Spring 2019
Assignment #1 Hexadecimal File Dump Program
hexdump.h

This file is the Header File. This defines the parametes that 
each function takes in. 

Our hexdump function takes in (char* str) a string of characters 
which is our input string,(void *addr) a pointer that points to 
the address that our string starts at and (int len) which stores 
the length of our string. 

Our bindump function takes in (FILE *ptr_file) a pointer that 
points to the beginning of our input file.  
***************************************************************/
#ifndef HEADER_FILE
#define HEADER_FILE

void hexdump (char* str, void* addr, int len);
void bindump (FILE *ptr_file);

#endif
