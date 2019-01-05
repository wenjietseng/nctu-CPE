#include<stdio.h>

int main()
{
    int n, q, Case = 1;
    while (scanf("%d %d", &n, &q) == 2 && n != 0 && q != 0)
    {
        int i, num, query;
        int marbles[10010] = {0};
        for (i = 0; i < n; i++)
        {
            scanf("%d", &num);
            marbles[num]++;
        }
        printf("CASE# %d:\n", Case++);
        for (i = 0; i < q; i++)
        {
            scanf("%d", &query);
            if (marbles[query] == 0)
                printf("%d not found\n", query);
            else
            {
                int j = 1, pos = 0;
                while (j != query)
                {
                    pos += marbles[j];
                    j++;
                }
                printf("%d found at %d\n", query, pos + 1);
            }
        }
    }
    return 0;
}
