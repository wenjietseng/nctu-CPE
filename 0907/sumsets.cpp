// Sum sets - uva 10125

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
#define MAXN 1000 + 5
int input[MAXN], n;

int find() {
    for (int d = n-1; d >= 0; d--)
        for (int a = 0; a < n; a++)
            for (int b = a+1; b < n; b++)
                for (int c = b+1; c < n; c++)
                    if (input[a] + input[b] + input[c] == input[d] &&
                        a != d && b != d && c != d) return input[d];
    return INT_MAX;
}


int main() {

    while(scanf("%d", &n) != EOF && n) {
        for (int i = 0; i < n; i++) scanf("%d", &input[i]);

        sort(input, input + n);
        int ans = find();

        if (ans == INT_MAX) printf("no solution\n");
        else printf("%d\n", ans);
    }
    return 0;
}