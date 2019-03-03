// Love big num - uva 10220

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
#define MAXN 1000
int fact_out[1001][3000] = {}, ans[1001] = {};

void create_table(int fact[][3000]) {
    int last = 1;
    fact[0][0] = 0; ans[0] = 0;
    fact[1][0] = 1; ans[1] = 1;
    for (int i = 2; i <= 1000; i++) {
        for (int j = 0; j <= last; j++) {
            fact[i][j] += fact[i-1][j] * i;
            if (fact[i][j] >= 10) {
                fact[i][j+1] += fact[i][j] / 10;
                fact[i][j] %= 10;
                if (j+1 > last) last = j+1; 
            }
            ans[i] += fact[i][j];
        }
    }
}

int main() {
    create_table(fact_out);
    int n;
    while (scanf("%d", &n) != EOF) printf("%d\n", ans[n]);
    return 0;
}