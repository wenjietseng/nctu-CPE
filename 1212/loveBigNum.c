// I love big numbers - uva 10220
#include <stdio.h>
int fact[1001][2600] = {}, ans[1001] = {};

void build_fact(int P[][2600]) {
    int i, j, last = 0;
    P[0][0] = 0, ans[0] = 0;
    P[1][0] = 1, ans[1] = 1;
    for (i = 2; i <= 1000; i++) {
        for (j = 0; j <= last; j++) {
            P[i][j] *= P[i-1][j]*i;
            if (P[i][j] >= 10) {
                P[i][j+1] += P[i][j]/10;
                P[i][j] %= 10;
                if (j+1 > last) last = j+1;
            }
            ans[i] += P[i][j];
        }
    }
}

int main() {
    build_fact(fact);
    int n;
    while (scanf("%d", &n) != EOF) printf("%d\n", ans[n]);
    return 0;
}
