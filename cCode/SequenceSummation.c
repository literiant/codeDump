/* 数列求和
【问题描述】

有一个数列如下：

Snipaste_2022-07-08_11-10-31.jpg

总结规律，并编写程序求这个数列的前n项之和，并保留两位小数。


【输入形式】

输入一个正整数n

【输出形式】

输出前n项数列之和

【样例输入】

3
【样例输出】

5.17*/
#include <stdio.h>
int main()
{
    int n;
    double sum=0.0;
    int fz1=2,fz2=3;
    int fm1=1,fm2=2;
    int temp_fz,temp_fm;
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
        if(i==0){sum+=(double)fz1/fm1;}
        else if(i==1){sum+=(double)fz2/fm2;}
        else{
            int current_fz=fz1+fz2;
            int current_fm=fm1+fm2;
            sum+=(double)current_fz/current_fm;
            temp_fz=fz2;
            fz2=current_fz;
            fz1=temp_fz;
            temp_fm=fm2;
            fm2=current_fm;
            fm1=temp_fm;
             }
    }
        printf("%.2f\n",sum);
        return 0;
}