#include <stdio.h>
#include <string.h>
#include <ctype.h>
char grid[55][55], word[100];

int dRow[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dCol[] = {-1, 0, 1, -1, 1, -1, 0, 1};

typedef struct
{
    int x, y;
} pos;

pos loc;

int check_match(int m, int n, char word[])
{
    int i, k, len = strlen(word);
    for (i = 0; i < 8; i++)
    {
        for (k = 0; k < len; k++)
        {
            int x = loc.x, y = loc.y;
            if (x < 1 || x > m || y < 1 || y > n) break;
            if (grid[x][y] != word[k]) break;
            x += dRow[i];
            y += dCol[i];
        }
        if (k == len - 1) return 1;
    }
    return 0;
}

void find_first(int m, int n, char word[])
{
    int i, j;
    for (i = 1; i <= m; i++)
    { 
        for (j = 1; j <= n; j++)
        {
            if (grid[i][j] == word[0])
            {
                loc.x = i;
                loc.y = j;
                if (check_match(m, n, word)) printf("%d %d\n", loc.x, loc.y);
            }
        }
    }
}


int main()
{
    /*  0. read input
        1. upper to lower
        2. for each word
        3.     find_first
        4.         check_match
        5.             print output
    */
    int Case;
    scanf("%d", &Case);
    while(Case--)
    {
        int m, n, k, i, j, len;
        getchar();
        scanf("%d %d\n", &m, &n);
        for (i = 1; i <= m; i++)
        {
            for (j = 1; j <= n; j++)
            {
                grid[i][j] = getchar();
                if (isupper(grid[i][j])) grid[i][j] = tolower(grid[i][j]);
            }
            getchar();
        }
        scanf("%d\n", &k);
        for (i = 0; i < k; i++)
        {
            scanf("%s\n", word);
            len = strlen(word);
            for (j = 0; j < len; j++)
                if (isupper(word[j])) word[j] = tolower(word[j]);
            find_first(m, n, word);
        }
        printf("\n");
    }
    return 0;
}
