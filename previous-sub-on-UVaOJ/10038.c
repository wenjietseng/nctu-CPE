#include <stdio.h>
#include <stdlib.h>
#define MAXN 3000 + 10

int main()
{
    int n, i, jolly, v[MAXN], a[MAXN];
    while (scanf("%d", &n) == 1)
    {
        for (i = 0; i < n; i++)
        {
            scanf("%d", &v[i]);
            a[i] = 0;
        }
        for (i = 0; i < n - 1; i++)
        {
            a[abs(v[i] - v[i + 1])] = 1;
        }
        jolly = 1;
        for (i = 1; i < n; i++)
        {
            if (!a[i]) {jolly = 0; break;}
        }
        if (jolly) printf("Jolly\n");
        else printf("Not jolly\n");
    }
    return 0;
}
