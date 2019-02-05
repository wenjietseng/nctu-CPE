// uva 10110 Light, more light
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

unsigned long long int n;

int main() {
    while (scanf("%llu", &n) && n) {
        int press = 0;
        for (int i = 1; i <= n; i++) if (n % i) press++;

        if (press % 2 == 0) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}