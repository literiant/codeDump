#include <stdio.h>
#include <stdlib.h>
typedef struct link
{
    int index;
    struct link *next;
} link;
link *initlink(int n)
{
    link *p = NULL;
    link *temp = (link *)malloc(sizeof(link));
    temp->index = n;
    temp->next = NULL;
    p = temp;

    for (int i = 1; i <= n; i++)
    {
        link *a = (link *)malloc(sizeof(link));
        scanf("%d", &(a->index));
        a->next = NULL;
        temp->next = a;
        temp = temp->next;
    }
    temp->next = p->next;
    return p;
}
void josephus(link *p, int m)
{
    link *temp = p;
    for (int j = 0; j < p->index; j++)
    {
        for (int i = 0; i < m - 1; i++)
        {
            temp = temp->next;
        }
        link *dellink = temp->next;
        temp->next = temp->next->next;

        dellink->next = NULL;
        printf("%d ", dellink->index);
        free(dellink);
    }
}
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    link *p = initlink(n);
    josephus(p, m);
    return 0;
}