#include<stdio.h>
#include<math.h>
int main()
{
    double sinx=0,x,n;
    scanf("%lf %lf",&x,&n);
    for(int i = 1;i<=n;i++)
    {   
        double fac=1;
        for(int j = 1;j<=(2*i-1);j++)
        {
            fac*=j;
        }
        double X = 1;
        X = pow(x,(2*i-1));
         
        sinx += (pow(-1,i-1)*X)/fac;
    }
    printf("%.8f",sinx);
    return 0;
}