#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#include "file.h"


int UseFlags(const char *input_flag, struct ParametersOfFlags *struct_flags)
{
    if ((strncmp(input_flag, struct_flags->flag, MAX_LEN_OF_WORD) == 0) || (strncmp(input_flag, struct_flags->flg, MAX_LEN_OF_WORD) == 0))
    {
        void (*pt)(void);
        pt = struct_flags->ptr;
        pt();
        return 0;
    }
    else
        return 1;
}

void Help()
{
    printf("help\n");
}

void ReadFile()
{
    printf("readfile\n");
}