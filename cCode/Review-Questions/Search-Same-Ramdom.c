#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    int num[100];
    srand((unsigned int)time(NULL));
    for(int i = 0; i<100; i++)
    num[i] = (rand()%100+1);
    for(int i = 0;i<99;i++)
    {
        for(int j = 1;j<99-i;j++)
        {
            if(num[i] == num[j])
            {
                printf("%d",num[i]);
                return 0;
            }
        }
    }
    return 0;
}