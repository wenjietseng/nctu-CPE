// Longest Increasing Subsequence Leetcode
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <iostream>
using namespace std;
#define MAXN 65535

int input[MAXN + 5], LIS[MAXN + 5];

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        // special case
        if (n == 0) {cout << 0 << endl; break;}
        if (n == 1) {cout << 1 << endl; break;}

        memset(input, 0, sizeof(input));
        // initialize, every number is its LIS with length 1
        memset(LIS, 0, sizeof(LIS));
        for (int i = 0; i < n; i++) LIS[i] = 1;
        
        for (int i = 0; i < n; i++) scanf("%d", &input[i]);

        // find LIS
        for (int i = 0; i < n; i++) {
            // LIS[i] = 1;
            for (int j = i+1; j < n; j++) 
                if (input[i] < input[j] && LIS[i] + 1 > LIS[j]) LIS[j] = LIS[i] + 1;
            // for check
            // for (int i = 0; i < n; i++) printf("%d ", LIS[i]);
            // printf("\n");
        }

        int ans = 0;
        for (int i = 0; i < n; i++) 
            ans = max(ans, LIS[i]);
        cout << ans << endl;
    }
    return 0;
}