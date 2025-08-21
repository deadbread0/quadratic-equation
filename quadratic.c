//решает квадратные уравнения с точностью до 2-го знака после запятой
#include <stdio.h>

int input(float*, float*, float*);
float squareroot(float);
void findsolution(float, float, float, int*);
void output(float, float, float, int);
char getanswer();
void BodyOfProgramm();

enum ad {a_and_d_equal_to_zero, only_a_equal_to_zero, only_d_equal_to_zero, a_and_d_equal_to_notzero};

int main()
{
    BodyOfProgramm();
    return 0;
}

int input(float *ptra, float *ptrb, float *ptrc)
{
    printf("Введите через пробел коэффициенты a, b, c для квадратного уравнения вида ax^2 + bx + c = 0\n");
    printf("Для завершения программы введите любую букву (например q)\n");
    return scanf("%f%f%f", ptra, ptrb, ptrc);
}

float squareroot(const float square) 
{
    float low = 0;
    float high = square;
    int variable_int;
    float accuracy = 0.01;

    if (square < 1)
        high = 1;

    while ((high - low) > accuracy)
    {
        float mid = (low + high) / 2;
        if (mid * mid < square)
            low = mid;
        else
            high = mid;
    }

    return low;
}

void findsolution(const float a, const float b, const float c, int * ptrMeaningOfad)
{
    float d = b * b - 4 * a * c;
    if (a == 0 && b == 0 && c == 0)
        *ptrMeaningOfad = a_and_d_equal_to_zero; 
    else if (a == 0 && b != 0 && d != 0)
        *ptrMeaningOfad = only_a_equal_to_zero; 
    else if (d == 0 && a != 0)
        *ptrMeaningOfad = only_d_equal_to_zero;
    else if (d > 0 && a != 0)
        *ptrMeaningOfad = a_and_d_equal_to_notzero;
}

void output(const float a, const float b, const float c, const int MeaningOfad)
{
    float d = b * b - 4 * a * c;
    float sqrt_d = squareroot(d);
    float x01 = -c / b == 0 ? 0 : -c / b;
    float x10 = -b / (2 * a) == 0 ? 0 : -b / (2 * a);
    float x11_1 = (-b + sqrt_d) / (2 * a);
    float x11_2 = (-b - sqrt_d) / (2 * a);


    switch(MeaningOfad)
    {
        case a_and_d_equal_to_zero: printf("Тяжело...\n корней бесконечно много\n"); break;
        case only_a_equal_to_zero: printf("x = %.2f\n", x01); break;
        case only_d_equal_to_zero: printf("1 корень: x = %.2f\n", x10); break;
        case a_and_d_equal_to_notzero: printf("2 корня:\n x = %.2f\n x = %.2f\n", x11_1, x11_2); break;
        default: printf("корней нет\n");
    }
}

char getanswer()
{
    char choice;
    choice = getchar(); 
    while (getchar() != '\n') 
        continue; 
    return choice;
}
void BodyOfProgramm()
{
    float a = 0;
    float b = 0;
    float c = 0;
    int count_inputnum = 0;
    int MeaningOfad = 0;

    count_inputnum = input(&a, &b, &c);

    while (count_inputnum == 3)
    {
        findsolution(a, b, c, &MeaningOfad);
        output(a, b, c, MeaningOfad);
        count_inputnum = input(&a, &b, &c);
    }
    char last_notright_input = getanswer();
    printf("Вы точно хотите выйти из программы?\n");
    char answer = getanswer();
    if (answer == 'n')
        BodyOfProgramm();
}