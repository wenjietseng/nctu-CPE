#include <stdio.h>
#include <string.h>
#define MAXN 1000005

int main() {
    int n, m, i, j, ms[20], dp[MAXN];
    while (scanf("%d %d", &n, &m) == 2) {
        memset(ms, 0, sizeof(ms));
        memset(dp, 0, sizeof(dp));        
        for (i = 0; i < m; i++) {
            scanf("%d", &ms[i]);
        }

        // dp
        for (i = 1; i <= n; i++) {
            for (j = 0; j < m; j++) {
                if (i - ms[j] >= 0 && !dp[i - ms[j]]) {
                    dp[i] = 1;
                    break;
                }
            }
        }

        printf("%s\n", dp[n] ? "Stan wins" : "Ollie wins");
    }
    return 0;
}