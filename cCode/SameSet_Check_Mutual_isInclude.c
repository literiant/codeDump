#include <stdio.h>
int isInclude(int a[],int b[],int len)
{
    int i = 0;
    int j = 0;
    int is_Same = 1;
    int isSame[100] = {0};
    for(i = 0; i<len;i++)
    {
        for(j = 0; j<len;j++)
        {
            if(a[i] == b[j])
            {
                isSame[i] = 1;
                break;
            }
        }
    }
    for(i = 0; i<len;i++)
    {
        if(isSame[i] == 0)
        is_Same = 0;
    }
    return is_Same;
}
int same_set(int a[],int b[],int len)
{
    int is_Same = 0;
    if(isInclude(a,b,len) == 1 && isInclude(b,a,len) == 1)
    is_Same = 1;
    return is_Same;
}
int main()
{
    int len;
    int a[100];
    int b[100];
    scanf("%d",&len);
    for(int i=0; i<len;i++)
    {
        scanf("%d",&a[i]);
    }
    getchar();
    for(int i=0; i<len;i++)
    {
        scanf("%d",&b[i]);
    }
    printf("%d",same_set(a,b,len));
    return 0;
}