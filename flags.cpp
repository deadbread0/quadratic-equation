#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#include "file.h"
#include "fun.h"


int UseFlags(const char *input_file, const char *input_flag, const struct ParametersOfFlags *struct_flags, int len)
{
    for (int i = 0; i < len; i++)
    {
        if ((strncmp(input_flag, struct_flags[i].flag, MAX_LEN_OF_WORD) == 0) || (strncmp(input_flag, struct_flags[i].flg, MAX_LEN_OF_WORD) == 0))
        {
            void (*pt)(const char *);
            pt = struct_flags[i].ptr;
            pt(input_file);
            return 0;
        }
    }
    return 1;
}

void Help(const char *input_flag)
{
    printf("available flags:\n");
    for (int i = 0; i < 4; i++) {
        printf("%s (%s) - %s\n", struct_flags[i].flag, struct_flags[i].flg, struct_flags[i].instruction);
    }
            
}

void ReadFile(const char *input_file)
{
    FILE *fp = nullptr;
    if ((fp = fopen(input_file, "r")) == nullptr)
        printf("the file did not open\n");
    else
    {
        bool user_doesnt_want_to_leave = true;
        int count_inputnum = 0;
        const int COUNT_ABC = 3;
        struct ParametersOfTheEquation struct_ptr_file = {NAN, NAN, NAN, 0, NAN, NAN};

        count_inputnum = InputFile(&struct_ptr_file, fp);

        while (count_inputnum == COUNT_ABC)
        {
            FindSolution(&struct_ptr_file);
            printf("Solution for %lgx*x + %lgx +%lg = 0:\n", struct_ptr_file.a, struct_ptr_file.b, struct_ptr_file.c);
            Output(&struct_ptr_file);
            count_inputnum = InputFile(&struct_ptr_file, fp);
        }
        printf("end of file\n");
    }
}

int InputFile(struct ParametersOfTheEquation *struct_ptr_file, FILE *fp)
{
    double a = 0, b = 0, c = 0;
    int count_inputnum = fscanf(fp, "%lf %lf %lf", &a, &b, &c);
    struct_ptr_file->a = a;
    struct_ptr_file->b = b;
    struct_ptr_file->c = c;
    return count_inputnum;
}


void Solver(const char *input_file)
{
    struct ParametersOfTheEquation struct_ptr = {NAN, NAN, NAN, 0, NAN, NAN};
    bool user_doesnt_want_to_leave = true;
    int count_inputnum = 0;
    const int COUNT_ABC = 3;

    while (user_doesnt_want_to_leave)
    {
        count_inputnum = Input(&struct_ptr);

        while (count_inputnum == COUNT_ABC)
        {
            FindSolution(&struct_ptr);
            Output(&struct_ptr);
            count_inputnum = Input(&struct_ptr);
        }
        user_doesnt_want_to_leave = GetAnswerAboutTheExit();
    }
}