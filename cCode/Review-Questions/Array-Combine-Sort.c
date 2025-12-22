#include<stdio.h>

void GetIntArr(int a[],int n)
{
    for(int i = 0;i<n;i++)
    scanf("%d",&a[i]);
}

void combine (int a[],int *n,int b[],int m)
{   int count=0;
    for(int i = 0 ;i < m;i++)
    {   int ishave = 0;
        for(int j = 0;j < *n+count;j++)
        {
            if(a[j] == b[i])
            ishave = 1;
        }
        if(!ishave)
        {
        a[*n+count] = b[i];
        count++;
        }
    }
    *n += count;
}

void sort(int a[], int n)
{
    for(int i = 0; i<n-1;i++)
    {
        for(int j = 0; j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

void PutIntArr(int a[],int n)
{
    for(int i = 0;i<n;i++)
    printf("%d ",a[i]);
}

int main()
{
    int n,m,a[40],b[20];
    scanf("%d %d",&n,&m);
    GetIntArr(a,n);
    GetIntArr(b,m);
    combine(a,&n,b,m);
    sort(a,n);
    PutIntArr(a,n);
    return 0;
}