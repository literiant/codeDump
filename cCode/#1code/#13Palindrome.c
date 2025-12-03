#include<stdio.h>
int loop(int x){
    int original=x;
    int reversed=0;
    while(x>0){
        reversed=reversed*10+x%10;
        x/=10;
    }
        return original==reversed?1:0;
    }

    int main()
    {
        int a,b;
        scanf("%d %d",&a,&b);
        for(int i=a;i<=b;i++){
            if(loop(i)){
                printf("%d\n",i);
                       }
        }
        return 0;
    }
            
