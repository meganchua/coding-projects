#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void)
{
   char *line = malloc(1);
   printf("Assignment #1-1, Megan Chua, meganchua@yahoo.com\n");
   printf("What is your name?\n");
   gets (line);
   printf ("Hello %s!\n", line);

}
