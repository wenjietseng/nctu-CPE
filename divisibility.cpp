// Divisibility uva 10036
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

#define FOR(i, a, b) for (int i = a, _n=(b); i <= _n; i++)
#define clr(x, v) memset(x, v, sizeof(x))
#define N 105
#define P(x) ((x-1)&1)
#define C(x) (x&1)

int t, n, k;
int seq[10005];
bool dp[2][N];


int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &k);
        FOR(i, 1, n) scanf("%d", &seq[i]);

        // solve
        clr(dp, false);
        dp[0][0] = true;
        // http://mobcs.blogspot.com/2015/03/uva-10036-divisibility.html
    }
}