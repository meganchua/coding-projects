#include <stdio.h>
#include <stdlib.h>
#include "prog1_2.h"
#include <string.h>


int main (int argc, char* argv[])
{
    char input[256]; //allocates memory for user input
    char *str1, *str2, *str3; //splits the str up into 3 parts for the space delimiter later on
    STACK* newSTACK = MakeStack(256); //creates new stack from the MakeStack function
    printf("Assignment #1-3, Megan Chua, meganchua@yahoo.com\n");

    if (argc != 2)
    {
        printf ("Error, please enter a single command line argument.\n");
        return 1;
    } //argc always starts with a value of one because of the program name, if user doesn't input a single command line argument, then print error

    int N = atoi(argv[1]); //N = user input, converts to user input to integer
    while (N > 0) 
    {
        N--;
        printf("> ");
        fgets(input, 256, stdin);
        str1 = strtok(input, " \n\t"); //splits the stdin, uses space delimiter
        str2 = strtok(NULL, " \n\t");
        str3 = strtok(NULL, " \n\t");
        if (strcmp("push",str1)==0 && str3 == NULL)
        {
            Push(newSTACK, atoi(str2));
            str1 = strtok(NULL, " \n\t");
        }// if user input is push and no string after, then push onto newstack
        
        else if (strcmp("pop",str1)==0 && str2 == NULL)
        {
            printf("%d\n",Pop(newSTACK));
        }// if user input is pop and no string after then pop off of newstack
    }
}
            
        
        
        

    

    

    
