#include<stdio.h>
int max(int n,int m)
{
    return n>m?n:m;
}
int min(int n,int m)
{
    return n<m?n:m;
}
int main()
{   int area;
    int Ax1,Ay1,Ax2,Ay2;//left-up 和right-down
    int Bx1,By1,Bx2,By2;
    scanf("%d %d %d %d %d %d %d %d",&Ax1,&Ay1,&Ax2,&Ay2,&Bx1,&By1,&Bx2,&By2);
    int left,right;
    int down,up;
    int width,height;
    left = max(Ax1,Bx1);
    right = min(Ax2,Bx2);
    width = right - left;
    if(width <= 0)
        area = 0;
    down = max(Ay2,By2);
    up = min(Ay1,By1);
    height = up - down;
    if(height <= 0)
        area = 0;
        if(height>0&&width>0)
        area = width*height;
        printf("%d\n",area);
}