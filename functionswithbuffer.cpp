#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#include "functionswithbuffer.h"

void CleanBuffer()
{
    while (getchar() != '\n') 
        continue; 
}


void CopyBufferInput(char *choice)
{
    fgets(choice, MAX_LEN_OF_WORD, stdin);
    for (int i = 0; i < MAX_LEN_OF_WORD; i++)
    {
        if (choice[i] == '\n')
            choice[i] = '\0';
        else
            choice[i] = tolower(choice[i]);
        
    }
}