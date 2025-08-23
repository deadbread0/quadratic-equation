//решает квадратные уравнения с точностью до 3-го знака после запятой
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

struct abc_amount_of_solutions_x{
    double a;
    double b;
    double c;
    int *amount_of_solutions;
    double *x1;
    double *x2;
};

int input(double*, double*, double*);
double squareroot(double);
void findsolution(struct abc_amount_of_solutions_x);
void output(int, double, double);
_Bool getanswer();
int comparison_with_num(double, double);
void input_answer(char*);
char buffer_cleaning();
void tests();

enum Roots_amount {
    INF, 
    ONE,
    TWO, 
    ZERO
};
enum Num_is {
    FIRST_EQUAL_TO_SECOND,
    FIRST_GREATER_THAN_SECOND,
    FIRST_LESS_THAN_SECOND,
};

int main()
{
    double x1 = 0;
    double x2 = 0;
    double a = 0;
    double b = 0;
    double c = 0;
    int count_inputnum = 0;
    int amount_of_solutions = 0;
    _Bool flag = true;

    while (flag)
    {
        count_inputnum = input(&a, &b, &c);

        while (count_inputnum == 3)
        {
            struct abc_amount_of_solutions_x struct_ptrx = {a, b, c, &amount_of_solutions, &x1, &x2};
            findsolution(struct_ptrx);
            //tests();
            output(amount_of_solutions, x1, x2);
            count_inputnum = input(&a, &b, &c);
        }
        flag = getanswer();
    }

    return 0;
}

int input(double *ptra, double *ptrb, double *ptrc)
{
    assert(ptra != NULL);
    assert(ptrb != NULL);
    assert(ptrc != NULL);

    printf("Введите через пробел коэффициенты a, b, c для квадратного уравнения вида ax^2 + bx + c = 0\n");
    printf("Для завершения программы введите любую букву (например q)\n");
    return scanf("%lf%lf%lf", ptra, ptrb, ptrc);
}

double squareroot(const double square) 
{
    double low = 0;
    double high = square;
    int variable_int = 0;
    const double ACCURACY = 1e-9;

    if (square < 1)
        high = 1;

    while ((high - low) > ACCURACY)
    {
        double mid = (low + high) / 2;
        if (mid * mid < square)
            low = mid;
        else
            high = mid;
    }

    return low;
}

void findsolution(struct abc_amount_of_solutions_x struct_ptrx)
{
    assert(struct_ptrx.amount_of_solutions != NULL);
    assert(struct_ptrx.x1 != NULL);
    assert(struct_ptrx.x2 != NULL);

    double d = (struct_ptrx.b * struct_ptrx.b) - (4 * struct_ptrx.a * struct_ptrx.c);
    double sqrt_d = squareroot(d);
    const int ZERO0 = 0;

    if (comparison_with_num(struct_ptrx.a, ZERO0) == FIRST_EQUAL_TO_SECOND && comparison_with_num(struct_ptrx.b, ZERO0) == FIRST_EQUAL_TO_SECOND && comparison_with_num(struct_ptrx.c, ZERO0) == FIRST_EQUAL_TO_SECOND)
        *struct_ptrx.amount_of_solutions = INF; 
    else if (comparison_with_num(struct_ptrx.a, ZERO0) == FIRST_EQUAL_TO_SECOND && comparison_with_num(struct_ptrx.b, ZERO0) != FIRST_EQUAL_TO_SECOND)
    {
        *struct_ptrx.amount_of_solutions = ONE;
        float x = -struct_ptrx.c / struct_ptrx.b;
        *struct_ptrx.x1 = (comparison_with_num(x, ZERO0) == FIRST_EQUAL_TO_SECOND) ? 0 : x;
    }
    else if (comparison_with_num(d, ZERO0) == FIRST_EQUAL_TO_SECOND && comparison_with_num(struct_ptrx.a, ZERO0) != FIRST_EQUAL_TO_SECOND)
    {
        float x = -struct_ptrx.b / (2 * struct_ptrx.a);
        *struct_ptrx.amount_of_solutions = ONE;
        *struct_ptrx.x1 = (comparison_with_num(x, ZERO0) == FIRST_EQUAL_TO_SECOND) ? 0 : x;
    }
    else if (comparison_with_num(d, ZERO0) == FIRST_GREATER_THAN_SECOND && comparison_with_num(struct_ptrx.a, ZERO0) != FIRST_EQUAL_TO_SECOND)
        {
            *struct_ptrx.amount_of_solutions = TWO;
            *struct_ptrx.x1 = (-struct_ptrx.b + sqrt_d) / (2 * struct_ptrx.a);
            *struct_ptrx.x2 = (-struct_ptrx.b - sqrt_d) / (2 * struct_ptrx.a);
        }
    else if (comparison_with_num(d, ZERO0) == FIRST_LESS_THAN_SECOND)
        *struct_ptrx.amount_of_solutions = ZERO;

}

