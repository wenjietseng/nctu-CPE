// Unique Lines
// http://natetang.tw/2018/02/01/2009-24unique-lines/
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

typedef struct Point {
    int x, y;
} p;

double find_slope(int x1, int y1, int x2, int y2) {
    return (double) (y2-y1) / (double) (x2-x1);
}

int main() {
    int test_case, n;
    scanf("%d", &test_case);
    while (test_case--) {
        scanf("%d", &n);
        vector<p> points(n);
        vector<double> slopes(n*(n-1)/2);
        while (n--) {
            int i = 0, a, b;
            scanf("%d%d", &a, &b);
            points[i].x = a;
            points[i].y = b;
        }
        int k = 0;
        for (int i = 0; i < points.size(); i++) 
            for (int j = i+1; j < points.size(); j++)
                slopes[k++] = find_slope(points[i].x, points[i].y, points[j].x, points[j].y);
        
        sort(slopes.begin(), slopes.end());
        int ans = 1;
        for (int i = 0; i < slopes.size(); i++) {
            if (slopes[i] != slopes[i+1]) ans++;
            cout << slopes[i] << endl;
        }
        cout << ans << endl;
    }
    return 0;
}