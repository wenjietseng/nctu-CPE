// Vito's Family
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

int testcases, r, vito;

int main() {
    scanf("%d", &testcases);
    while (testcases--) {
        scanf("%d", &r);
        int dists[r+5];
        for (int i = 0; i < r; i++) scanf("%d", &dists[i]);
        sort(dists, dists+r);
        if (r % 2 == 1) vito = dists[r/2];
        else vito = (dists[r/2-1] + dists[r/2]) / 2 ;

        int sum = 0;
        for (int i = 0; i < r; i++) sum += abs(vito-dists[i]);
        cout << sum << endl;
    }
    return 0;
}