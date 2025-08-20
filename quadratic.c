//решает квадратные уравнения с точностью до 2-го знака после запятой
#include <stdio.h>

int input(float*, float*, float*);
float squareroot(float);
void findsolution(float, float, float, int*);
void output(float, float, float, int);

int main()
{
    float a = 0;
    float b = 0;
    float c = 0;
    int count_inputnum = 0;
    int way_of_solution = 0; 

    count_inputnum = input(&a, &b, &c);

    while (count_inputnum==3)
    {
        findsolution(a, b, c, &way_of_solution);
        output(a, b, c, way_of_solution);
        count_inputnum = input(&a, &b, &c);
    }

    return 0;
}

int input(float *ptra, float *ptrb, float *ptrc)
{
    printf("Введите через пробел коэффициенты a, b, c для квадратного уравнения вида ax^2 + bx + c = 0\n");
    printf("Для завершения программы введите любую букву (например q)\n");
    return scanf("%f%f%f", ptra, ptrb, ptrc);
}

float squareroot(float const square) 
{
    float low = 0;
    float high = square;
    int variable_int;

    if (square < 1)
        high = 1;

    while ((high - low) > 0.01)
    {
        float mid = (low + high) / 2;
        if (mid * mid < square)
            low = mid;
        else
            high = mid;
    }

    return low;
}

void findsolution(const float a, const float b, const float c, int * ptrway_of_solution)
{
    float d = b * b - 4 * a * c;
    if (a == 0 && b == 0 && c == 0)
        *ptrway_of_solution = 1;
    else if (a == 0 && b != 0 && d != 0)
        *ptrway_of_solution = 2; 
    else if (d == 0 && a != 0)
        *ptrway_of_solution = 3;
    else if (d > 0 && a != 0)
        *ptrway_of_solution = 4;
}

void output(const float a, const float b, const float c, const int way_of_solution)
{
    float sqrt_d = squareroot(b * b - 4 * a * c);
    switch(way_of_solution)
    {
        case 1: printf("Тяжело...\n корней бесконечно много\n"); break;
        case 2: printf("x = %.2f\n", (float)-c / b == 0 ? 0 : -c / b); break;
        case 3: printf("1 корень: x = %.2f\n", (float)-b / (2 * a) == 0 ? 0 : -b / (2 * a)); break;
        case 4: printf("2 корня:\n x = %.2f\n x = %.2f\n", (float)(-b + sqrt_d) / (2 * a), (float)(-b - sqrt_d) / (2 * a)); break;
        default: printf("корней нет\n");
    }
}