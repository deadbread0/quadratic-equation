//решает квадратные уравнения
#include <stdio.h>

int input(int*, int*, int*);
float squareroot(int);
void mathpart(int, int, int, int*);
void output(int, int, int, int);

int main()
{
    int a, b, c, count, flag;
    a = b = c = count = flag = 0;

    count = input(&a, &b, &c);

    while (count==3)
    {
        mathpart(a, b, c, &flag);
        output(a, b, c, flag);
        count = input(&a, &b, &c);
    }

    return 0;
}

int input(int *yka, int *ykb, int *ykc)
{
    printf("Введите через пробел целые коэффициенты a, b, c для квадратного уравнения вида ax^2 + bx + c = 0\n");
    printf("Для завершения программы введите любую букву (например q)\n");
    return scanf("%d%d%d", &(*yka), &(*ykb), &(*ykc));
}

float squareroot(const int kv) //наверное можно попроще, но я не знаю как, поэтому написала функцию приближенного извлечения корня
{
    float root, r;
    float min = kv;
    for (root = 0; root<=kv; root+=0.1)
    {
        float mod = (root*root>kv)?(root*root-kv):(kv-root*root);
        if (mod<min)
        {
            min = mod;
            r = root;
        }
    }
    return r;
}

void mathpart(const int a, const int b, const int c, int * ykflag)
{
    int d = b*b-4*a*c;
    if (a==0 && b==0 && c==0)
        *ykflag = 1;
    else if ((a==0 && b!=0 && c!=0) || (a==0 && c==0 && b!=0))
        *ykflag = 2; 
    else if (d==0 && a!=0)
        *ykflag = 3;
    else if (d>0 && a!=0)
        *ykflag = 4;
}

void output(const int a, const int b, const int c, const int flag)
{
    switch(flag)
    {
        case 1: printf("Тяжело...\n корней бесконечно много\n"); break;
        case 2: printf("x = %.2f\n", (float)-c/b); break;
        case 3: printf("1 корень: x = %.2f\n", (float)-b/(2*a)); break;
        case 4: printf("2 корня:\n x = %.2f\n x = %.2f\n", (float)(-b+squareroot(b*b-4*a*c))/(2*a), (float)(-b-squareroot(b*b-4*a*c))/(2*a)); break;
        default: printf("корней нет\n");
    }
}