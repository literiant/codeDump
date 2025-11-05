#include <stdio.h>
int main()
{
    float a = 0, b = 0;
    float result = 0;
    char c;
    char opt;
    do
    {
        scanf("%f %c %f", &a, &c, &b);
        getchar();
        switch (c)
        {
        case '+':
            result = a + b;
            printf("%.2f %c %.2f = %.2f\n", a, c, b, result);
            break;
        case '-':
            result = a - b;
            printf("%.2f %c %.2f = %.2f\n", a, c, b, result);
            break;
        case '*':
            result = a * b;
            printf("%.2f %c %.2f = %.2f\n", a, c, b, result);
            break;
        case '/': // 重点
            if (b == 0)
            {
                printf("error");
                break;
            }
            result = a / b;
            printf("%.2f %c %.2f = %.2f\n", a, c, b, result);
            break;
        default:
            printf("error");
        };

        scanf("%c", &opt);
        getchar();
    } while (opt == 'y' || opt == 'Y');
    return 0;
}