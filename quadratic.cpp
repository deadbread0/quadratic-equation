//решает квадратные уравнения с точностью до 3-го знака после запятой
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define MAX_LEN_OF_WORD 100

struct ParametersOfTheEquation{
    double a;
    double b;
    double c;
    int amount_of_solutions;
    double x1;
    double x2;
};

int Input(struct ParametersOfTheEquation*);
double SquareRoot(double);
void FindSolution(struct ParametersOfTheEquation*);
void Output(struct ParametersOfTheEquation*);
bool GetAnswer();
int ComparisonDouble(double, double);
void CopyBufferInput(char*);
void BufferCleaning();
void Tests();
double Mod(double);
int OneTest(struct ParametersOfTheEquation);

enum RootsAmount {
    INF, 
    ONE,
    TWO, 
    ZERO
};
enum NumIs {
    FIRST_EQUAL_TO_SECOND,
    FIRST_GREATER_THAN_SECOND,
    FIRST_LESS_THAN_SECOND
};

int main()
{
    int count_inputnum = 0;
    bool flag = true;
    const int COUNT_ABC = 3;

    struct ParametersOfTheEquation struct_ptr = {NAN, NAN, NAN, 0, NAN, NAN};
    Tests();

    while (flag)
    {
        count_inputnum = Input(&struct_ptr);

        while (count_inputnum == COUNT_ABC)
        {

            FindSolution(&struct_ptr);
            Output(&struct_ptr);
            count_inputnum = Input(&struct_ptr);
        }
        flag = GetAnswer();
    }

    return 0;
}

int Input(struct ParametersOfTheEquation *struct_ptr)
{
    assert(struct_ptr != nullptr);
    while (true)
    {
        double a = 0, b = 0, c = 0;

        printf("Введите через пробел коэффициенты a, b, c для квадратного уравнения вида ax^2 + bx + c = 0\n");
        printf("Для завершения программы введите любую букву (например q)\n");

        int count_abc = 0;
        char ch = 0;
        count_abc = scanf("%lf%lf%lf", &a, &b, &c);
        //BufferCleaning();

        if (ch = getchar() != '\n')
            return 0;
        else
            continue;

        BufferCleaning();
        struct_ptr->a = a;
        struct_ptr->b = b;
        struct_ptr->c = c;
        return count_abc;
    }
}

double SquareRoot(const double square) 
{
    double low = 0;
    double high = square;
    int variable_int = 0;
    const double ACCURACY = 1e-9;

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

void Output(struct ParametersOfTheEquation *struct_ptr)
{
    assert(struct_ptr != nullptr);

    switch(struct_ptr->amount_of_solutions)
    {
        case INF: printf("Тяжело...\n корней бесконечно много\n"); break;
        case ONE: printf("x = %.3g\n", struct_ptr->x1); break;
        case TWO: printf("2 корня:\n x = %.3g\n x = %.3g\n", struct_ptr->x1, struct_ptr->x2); break;
        case ZERO: printf("корней нет\n");break;
        default: printf("какая-то ошибка, попробуй снова!!\n");
    }
}

void BufferCleaning()
{
    while (getchar() != '\n') 
        continue; 
}

bool GetAnswer()
{
    char choice[MAX_LEN_OF_WORD] = "";
    const char *NEGATIVE_ANSWER = "no";
    const char *POSITIVE_ANSWER = "yes";
    printf("Вы точно хотите выйти из программы? (yes/no)\n");
    BufferCleaning();
    CopyBufferInput(choice);

    int negative = strncmp(choice, NEGATIVE_ANSWER, MAX_LEN_OF_WORD);
    int positive = strncmp(choice, POSITIVE_ANSWER, MAX_LEN_OF_WORD);

    while(true)
    {
        if (negative == 0)
            return true;
        else if (positive == 0)
            return false;
        else
        {
            printf("введите no или yes\n");
            CopyBufferInput(choice);
            BufferCleaning();
        }
    }
}

void CopyBufferInput(char *choice)
{
    int i = 0;
    char ch;
    while (((ch = getchar()) != '\n') && i < MAX_LEN_OF_WORD)
    {
        choice[i] = ch;
        i++;
    }
}

int ComparisonDouble(const double num1, const double num2)
{
    double mod = Mod(num1 - num2);
    const double ACCURACY = 1e-9;
    if (mod < ACCURACY)
        return FIRST_EQUAL_TO_SECOND;
    else if (num1 - num2 > ACCURACY)
        return FIRST_GREATER_THAN_SECOND;
    else
        return FIRST_LESS_THAN_SECOND;
}

double Mod(double num)
{
    return (num >= 0) ? num : -num;
}

void Tests()
{

    unsigned int count_right_answer = 0;
    struct ParametersOfTheEquation mass[] = {
        {1, 0, 0, 1, 0, 0},
        {0, 1, 0, 1, 0, 0},
        {0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {1, 2, 1, 1, -1, 0},
        {0.000001, 0.000002, 0.000001, 1, -1, 0},
        {1, -3, 2, 2, 1, 2},
        {1, -15, 26, 2, 2, 13}
    };
    const int len = sizeof(mass) / sizeof(mass[0]);
    for (int i = 0; i < len; i++)
        count_right_answer += OneTest(mass[i]);
    if (count_right_answer == len)
        printf("все норм\n");

}

int OneTest(struct ParametersOfTheEquation mass_i)
{
    struct ParametersOfTheEquation struct_ptr_tests = {NAN, NAN, NAN, 0, NAN, NAN};

    struct_ptr_tests.a = mass_i.a;
    struct_ptr_tests.b = mass_i.b;
    struct_ptr_tests.c = mass_i.c;

    FindSolution(&struct_ptr_tests);
    if (!(ComparisonDouble(struct_ptr_tests.x1, mass_i.x1) == FIRST_EQUAL_TO_SECOND) && 
         (ComparisonDouble(struct_ptr_tests.x2, mass_i.x2) == FIRST_EQUAL_TO_SECOND))
    {
        printf("вывод неправильного ответа!!\n"
               "полученный ответ: %.3g, %.3g\n"
               "ожидаемый ответ: %.3g, %.3g\n\n", struct_ptr_tests.x1, struct_ptr_tests.x2, mass_i.x1, mass_i.x2);
        return 0;
    }
    return 1;
}
 
