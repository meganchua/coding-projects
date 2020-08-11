#include <stdio.h>
#include <stdlib.h>
#include "prog1_2.h"


STACK *MakeStack (int initialCapacity)
{	
	STACK *newSTACK = (STACK *)malloc(sizeof(STACK)); //allocates memory for the stack
    newSTACK->capacity = initialCapacity;
    newSTACK->size = 0;
    newSTACK->data = malloc(sizeof(int)*initialCapacity);
    
    return newSTACK;
}

void Push(STACK *stackPtr, int data)
{
    //grow the stack if the index points at the same place as capacity and needs more memory
    if (stackPtr->size == stackPtr->capacity)
    {
        Grow(stackPtr);
    }
    stackPtr->data[stackPtr->size] = data;
    stackPtr->size++;
}

int Pop(STACK *stackPtr)
{
    if (stackPtr->size == 0) //checks if stack is empty
    {
        return -1;
    }
    stackPtr->size--;
    return stackPtr->data[stackPtr->size];

}

void Grow (STACK *stackPtr)
{
    //create a temporary stack to allocate double the memory
    int newCapacity = stackPtr->capacity*2;
    stackPtr->data = realloc(stackPtr->data, newCapacity * sizeof(int));
    stackPtr->capacity = newCapacity;
    
}
