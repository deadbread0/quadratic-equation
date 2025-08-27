#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#include "file.h"
#include "fun.h"

int Input(struct ParametersOfTheEquation *struct_ptr)
{
    assert(struct_ptr != nullptr);
    while (true)
    {
        double a = 0, b = 0, c = 0;

        printf("Enter the coefficients a, b, c for the quadratic equation of the form ax^2 + bx + c = 0 separated by spaces.\n"
               "To finish the program, enter any letter (for example, q)\n");

        int count_abc = scanf("%lf%lf%lf", &a, &b, &c);

        if (InputValidate() == 0)
            return 0;

        struct_ptr->a = a;
        struct_ptr->b = b;
        struct_ptr->c = c;
        return count_abc;
    }
}

bool GetAnswerAboutTheExit()
{
    char choice[MAX_LEN_OF_WORD] = "";
    const char *NEGATIVE_ANSWER = "no";
    const char *POSITIVE_ANSWER = "yes";
    printf("Are you sure you want to exit the program? (yes/no)\n");
    CleanBuffer();
    CopyBufferInput(choice);

    while(true)
    {
        int negative = strncmp(choice, NEGATIVE_ANSWER, MAX_LEN_OF_WORD);
        int positive = strncmp(choice, POSITIVE_ANSWER, MAX_LEN_OF_WORD);

        if (negative == 0)
            return true;
        else if (positive == 0)
            return false;
        else
        {
            printf("enter no or yes\n");
            CopyBufferInput(choice);
            continue;
        }
    }
}

int InputValidate()
{
    char ch = 0;
    while (true)
    {
        if ((ch = getchar()) == '\n')
            break;
        else if (isspace(ch))
            continue;
        else
            return 0;
    }
    return 1;
}

