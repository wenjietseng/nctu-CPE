// Prefix expression evaluation

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
#define MAXN 1024 + 10
char line[MAXN];

int main() {
    while (fgets(line, MAXN, stdin) != NULL && line[0] != '.') {
        int len = strlen(line) - 1;
        int illegal = 0;
        // vector<char> op;
        vector<int> nums;
        for (int i = len-1; i >= 0; i--) {
            if (line[i] == '+' || line[i] == '-' || line[i] == '*' || line[i] == '/' || line[i] == '%') {
                // calculate
                int out = 0, a = 0, b = 0;
                char c = line[i];
                a = nums.back();
                if (nums.empty()) {
                    illegal = 1;
                    break;
                }
                nums.pop_back();

                b = nums.back();
                if (nums.empty()) {
                    illegal = 1;
                    break;
                }
                nums.pop_back();
                
                if (c == '+') out = a + b;
                else if (c == '-') out = a - b;
                else if (c == '*') out = a * b;
                else if (c == '/') out = a / b;
                else if (c == '%') out = a % b;
                // cout << out << endl;
                nums.push_back(out);
            }
            else if (line[i] >= '0' && line[i] <= '9') {
                int tmp = 0, power = 1;
                while (line[i] != ' ' && line[i] != '\n') {
                    tmp = tmp + (line[i] - '0') * power;
                    power *= 10;
                    i--;
                }
                // cout << tmp << endl;
                nums.push_back(tmp);
            }
            else if (line[i] == ' ' || line[i] == '\n') continue;
        }

        if (illegal) printf("illegal\n");
        else cout << nums.back() << endl;
        // for (int i = 0; i < nums.size(); i++) {
            // cout << nums[i] << endl;
        // }
        // for (int i = 0; i < op.size(); i++) {
            // cout << op[i] << endl;
        // }
    }
    return 0;
}