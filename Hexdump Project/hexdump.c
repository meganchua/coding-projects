/**************************************************************
Megan Chua & Ko Takahashi 
cssc0453 & cssc0452
CS 530 Spring 2019
Assignment #1 Hexadecimal File Dump Program
hexdump.c

This program takes in a file and performs a hexdump on the file.
User has the choice of printing the file in hexadecimal format
or binary format with the use of "xbd" vs "xbd -b".  
***************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hexdump.h"
#define SIZE 255

/***************************************************************
hexdump: Utilizes pointers to change the values at each address
to hexadecimal, then prints out the ASCII characters. Each 'if 
statement' deals with the spacing and output of each character. 
****************************************************************/
void hexdump (char *str, void *addr, int len)
{
    int i;
    unsigned char *ptr = (unsigned char*)addr; //ptr points to contents at address
    unsigned char buff[17];

    if (str != NULL) //prints out the input string such as "buff"
    {
        printf("%s:\n", str);
    }

    for (i=0; i < len; i++) //prints out the address of memory
    {
        if ((i%16) == 0) //we want to print out every 16 bytes
        {
            if(i != 0)
            {
                printf (" %s\n", buff);
            }
        
            if (ptr[i] == 0x00) exit(0);

            printf (" %07x ", i); //print address
        }

        //prints out the contents of our text file into hex
        //%02x converts to a two digit hexadecimal value
        printf ("%02x", ptr[i]); 
        if((i%2) == 1) //deals with the spacing between each hexadecimal grouping
        {
            printf(" ");
        }
        //ensures that we only convert letters and numbers in the ACII table
        if((ptr[i] < 0x20) || (ptr[i] > 0x7e)) 
        {
            buff[i%16] = '.';
        }

        else
        {
            buff[i%16] = ptr[i];
        }

        buff[(i%16) + 1] = '\0';
    }
    //prints out the contents of the input file in human readable form
    //prints a space and the input buffer every 16 bytes
    while ((i%16) !=0)
    {
        printf(" ");
        i++;
    }

    printf (" %s\n", buff); 

}

/***************************************************************
bindump: Takes a file pointer as the input. Utilizes bitwise
operators to convert the text file into a binary output. Loops 
through until the end of the file.
****************************************************************/
void bindump (FILE *ptr_file)
{
    char buff[SIZE]; //holds the char values in the input text file
    int p = 0;      //a pointer for the buff array of chars
    int n, c, k;    //n holds int value of the char input, c is a counter, k holds a bitwise op
    int count = 0;  //counter for the spacing of each binary group
    char input;     //starting char value in the input text file

    while (!feof(ptr_file)) 
    {   
        input = fgetc(ptr_file); 
        //every 6 octets, print out the user input in human readable form
        //print out the address at the beginning of the 6 bytes
        if (count%6 == 0 || feof(ptr_file))
        {
            //each octet is 8 bytes long and count%6 spaces after 6 octets
            //+5 adds a space for every odd amount of chars
            printf("%*s", 8 * (count%6) + 5, "");
            printf("%*s",(count%6), "");
            printf(" %s\n", buff);    
            printf("%08x: ", count);
            memset(buff, '\0', sizeof(buff) );
            p = 0;
        }
        //set n equal to the integer value of the input
        n = (int) input; 
        //uses a bitwise operand to convert to binary
        for (c = 7; c >= 0; c--)
        {
            k = n>>c;
            if (k&1)
            {
                printf("1");
            }
            else
            {
                printf ("0");
            }
        
         } 
        //increments all the counters and pointers
         buff[p] = n;
         count++;
         p++;   
         printf (" ");      
    }
}
/***************************************************************
main: Takes in a text file. Utilizes command line arguments to 
test which dump (hex or binary) to use. Calls hex or binary dump
functions depending on user input.
****************************************************************/
int main(int argc, char* argv[])
{
    char buff[SIZE];
    FILE *ptr_file;

    memset(buff, '\0', sizeof(buff));
    
    //checks for one command line argument 'xbd'
    if (argc == 2)
    {
        ptr_file = fopen(argv[1], "r");
        if(!ptr_file)
        {   
            printf ("FILE NOT FOUND\n");
            return 1;
        }
        for (;;)
        {
            unsigned char buff[SIZE];
            size_t n = fread(buff, 1, SIZE, ptr_file);
        
            if(n > 0) 
            {    
                hexdump("buff", &buff, sizeof (buff));
            }
        if (n < SIZE) break;
        }
        fclose(ptr_file);
    }

    //checks for 2 command line arguments and for the '-b' flag
    else if(argc == 3 && strcmp(argv[2], "-b"))
    {
        ptr_file = fopen(argv[2], "r");
        if(!ptr_file)
        {   
            printf ("FILE NOT FOUND\n");
            return 1;
        }
        bindump(ptr_file);
        printf("\n");
        fclose(ptr_file);
    }

    return 0;
}
