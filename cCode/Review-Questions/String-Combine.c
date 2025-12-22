#include<stdio.h>
#include<string.h>
void str_bin(char* str1,char* str2)
{
    int n = strlen(str1);
    int m = strlen(str2);
    for(int i = 0;i<=m;i++)
    {
        str1[n+i] = str2[i];
    }

}

void StrSort(char* str1)
{
    int n = strlen(str1);
    for(int i = 0;i<n-1;i++)
    {
        for(int j = 0; j<n-1-i;j++)
        {
            if(str1[j]>str1[j+1])
            {
                char temp = str1[j];
                str1[j] = str1[j+1];
                str1[j+1] = temp;
            }
        }
    }
}

int main()
{
    char str1[201],str2[101];
    scanf("%s %s",str1,str2);
    str_bin(str1,str2);
    StrSort(str1);
    printf("%s",str1);
    return 0;
}