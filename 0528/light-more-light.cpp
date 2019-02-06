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
#include <cmath>
using namespace std;

long int n;

int main() {
    while (scanf("%ld", &n) && n) {
        // if odd divisors -> light is on, even divisors -> light is off
        // square number has odd divisors
        long root = sqrt(n);
        if (root*root == n) cout << "yes" << endl;
        else cout << "no" << endl;

        // using loop in this problem cause time limit error (TLE)
        // int press = 0;
        // for (int i = 1; i <= n; i++) if (n % i) press++;

        // if (press % 2 == 0) cout << "yes" << endl;
        // else cout << "no" << endl;
    }
    return 0;
}