void output(const int amount_of_solutions, const double x1, const double x2)
{
    switch(amount_of_solutions)
    {
        case INF: printf("Тяжело...\n корней бесконечно много\n"); break;
        case ONE: printf("x = %.3g\n", x1); break;
        case TWO: printf("2 корня:\n x = %.3g\n x = %.3g\n", x1, x2); break;
        case ZERO: printf("корней нет\n");
        default: printf("какая-то ошибка, попробуй снова!!\n");
    }
}

char buffer_cleaning()
{
    char choice = 0;
    choice = getchar(); 
    while (getchar() != '\n') 
        continue; 
    return choice;
}

_Bool getanswer()
{
    char choice[4] = "";
    const char *negative_answer = "no";
    const char *positive_answer = "yes";
    int i = 0;
    printf("Вы точно хотите выйти из программы? (yes/no)\n");
    buffer_cleaning();
    input_answer(choice);

    while(true)
    {
    if (strncmp(choice, negative_answer, 4) == 0)
        return true;
    else if ((strncmp(choice, negative_answer, 4) != 0) && (strncmp(choice, positive_answer, 4) != 0))
    {
        printf("введите no или yes\n");
        input_answer(choice);
    }
    else
        return false;
    }
}

void input_answer(char *choice)
{
    int i = 0;
    char ch;
    while (((ch = getchar()) != '\n') && i < 3)
        {
            choice[i] = ch;
            i++;
        }
}

int comparison_with_num(const double num1, const double num2)
{
    double mod = (num1 - num2 > 0) ? num1 - num2 : num2 - num1;
    const double ACCURACY = 1e-9;
    if (mod < ACCURACY)
        return FIRST_EQUAL_TO_SECOND;
    else if (num1 - num2 > ACCURACY)
        return FIRST_GREATER_THAN_SECOND;
    else if (num2 - num1 > ACCURACY)
        return FIRST_LESS_THAN_SECOND;
}

void tests()
{
    double a[] = {1, 0, 0};
    double b[] = {0, 1, 0};
    double c[] = {0, 0, 1};
    int len = 3;

    for (int i = 0; i < len; i++)
    {
        int amount_of_solutions_tests = 0;
        double x1_tests = 0, x2_tests = 0;
        struct abc_amount_of_solutions_x struct_for_tests = {a[i], b[i], c[i], &amount_of_solutions_tests, &x1_tests, &x2_tests};
        findsolution(struct_for_tests);
        if (*struct_for_tests.amount_of_solutions == ONE)
        {
            if (struct_for_tests.a * (*struct_for_tests.x1) * (*struct_for_tests.x1) + struct_for_tests.b * (*struct_for_tests.x1) + struct_for_tests.c == 0)
                printf("ok ");
        }
        else if (*struct_for_tests.amount_of_solutions == TWO)
        {
            if ((struct_for_tests.a * (*struct_for_tests.x1) * (*struct_for_tests.x1) + struct_for_tests.b * (*struct_for_tests.x1) + struct_for_tests.c == 0) && (struct_for_tests.a * (*struct_for_tests.x2) * (*struct_for_tests.x2) + struct_for_tests.b * (*struct_for_tests.x2) + struct_for_tests.c == 0))
                printf("ok ");
        }
        else
            printf("ok ");
    }
}