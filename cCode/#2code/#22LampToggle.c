#include <stdio.h>
int main(){
    int N=0;
    int lamp[1000]={0};
    printf("Please enter the number of people:\n");
    scanf("%d",&N);
    int i=0,j=0;
    for(i=1;i<=N;i++)
    for(j=i;j<=N;j+=i)
    lamp[j]=!lamp[j];
    for(i=1;i<=N;i++)
    if(lamp[i]==1)
    printf("The lamp No.%d is lighted on\n",i);
    return 0;
}