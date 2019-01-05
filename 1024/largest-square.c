#include <stdio.h>

int main()
{
    int T, m, n, q, x, y, ans, i, j;
    char map[105][105];
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &m, &n, &q);
        for (i = 0; i < m; i++) {
            scanf("%s", map[i]);
        }
        printf("%d %d %d\n", m, n, q);
        while (q--) {
            scanf("%d%d", &x, &y);
            for (ans = 1; ; ans++) {
                int xx = x-ans, yy = y-ans, dx = x+ans, dy = y+ans, flag = 0; // the squate needs to check this time
                if (xx < 0 || yy < 0 || dx >= m || dy >= n) {
                    printf("%d\n", 2*ans-1);
                    break;
                }
                for (i = xx; i < xx+2*ans+1 && !flag; i++)
                    for (j = yy; j < yy+2*ans+1 && !flag; j++)
                        if (map[i][j] != map[x][y]) flag = 1;
                if (flag) {
                    printf("%d\n", 2*ans-1);
                    break;
                }
            }
        }
    }
    return 0;
}