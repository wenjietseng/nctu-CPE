// Happy number - uva 10591

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

int main() {
    int n, test_cases = 1;
    while (scanf("%d", &n) != EOF) {
        while (n--) {
            int target, happy = 0, store;
            scanf("%d", &target);
            store = target;
            while (1) {
                if (target == 1) {
                    happy = 1;
                    break;
                }
                else if (target == 4) {
                    happy = 0;
                    break;
                }
                else {
                    int out = 0;
                    while (target > 0) {
                        out += (target % 10) * (target % 10);
                        target /= 10;
                    }
                    target = out;
                }
            }
            if (happy) printf("Case #%d: %d is a Happy number.\n", test_cases++, store);
            else printf("Case #%d: %d is an Unhappy number.\n", test_cases++, store);
        }
    }
    return 0;
}