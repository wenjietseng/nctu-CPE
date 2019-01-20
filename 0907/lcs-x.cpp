// Brick Wall Pattern uva 900
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <iostream>
using namespace std;
#define MAXN 1000 + 5

char a[MAXN], b[MAXN];
char dp[MAXN][MAXN];

int main() {
    while (gets(a) != NULL && gets(b) != NULL) {
        int len_a = strlen(a), len_b = strlen(b);
        memset(dp, 0, sizeof(dp));

        for (int i = 1; i <= len_a; i++)
            for (int j = 1; j <= len_b; j++) {
                if (a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = dp[i][j-1] > dp[i-1][j] ? dp[i][j-1] : dp[i-1][j];
            }
        printf("%d\n", dp[len_a][len_b]);
    }
    return 0;
}

