// A mid-summer night’s dream - uva 10057

// C libraries
#include <cstdio>
#include <cstring>
#include <cmath>

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
#define MAXN 1000000
int nums[MAXN];

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        memset(nums, 0, sizeof(nums));
        int med_counts = 0;
        for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
        sort(nums, nums + n);
        int M = nums[n/2];
        int m = nums[(n-1)/2];
        for (int i = 0; i < n; i++) if (M == nums[i] || m == nums[i]) med_counts++;
        printf("%d %d %d\n", m, med_counts, M-m+1);
    }
    return 0;
}