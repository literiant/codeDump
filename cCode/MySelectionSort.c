#include <stdio.h>
int main()
{
    int n=10;
    int array[10]={0};
    int i=0,j=0;
    int min=0;
    printf("Please enter 10 integers:\n");
    for(i=0;i<10;i++)
    {
        scanf("%d",&array[i]);
    }
    for(i=0;i<n-1;i++)
    {min=array[i];
    for(j=i;j<n;j++)
    if(array[j]<min)
    {
        min=array[j];
        array[j]=array[i];
        array[i]=min;
    }
    }
    for(i=0;i<n;i++)
    printf("%d ",array[i]);
    return 0;
}