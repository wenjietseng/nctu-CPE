#include <stdio.h>
#include <string.h>
#define maxn 105
char grid[maxn][maxn];
int visited[maxn][maxn];
int m, n, ans;

void dfs(int r, int c, int pocket_num);

int main() {
    int i, j;

    while ((scanf("%d %d", &m, &n) == 2 && m && n)) {
        // read input
        for (i = 0; i < m; i++) scanf("%s", grid[i]);
        // initialize visited array (use memset!)
        memset(visited, 0, sizeof(visited));
        ans = 0;

        // apply dfs until every grid has been visited
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                if (visited[i][j] == 0 && grid[i][j] == '@') dfs(i, j, ++ans);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

void dfs(int r, int c, int pocket_num) {
    int s, t;
    if (r < 0 || r >= m || c < 0 || c >= n) return; // check boarder
    if (visited[r][c] > 0 || grid[r][c] != '@') return; // check visited and has no oil
    visited[r][c] = pocket_num;
    for (s = -1; s <= 1; s++) {
        for (t = -1; t <= 1; t++) {
            if (s != 0 || t != 0) dfs(r+s, c+t, pocket_num);
        }
    }
}