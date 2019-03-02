// Light, more light - uva 10110

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
    long n;
    while (scanf("%ld", &n) == 1 && n) {
        long root = sqrt(n);
        if (root * root == n) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
