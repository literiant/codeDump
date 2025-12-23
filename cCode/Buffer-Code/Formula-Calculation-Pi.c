#include <stdio.h>
#include <math.h>
int main()
{
    double pi1 = 0;
    double pi2 = 4;
    double precision;
    scanf("%lf", &precision);
    double time = 0;
    double difference;
    do
    {
        time++;
        pi1 += 4 * pow(-1, time + 1) / (2 * time - 1);
        pi2 += 4 * pow(-1, time) / (2 * (time + 1) - 1);
        difference = (pi1 - pi2) > 0 ? (pi1 - pi2) : (pi2 - pi1);
    } while (difference >= precision);
    printf("%.lf", (time + 1));
    return 0;
} // 公式计算圆周率,误差小于给定参数