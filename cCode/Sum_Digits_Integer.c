#include <stdio.h>
#include <stdlib.h>
int sum(int x)
{
    int Nsum =0;
    char str[100];
    int N[100];
    sprintf(str,"%d",x);
    int len = 0;
    int i =0;
    while(str[i] != '\0')
    {
        len++;
        i++;
    }
    for(i = 0;i<len;i++)
    {
        N[i]=str[i]-'0';
        Nsum += N[i];
    }

    return Nsum;
}
int main()
{
    int n;
    scanf("%d",&n);
    printf("%d",sum(n));
    return 0;
}
