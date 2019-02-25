// Guard the night - uva 11639

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
#define MIN(x,y) ((x) < (y) ? (x) : (y))
#define MAX(x,y) ((x) > (y) ? (x) : (y))

struct Guard {
    int x1, y1, x2, y2;
};
int n, nights = 1;
int strong, weak, unsecured;

int main() {
    scanf("%d", &n);
    while (n--) {
        Guard first, second;
        scanf("%d%d%d%d", &first.x1, &first.y1, &first.x2, &first.y2);
        scanf("%d%d%d%d", &second.x1, &second.y1, &second.x2, &second.y2);
        int p, q, r, s, A, B, C;
        p = MAX(first.x1, second.x1);
        q = MAX(first.y1, second.y1);
        r = MIN(first.x2, second.x2);
        s = MIN(first.y2, second.y2);
        A = (first.x2 - first.x1) * (first.y2 - first.y1);
        B = (second.x2 - second.x1) * (second.y2 - second.y1);
        C = (p - r) * (q - s);

        printf("Night %d: ", nights++);
        if (p >= r || q >= s) printf("0 %d %d\n", A + B, 10000 - A - B);
        else printf("%d %d %d\n", C, A + B - 2 * C, 10000 - A - B + C);
    }
    return 0;
}