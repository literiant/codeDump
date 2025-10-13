#include <stdio.h>
int arrayMax(int a[], int count)
{
    int max = a[0];
    if (count <= 0)
        return 1;
    else
    {
        for (int i = 1; i <= count; i++)
        {
            if (max < a[i])
                max = a[i];
        }
    }
    return max;
}
int main()
{
    int arr[] = {23, 13, 123, 43, 13, 54};
    int len;
    len = sizeof(arr) / sizeof(arr[0]);
    int max = arrayMax(arr, len);
    printf("The maximum is %d", max);
    return 0;
}