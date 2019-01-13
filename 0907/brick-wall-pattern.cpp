// Brick Wall Pattern uva 900
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

// guess fibonacci series

unsigned long long fibs[55];

void compute_fib() {
    memset(fibs, 0, sizeof(fibs));
    fibs[0] = 1;
    fibs[1] = 1;
    for (int i = 2; i < 55; i++) fibs[i] = fibs[i-1] + fibs[i-2];
}



int main() {
    int n;
    compute_fib();
    while (scanf("%d", &n) == 1 && n) {
        cout << fibs[n] << endl;
    }
    return 0;
}