#include <stdio.h>
#include <string.h>
#define MAXN 25
char grid[MAXN][MAXN];
int visited[MAXN][MAXN];
int h, w;
int country_table[30];

void dfs(int r, int c, char lang);

int main() {
    int t, i, j, t_idx = 1;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &h, &w);
        for (i = 0; i < h; i++) scanf("%s", grid[i]);
        
        memset(visited, 0, sizeof(visited));
        memset(country_table, 0, sizeof(country_table));

        for (i = 0; i < h; i++) {
            for (j = 0; j < w; j++) {
                if (visited[i][j] == 0) {
                    dfs(i, j, grid[i][j]);
                    int idx = grid[i][j] - 'a';
                    country_table[idx] += 1;
                }
            }
        }

        printf("World #%d\n", t_idx++);
        int max = 0;
        for (i = 0; i < 26; i++) {
            if (country_table[i] > max) max = country_table[i];
        }
        while (max) {
            for (i = 0; i < 26; i++) {
                if (country_table[i] == max) printf("%c: %d\n", 'a'+i,country_table[i]);
            }
            max--;
        }
        // for (i = 0; i < 26; i++) {
        //     printf("%c: %d\n", 'a'+i,country_table[i]);
        // }
    }
    return 0;
}

void dfs(int r, int c, char lang) {
    int s, t;
    if (r < 0 || r >= h || c < 0 || c >= w) return;
    if (visited[r][c] > 0 || grid[r][c] != lang) return;
    visited[r][c] = 1;
    for (s = -1; s <= 1; s++) {
        if (s != 0) dfs(r+s, c, lang);
    }
    for (t = -1; t <= 1; t++) {
        if (t != 0) dfs(r, c+t, lang);
    }
}