// Luggage - uva 10664

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
int m = 0, weights[25], dp[202];


int main() {
    scanf("%d", &m);
    getchar();
    while (m--) {
        int num = 0, sum = 0, n = 0;
        while (1) {
            char c = getchar();
            if (c >= '0' && c <= '9') num = num * 10 + (c - '0');
            else {
                weights[n++] = num;
                sum += num;
                num = 0;
                if (c == '\n') break;
            }
        }
        // for (int i = 0; i < n; i++) cout << weights[i] << endl;
        // cout << sum << endl;

        if (sum % 2 == 1 || n == 1) cout << "NO" << endl;
        else {
            // dp
            memset(dp, 0, sizeof(dp));
            dp[0] = 1;
            sum /= 2;
            for (int i = 0; i < n; i++)
                for (int j = sum; j >= weights[i]; j--)
                    if (dp[j-weights[i]]) dp[j] = 1;
            
        
            if (dp[sum] == 1) cout << "Yes" << endl;
            else cout << "NO" << endl;    
        }
    }
    return 0;
}