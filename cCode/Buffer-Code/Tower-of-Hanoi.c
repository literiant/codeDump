#include <stdio.h>
static int count = 0;
void hanoi(int n, char src, char aux, char dest)
{
    if (n == 1)
    {
        printf("Move disk %d from %c to %c\n", n, src, dest);
        count++;
    }
    else
    {
        hanoi(n - 1, src, dest, aux);
        printf("Move disk %d from %c to %c\n", n, src, dest);
        count++;
        hanoi(n - 1, aux, src, dest);
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    char src = 'A', aux = 'B', dest = 'C';
    hanoi(n, src, aux, dest);
    printf("Total moves: %d", count);
    return 0;
}