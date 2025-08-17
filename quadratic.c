//решает квадратные уравнения
#include <stdio.h>

void input();
float sqr(int);

int main()
{
    input();
    int a, b, c;

    while (scanf("%d%d%d", &a, &b, &c))
    {
        int d = b*b-4*a*c;
        if (a==0 && b==0 && c==0)
            printf("Тяжело...\n корней бесконечно много\n");
        else if ((a==0 && b!=0 && c!=0) || (a==0 && c==0 && b!=0))
            printf("x = %.2f\n", (float)(-c/b)); 
        else if (d==0 && a!=0)
            printf("1 корень: x = %.2f\n", (float)(-b)/(2*a));
        else if (d>0 && a!=0)
            printf("2 корня:\n x = %.2f\n x = %.2f\n", (float)(-b+sqr(d))/(2*a), (float)(-b-sqr(d))/(2*a));
        else 
            printf("корней нет\n");
        input();
    }

    return 0;
}

void input()
{
    printf("Введите через пробел целые коэффициенты a, b, c для квадратного уравнения вида ax^2 + bx + c = 0\n");
    printf("Для завершения программы введите любую букву (например q)\n");
    return;
}

float sqr(int kv) //наверное можно попроще, но я не знаю как, поэтому написала функцию приближенного извлечения корня
{
    float root, r;
    int min = kv;
    for (root = 0; root<kv; root+=0.01)
    {
        int mod = (root*root>kv)?(root*root-kv):(kv-root*root);
        if (mod<min)
        {
            min = mod;
            r = root;
        }
    }
    return r;
}