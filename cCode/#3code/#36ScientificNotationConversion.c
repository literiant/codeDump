#include <stdio.h>
#include <math.h>
int main()
{
    float num;
    int index;
    char SciNota[20];
    scanf("%s", SciNota);
    sscanf(SciNota, "%fe%d", &num, &index);
    num = num * pow(10, index);
    printf("%f\n", num);
    return 0;
}