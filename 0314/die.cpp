// Die game - uva 10409

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
    int n = 0;
    char direction[10];
    while (scanf("%d", &n) == 1 && n) {
        int top = 1, north = 2, west = 3, east = 4, south = 5, down = 6;
        while (n--) {
            scanf("%s", direction);
            int tmp;
            if (direction[0] == 'n') {
                tmp = top;
                top = south;
                south = down;
                down = north;
                north = tmp;
            }
            else if (direction[0] == 'e') {
                tmp = top;
                top = west;
                west = down;
                down = east;
                east = tmp;
            }
            else if (direction[0] == 'w') {
                tmp = top;
                top = east;
                east = down;
                down = west;
                west = tmp;
            }
            else if (direction[0] == 's') {
                tmp = top;
                top = north;
                north = down;
                down = south;
                south = tmp;
            }
            // printf("%d %d %d %d %d %d\n", top, north, west, east, south, down);
        }
        printf("%d\n", top);
    }
    return 0;
}

