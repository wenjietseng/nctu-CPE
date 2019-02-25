// Exact sum - uva 11057

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
int prices[MAXN];

int main() {
    int n = 0;
    while (scanf("%d", &n) != EOF) {
        int target = 0;
        for (int i = 0; i < n; i++) scanf("%d", &prices[i]);
        scanf("%d", &target);

        sort(prices, prices + n);
        // int mid = lower_bound(prices, prices+n, target/2) - prices;
        // printf("%d\n", mid);
        int mid;
        for (int i = 0; i < n; i++) {
            if (prices[i] >= target/2) {
                mid = i;
                break;
            }
        }

        bool flag = true;

        for (; flag && (prices[mid] <= target); mid++)
            for (int i = 1; i <= mid; i++) 
                if ((prices[mid] + prices[mid - i]) == target) {
                    printf("Peter should buy books whose prices are %d and %d.\n\n", prices[mid-i], prices[mid]);
                    flag = false;
                    break;
                }
    }
    return 0;
}