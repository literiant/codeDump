#include<stdio.h>
#include<string.h>
struct Student
{
    char name[50];
    int xuehao;
    int nianling;
};
int main()
{
    int n;
    scanf("%d",&n);
   
    struct Student students[50];
    struct Student temp;
    for(int i=0;i<n;++i)
    {
    scanf("%d %s %d",&students[i].xuehao,
          students[i].name,
          &students[i].nianling);
    }
    
    
    for(int i=0;i<n-1;++i)
    {
        for(int j=0;j<n-1-i;j++)
        {
        if(strcmp(students[j].name,students[j+1].name)>0)
        {
            temp=students[j];
            students[j]=students[j+1];
            students[j+1]=temp;
            
        }
        }
    }
    
    
    for(int i=0;i<n;i++)
    {
    printf("%3d%6s%3d\n",students[i].xuehao,students[i].name,
           students[i].nianling);
    }
    
    printf("\n");
    
    for(int i=0;i<n-1;i++)
    {
    for(int j=0;j<n-i-1;j++)
    {
    if(students[j].nianling>students[j+1].nianling
       ||(students[j].nianling==students[j+1].nianling&&strcmp(students[j].name,
                                              students[j+1].name)>0))
    {
    temp=students[j];
        students[j]=students[j+1];
        students[j+1]=temp;
    }
    }
    }
    for(int i=0;i<n;i++)
    {
    printf("%3d%6s%3d\n",students[i].xuehao,students[i].name,students[i].nianling);
    }
    return 0;
}