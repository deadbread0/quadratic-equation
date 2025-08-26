#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#include "file.h"
double SquareRoot(const double square) 
{
    double low = 0;
    double high = square;
    int variable_int = 0;
    const double ACCURACY = 1e-12;

    if (square < 1)
        high = 1;

    while (ComparisonDouble((high - low), ACCURACY) == FIRST_GREATER_THAN_SECOND)
    {
        double mid = (low + high) / 2;
        if (ComparisonDouble(mid * mid, square) == FIRST_LESS_THAN_SECOND)
            low = mid;
        else
            high = mid;
    }

    return low;
}

int ComparisonDouble(const double num1, const double num2)
{
    double mod = Mod(num1 - num2);
    const double ACCURACY = 1e-12;
    if (mod < ACCURACY)
        return FIRST_EQUAL_TO_SECOND;
    else if (num1 > num2)
        return FIRST_GREATER_THAN_SECOND;
    else
        return FIRST_LESS_THAN_SECOND;
}

double Mod(double num)
{
    return (num >= 0) ? num : -num;
}   

void FindSolution(struct ParametersOfTheEquation *struct_ptr)
{
    assert(struct_ptr != nullptr);

    double a0 = struct_ptr->a;
    double b0 = struct_ptr->b;
    double c0 = struct_ptr->c;
    const int ZERO0 = 0;

    double d = (b0 * b0) - (4 * a0 * c0);
    double sqrt_d = SquareRoot(d);
    int comp_a = ComparisonDouble(a0, ZERO0);
    int comp_b = ComparisonDouble(b0, ZERO0);
    int comp_c = ComparisonDouble(c0, ZERO0);
    int comp_d = ComparisonDouble(d, ZERO0);

    if (comp_a == FIRST_EQUAL_TO_SECOND && comp_b == FIRST_EQUAL_TO_SECOND && comp_c == FIRST_EQUAL_TO_SECOND)
        (struct_ptr->amount_of_solutions) = INF; 
    else if (comp_a == FIRST_EQUAL_TO_SECOND && comp_b != FIRST_EQUAL_TO_SECOND)
    {
        (struct_ptr->amount_of_solutions) = ONE;
        double x = -c0 / b0;
        (struct_ptr->x1) = (ComparisonDouble(x, ZERO0) == FIRST_EQUAL_TO_SECOND) ? 0 : x;
    }
    else if (comp_d == FIRST_EQUAL_TO_SECOND && comp_a != FIRST_EQUAL_TO_SECOND)
    {
        double x = -b0 / (2 * a0);
        struct_ptr->amount_of_solutions = ONE;
        (struct_ptr->x1) = (ComparisonDouble(x, ZERO0) == FIRST_EQUAL_TO_SECOND) ? 0 : x;
    }
    else if (comp_d == FIRST_GREATER_THAN_SECOND && comp_a != FIRST_EQUAL_TO_SECOND)
        {
            (struct_ptr->amount_of_solutions) = TWO;
            (struct_ptr->x1) = (-b0 - sqrt_d) / (2 * a0);
            (struct_ptr->x2) = (-b0 + sqrt_d) / (2 * a0);
        }
    else if (comp_d == FIRST_LESS_THAN_SECOND)
        (struct_ptr->amount_of_solutions) = ZERO;

}