//решает квадратные уравнения с точностью до 3-го знака после запятой

#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#include "quadratic.h"


int main(const int argc, const char *argv[])
{
    const char *input_flag = (argc >= 2) ? argv[1] : "-h";
    const char *input_file = (argc >= 3) ? argv[2] : "";
    const char *output_file = (argc >= 4) ? argv[3] : nullptr;

    int res = CompareFlagsAndRunFunction(input_file, input_flag, output_file, struct_flags);
    return 0;
}









