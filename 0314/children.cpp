// Children 's game - uva 10905

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

bool cmp(string a, string b) {
    return (a+b) > (b+a);
}

int main() {
    int n = 0;
    while (scanf("%d", &n) == 1 && n) {
        vector<string> nums;
        string tmp;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            nums.push_back(tmp);
        }
        sort(nums.begin(), nums.end(), cmp);
        for (int i = 0; i < n; i++) cout << nums[i];
        cout << endl;
    }

    return 0;
}