// Zeros and Ones uva 10324
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
#define MAXN 1000000 + 5
char line[MAXN];

int main() {
    int n, i, j, ans, test_case = 1;
    while (scanf("%s", line) != EOF) {
        scanf("%d", &n);
        cout << "Case " << test_case++ << ":" << endl;
        while (n--) {
            scanf("%d%d", &i, &j);
            ans = 1;
            if (i > j) {
                int tmp = i;
                i = j;
                j = tmp;
            }
            for (int k = i+1; k <= j; k++) {
                if (line[i] != line[k]) {
                    ans = 0;
                    break;
                }
            }
            printf("%s\n", ans ? "Yes" : "No");
        }
    }
    return 0;
}