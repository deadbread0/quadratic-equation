#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <cstring>

#include "flags.h"

int CompareFlagsAndRunFunction(const char *input_file, const char *input_flag, const char *output_file, const struct ParametersOfFlags *struct_flags)
{
    //const char *input_flag1 = (const char*) input_flag; 
    const char *beggining_of_flag = "--";
    const char *beggining_of_flg = "-";
    for (int i = 0; i < len; i++)
    {
        if ((strncmp(input_flag, struct_flags[i].flag, strlen(beggining_of_flag)) == 0) && 
            (strncmp(input_flag, struct_flags[i].flag, MAX_LEN_OF_WORD) == 0))
            return RunFunc(input_file, output_file, struct_flags, i);
        else if ((strncmp(input_flag, struct_flags[i].flg, strlen(beggining_of_flag)) == 0) && 
                 (strncmp(input_flag, struct_flags[i].flg, MAX_LEN_OF_WORD)) == 0)
            return RunFunc(input_file, output_file, struct_flags, i);
    }
    return 1;
}

void Help(const char *input_flag, const char *output_file)
{
    printf("available flags:\n");
    for (int i = 0; i < len; i++) {
        printf("%s (%s) - %s\n", struct_flags[i].flag, struct_flags[i].flg, struct_flags[i].instruction);
    }
            
}

void SolveEquationFromFile(const char *input_file, const char *output_file)
{
    //const char* file = (const char*) input_file;//
    FILE *fp = nullptr;
    //const char *input_file1 = (const char*)input_file;
    if ((fp = fopen(input_file, "r")) == nullptr)
    {
        printf("enter file\n");
        /*char *filee;
        CopyBufferInput(filee);
        if ((fp = fopen(filee, "r")) == nullptr)
            printf("file was not entered((\n");*/
    }
    else
    {
        bool user_doesnt_want_to_leave = true;
        int count_inputnum = 0;
        const int COUNT_ABC = 3;
        struct ParametersOfTheEquation struct_ptr_file = {NAN, NAN, NAN, 0, NAN, NAN};

        count_inputnum = ReadsCoefficientsFromFile(&struct_ptr_file, fp);

        while (count_inputnum == COUNT_ABC)
        {
            FindSolution(&struct_ptr_file);
            if (*output_file == NULL)
            {
                Output(&struct_ptr_file);
            }
            else
            {
                //const char *output_file1 = (const char*) output_file;
                OutputInFile(&struct_ptr_file, output_file);
            }
            count_inputnum = ReadsCoefficientsFromFile(&struct_ptr_file, fp);
        }
    }
}

int ReadsCoefficientsFromFile(struct ParametersOfTheEquation *struct_ptr_file, FILE *fp)
{
    double a = 0, b = 0, c = 0;
    int count_inputnum = fscanf(fp, "%lf %lf %lf", &a, &b, &c);
    struct_ptr_file->a = a;
    struct_ptr_file->b = b;
    struct_ptr_file->c = c;
    return count_inputnum;
}

void Solver(const char *input_file, const char *output_file)
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

void OutputInFile(struct ParametersOfTheEquation *struct_ptr_file, const char *output_file)
{
    FILE *fp = nullptr;
    fp = fopen(output_file, "a");
    fprintf(fp, "Solution for %lgx*x + %lgx +%lg = 0:\n", struct_ptr_file->a, struct_ptr_file->b, struct_ptr_file->c);
    switch(struct_ptr_file->amount_of_solutions)
    {
        case INF:  fprintf(fp, "It's really hard...\n there are infinitely many roots\n"); break;
        case ONE:  fprintf(fp, "x = %.3g\n", struct_ptr_file->x1); break;
        case TWO:  fprintf(fp, "2 roots:\n x = %.3g\n x = %.3g\n", struct_ptr_file->x1, struct_ptr_file->x2); break;
        case ZERO: fprintf(fp, "no roots\n"); break;
        default:   fprintf(fp, "some kind of error, try again!!\n");
    }
}

int RunFunc(const char *input_file, const char *output_file, const struct ParametersOfFlags *struct_flags, int i)
{
    void (*pt)(const char*, const char*);
    pt = struct_flags[i].ptr;
    const char *input_file1 = (input_file == nullptr) ? "" : input_file;
    const char *output_file1 = (output_file == nullptr) ? "" : output_file;
    pt(input_file1, output_file1);
    return 0;
}

void Joker(const char*, const char*)
{
    printf("\ntop jokes in the humble opinion of Kira Vostrikova\n\n"
            "1. A bear was walking through the forest and saw a stone with an inscription on it: if you go left, you'll burn in a car,\n if you go right, you'll burn in a car, if you go straight, you'll burn in a car. The bear went back and saw that the car \nwas on fire. He got into it and burned.\n\n"
            "2. Man:\n"
            "- Dear sir, good afternoon. How much wool do your sheep produce per year?\n"
            "- What kind: black or white?\n"
            "- Black.\n"
            "- 2 kilograms.\n"
            "- And white?\n"
            "- Also 2.\n"
            "The man was surprised and thought: let me ask you something else...\n"
            "- Dear sir, how much feed do your sheep eat per day?\n"
            "- What kind: black or white?\n"
            "- White.\n"
            "- A kilogram.\n"
            "- And black?\n"
            "- Also a kilogram.\n"
            "The man was confused:\n"
            "- Dear sir, why do you keep asking what kind of sheep, although the results are the same?\n"
            "- Well, the black sheep are mine!\n"
            "- And the white ones?\n"
            "- White? Also mine.\n\n"
            "3. A man bought a hat and it fit him perfectly (kupil muzhik shlyapu, a ona yemu kak raz)\n\n"
            "4. Me: kilogram\n"
            "ogram: no pls don't do it\n"
            "Pls: i was never going to\n"
            "i: it's true\n"
            "true: yogurt\n"
            "gurt: you\n");
}
