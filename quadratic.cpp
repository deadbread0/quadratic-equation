//решает квадратные уравнения с точностью до 3-го знака после запятой
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#include "file.h"

const char *TESTFLAG = "--test";//h
const char *HELPFLAG = "--help";
const char *FILEFLAG = "--file";
const char *SOLVEFLAG = "--solve";
const char *TESTFLG = "-t"; 
const char *HELPFLG = "-h";
const char *FILEFLG = "-f";
const char *SOLVEFLG = "-s";
const char *TESTINSTR = "a flag for testing the program. the program will output errors if there are any.";
const char *HELPINSTR = "the flag will show all flags and their purpose.";
const char *FILEINSTR = "flag for inputting values from a file.";
const char *SOLVEINSTR = "flag for solving quadratic equations";


int main(const int argc, const char *argv[])
{


    void (*ptr_run_tests)(const char*);
    ptr_run_tests = RunTests;
    void (*ptr_help)(const char*);
    ptr_help = Help;
    void (*ptr_file)(const char*);
    ptr_file = ReadFile;
    void (*ptr_solver)(const char*);
    ptr_solver = Solver;

    struct ParametersOfFlags struct_flags[] = {{TESTFLAG, TESTFLG, ptr_run_tests}, //long_flag_name, short_flag_name
                                               {HELPFLAG, HELPFLG, ptr_help},  
                                               {FILEFLAG, FILEFLG, ptr_file},
                                                {SOLVEFLAG, SOLVEFLG, ptr_solver}};

    const char *input_flag = argv[1];
    const char *input_file = argv[2];
    int len = sizeof(struct_flags) / sizeof(struct_flags[0]);

    for (int i = 0; i < len; i++)//внутрь ф
    {
        int res = UseFlags(input_file, input_flag, &struct_flags[i]);
        if ((res == 0) && (i!=3))
            return 0;

    }


    return 0;
}
int UseFlags(const char *input_file, const char *input_flag, struct ParametersOfFlags *struct_flags)
{
    if ((strncmp(input_flag, struct_flags->flag, MAX_LEN_OF_WORD) == 0) || (strncmp(input_flag, struct_flags->flg, MAX_LEN_OF_WORD) == 0))
    {
        void (*pt)(const char *);
        pt = struct_flags->ptr;
        pt(input_file);
        return 0;
    }
    else
        return 1;
}

void Help(const char *input_flag)
{
    printf("available flags:\n"//for
            "%s (%s) - %s\n"
            "%s (%s) - %s\n"
            "%s (%s) - %s\n"
            "%s (%s) - %s\n", TESTFLAG, TESTFLG, TESTINSTR, HELPFLAG, HELPFLG, HELPINSTR, FILEFLAG, FILEFLG, FILEINSTR, SOLVEFLAG, SOLVEFLG, SOLVEINSTR);
}

void ReadFile(const char *input_file)
{
    FILE *fp = nullptr;
    if ((fp = fopen(input_file, "r")) == nullptr)
        printf("the file did not open\n");//nameoffile
    else
    {
        bool user_doesnt_want_to_leave = true;
        int count_inputnum = 0;
        const int COUNT_ABC = 3;
        struct ParametersOfTheEquation struct_ptr_file = {NAN, NAN, NAN, 0, NAN, NAN};

        count_inputnum = InputFile(&struct_ptr_file, fp);

        while (count_inputnum == COUNT_ABC)
        {
            FindSolution(&struct_ptr_file);//
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






