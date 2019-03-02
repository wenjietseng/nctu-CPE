// Maja Bee - uva 10182

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
#define MAXN 100000

struct Point {
    int x, y;
};

struct Point maja[MAXN+5];
int idx = 0;
void create()
{
    maja[1].x = 0, maja[1].y = 0;
    idx = 1;
    int nowI = 0, nowJ = 0, num;
    for (num = 1; idx <= MAXN; num++)
    {
        for (int count = 0; count < num && idx <= MAXN; count++, idx++)
            maja[idx].x = nowI, maja[idx].y = nowJ++;
        for (int count = 0; count < num-1 && idx <= MAXN; count++, idx++)
            maja[idx].x = nowI--, maja[idx].y = nowJ++;
        for (int count = 0; count < num && idx <= MAXN; count++, idx++)
            maja[idx].x = nowI--, maja[idx].y = nowJ;
        for (int count = 0; count < num && idx <= MAXN; count++, idx++)
            maja[idx].x = nowI, maja[idx].y = nowJ--;
        for (int count = 0; count < num && idx <= MAXN; count++, idx++)
            maja[idx].x = nowI++, maja[idx].y = nowJ--;
        for (int count = 0; count < num && idx <= MAXN; count++, idx++)
            maja[idx].x = nowI++, maja[idx].y = nowJ;
    }

}


int main()
{
    create();
    // for (int i = 1; i < 20; i++) printf("%d %d\n", maja[i].x, maja[i].y);
    int willi = 0;
    while (scanf("%d", &willi) != EOF)
    {
        printf("%d %d\n", maja[willi].x, maja[willi].y);
    }

    return 0;
}