//решает квадратные уравнения с точностью до 3-го знака после запятой

#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#include "fun.h"
#include "file.h"


int main(const int argc, const char *argv[])
{
    const char *input_flag = (argc >= 2) ? argv[1] : "-h";
    const char *input_file = (argc >= 3) ? argv[2] : "";
    int len = sizeof(struct_flags) / sizeof(struct_flags[0]);
    if (input_flag == nullptr)
    {
        printf("enter -h");
        return 0;
    }

    int res = UseFlags(input_file, input_flag, struct_flags, len);
    return 0;
}









