// Bit mask - uva 10718

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
#define BIT(i) (1L << i)
#define AND(x, i) (x & BIT(i))
#define OR(x, i) (x | BIT(i))

int main() {
    long long int n, l, u, ans;
    while (scanf("%lld%lld%lld", &n, &l, &u) != EOF) {
        ans = 0;
        for (int i = 31; i >= 0; i--) 
            if (OR(ans, i) <= (AND(n, i) ? l : u)) ans |= BIT(i);
        printf("%lld\n", ans);

    }
    return 0;
}