// Quirksome Squares - uva 256
// ref: http://naivered.github.io/2016/09/10/Problem_Solving/UVa/UVa-256-Quirksome-Squares/
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



int main() {
    int ans[4][10], count[4] = {};
    int div[4] = {10, 100, 1000, 10000};
    int n = 0;
    for (int i = 0; i < 10000; i++) {
        int square = i * i;
        for (int j = 0; j < 4; j++) {
            if (i < div[j]) {
                int x = square / div[j] + square % div[j];
                if (x == i) ans[j][count[j]++] = square;
            }
        }
    }
    while (scanf("%d", &n) != EOF) {
        int idx = n / 2 - 1;
        for (int i = 0; i < count[idx]; i++)
            printf("%0*d\n", n, ans[idx][i]);
    }
    return 0;
}