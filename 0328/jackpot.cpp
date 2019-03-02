// The jackpot - uva 10684

// C libraries
#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>

// C++ libraries
#include <iostream>
#include <string>
// STL libraries
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <stack>
// namespace
using namespace std;

// define marcos
#define MAXN 10000
int nums[MAXN + 5], dp[MAXN + 5];

int main() {
    int n;
    while (scanf("%d", &n) == 1 && n) {
        for (int i = 1; i <= n; i++) scanf("%d", &nums[i]);

        int win = 0;
        for (int i = 1; i <= n; i++) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            win = max(win, dp[i]);
        }

        if (win > 0) printf("The maximum winning streak is %d.\n", win);
        else printf("Losing streak.\n");
    }

    return 0;
}