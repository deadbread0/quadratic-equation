#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#include "file.h"
void Output(struct ParametersOfTheEquation *struct_ptr)
{
    assert(struct_ptr != nullptr);

    switch(struct_ptr->amount_of_solutions)
    {
        case INF:  printf("It's really hard...\n there are infinitely many roots\n"); break;
        case ONE:  printf("x = %.3g\n", struct_ptr->x1); break;
        case TWO:  printf("2 roots:\n x = %.3g\n x = %.3g\n", struct_ptr->x1, struct_ptr->x2); break;
        case ZERO: printf("no roots\n"); break;
        default:   printf("some kind of error, try again!!\n");
    }
}
