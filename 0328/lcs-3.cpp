// LCS - uva 10405

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
#define MAXN 1000
char a[MAXN + 5], b[MAXN + 5];
int lcs[MAXN + 5][MAXN + 5];

int main() {
    while (gets(a) != NULL && gets(b) != NULL) {
        int len_a = strlen(a), len_b = strlen(b);
        memset(lcs, 0, sizeof(lcs));
        

        for (int i = 1; i <= len_a; i++) {
            for (int j = 1; j <= len_b; j++) {
                if (a[i-1] == b[j-1]) lcs[i][j] = lcs[i-1][j-1] + 1;
                else lcs[i][j] = lcs[i-1][j] > lcs[i][j-1] ? lcs[i-1][j] : lcs[i][j-1];
            }
        }

        printf("%d\n", lcs[len_a][len_b]);
    }

    return 0;
}