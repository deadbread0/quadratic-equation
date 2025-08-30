#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#include "tests.h"

void RunTests(const char *input_flag, const char *i)
{
    struct ParametersOfTheEquation mass[] = {
        {           1,            0,            0, 1,   0, NAN},
        {           0,            1,            0, 1,   0, NAN},
        {           0,            0,            1, 0, NAN, NAN},
        {           0,            0,            0, 0, NAN, NAN},
        {           1,            2,            1, 1,  -1, NAN},
        {    0.000001,     0.000002,     0.000001, 1,  -1, NAN},
        {           1,           -3,            2, 2,   1,   2},
        {           1,          -15,           26, 2,   2,  13},
        {0.0000000001, 0.0000000002, 0.0000000001, 1,  -1, NAN}
    };

    const int len = sizeof(mass) / sizeof(mass[0]);
    unsigned int count_right_answer = 0;

    for (int i = 0; i < len; i++)
        count_right_answer += OneTest(&mass[i]);
    if (count_right_answer == len)
        printf("ok, amount of right answers: %d\n", count_right_answer);

}

int OneTest(struct ParametersOfTheEquation *mass_i)
{
    struct ParametersOfTheEquation struct_ptr_tests = {NAN, NAN, NAN, 0, NAN, NAN};

    struct_ptr_tests.a = (mass_i->a);
    struct_ptr_tests.b = (mass_i->b);
    struct_ptr_tests.c = (mass_i->c);

    FindSolution(&struct_ptr_tests);
    if (!(ComparisonDouble(struct_ptr_tests.x1, (mass_i->x1)) == FIRST_EQUAL_TO_SECOND) && 
         (ComparisonDouble(struct_ptr_tests.x2, (mass_i->x2)) == FIRST_EQUAL_TO_SECOND))
    {
        printf("output of incorrect answer!!\n"
               "received answer: %.3g, %.3g\n"
               "expected response: %.3g, %.3g\n\n", struct_ptr_tests.x1, struct_ptr_tests.x2, (mass_i->x1), (mass_i->x2));
        return 0;
    }
    return 1;
}