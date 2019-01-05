#include <stdio.h>

int main()
{
    int n, m;
    while (scanf("%d %d", &n, &m) == 2)
    {
        if (n == 0 && m == 0) break;
        char field[n][m];
        int i, j;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                field[i][j] = getchar();
            }
            getchar();
        }


    }



}
