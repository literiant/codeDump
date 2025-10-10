#include<stdio.h>
int main()
{
  printf("==========九九乘法表==========");
  for(int h=1;h<=9;h++)//从每行开始
    {
      for(int v=1;v<=9;v++)//依次算每列
      {
        printf("|v*h");
      }
      printf("|\n");\\结尾换行
    }
  printf("-------------------");//给表封个底
    return 0
}
