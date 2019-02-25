// Sum of consecutive primes - uva 1210

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
#define MAXN 10000 + 5
int prime[MAXN], visit[MAXN];

int find_primes() {
    int count = 0;
    for (int i = 2; i < MAXN; i++) {
        if (!visit[i]) {
            prime[count++] = i;
            for (int j = i+i; j < MAXN; j += i) visit[j] = 1;
        }
    }
    return count;
}

int main() {
    memset(prime, 0, sizeof(prime));
    memset(visit, 0, sizeof(visit));
    int prime_count = find_primes();
    int n;
    while (scanf("%d", &n) != EOF && n) {
        int l = 0, r = 0, ans = 0, sum = 0;
        for (r = 0; n >= prime[r]; r++) {
            sum += prime[r];
            while (sum > n) sum -= prime[l++];
            if (sum == n) ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}