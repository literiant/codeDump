#include<stdio.h>

int main()
{
   char str[101]={0};
   char *p;
   p=str;
   int nCount=0,cCount=0;
    printf("Please enter a string:");
    gets(str);
    do{
        if((*p>='0')&&(*p<='9'))nCount++;
        else if(((*p>='a')&&(*p<='z'))||((*p>='A'&&*p<='Z')))cCount++;
        p++;
    }while(*p!='\0');
    printf("The number of figure is %d\n",nCount);
    printf("The number of letter is %d",cCount);
    return 0;
}