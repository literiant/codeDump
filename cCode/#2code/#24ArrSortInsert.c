#include <stdio.h>
int main()
{
    int arr[11] = {1, 4, 6, 9, 13, 16, 19, 28, 40, 100};
    int n;
    scanf("%d", &n);
    int count = 0;
    int i;
    for (i = 0; i < 10; i++)
    {
        if (arr[i] <= n)
            count++;
        else
            break;
    }
    for (i = 9; i >= count; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[count] = n;
    for (i = 0; i < 11; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
