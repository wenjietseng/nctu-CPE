// All you need is love - uva 10193

// C libraries
#include <cstdio>
#include <cstring>
#include <cmath>

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

int binary_string_to_int(char *str) {
    int out = 0;
    for (int i = 0; i < strlen(str); i++) {
        out <<= 1;
        out += str[i] - '0';
    }
    return out;
}

int gcd(int a, int b) {
    // int out = 0;
    // for (int i = 1; i <= a && i <= b; i++) if (a % i == 0 && b % i == 0) out = i;
    // return out;
    if(a == 0 || b == 0) return a + b;
    while((a %= b) != 0 && (b %= a) != 0);
    return a + b;
}

int main() {
    int n = 0, test_cases = 1;
    scanf("%d", &n);
    while (n--) {
        char a[32], b[32];
        scanf("%s", a);
        scanf("%s", b);

        int num_a = binary_string_to_int(a);
        int num_b = binary_string_to_int(b);
        // cout << num_a << "," << num_b << endl;
        if (gcd(num_a, num_b) != 1) cout << "Pair #" << test_cases++ << ": All you need is love!" << endl;
        else cout << "Pair #" << test_cases++ << ": Love is not all you need!" << endl; 
    }
    return 0;
}