//решает квадратные уравнения с точностью до 3-го знака после запятой
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#include "file.h"

int main(const int argc, const char *argv[])
{
    struct ParametersOfTheEquation struct_ptr = {NAN, NAN, NAN, 0, NAN, NAN};

    const char *TESTFLAG = "--test";
    const char *HELPFLAG = "--help";
    const char *FILEFLAG = "--file";
    const char *TESTFLG = "-t";
    const char *HELPFLG = "-h";
    const char *FILEFLG = "-f";

    void (*ptr_run_tests)(void);
    ptr_run_tests = RunTests;
    void (*ptr_help)(void);
    ptr_help = Help;
    void (*ptr_file)(void);
    ptr_file = ReadFile;

    struct ParametersOfFlags struct_flags[] = {{TESTFLAG, TESTFLG, ptr_run_tests}, 
                                               {HELPFLAG, HELPFLG, ptr_help},  
                                               {FILEFLAG, FILEFLG, ptr_file}};

    const char *input_flag = argv[argc - 1];
    int len = sizeof(struct_flags) / sizeof(struct_flags[0]);

    for (int i = 0; i < len; i++)
    {
        int res = UseFlags(input_flag, &struct_flags[i]);
        if (res == 0)
            return 0;
    }

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

    return 0;
}






