// Dollars uva 147
#include<stdio.h>
#include<string.h>

int main() {
    int money[] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
    unsigned long long dp[30001] = {0};
    dp[0] = 1;
    int i, j;
    for (i = 0; i < 11; i++) {
        for (j = money[i]; j < 30001; j += 5) {
            dp[j] += dp[j-money[i]];
        }
    }

    int dollar, cent;
    while(scanf("%d.%d", &dollar, &cent) != EOF) {
        if (dollar == 0 && cent == 0) break;
        printf("%3d.%02d%17llu\n", dollar, cent, dp[dollar*100+cent]);
    }
    return 0;
}