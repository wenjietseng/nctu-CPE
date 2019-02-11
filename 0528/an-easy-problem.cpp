// uva 10093 An easy problem!
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


// 在10進位下，一個數若是9的倍數，則這個數字的每個位數相加的總和一定也是9的倍數;
// 舉個例子，81(10-based)，8+1=9，9%9==0 -> 是9的倍數  ;
// 依此原則推出:
// 當這個數字R的每個位數總和=sum，而sum是n的倍數，
// 則 N=n+1;
// ref: http://hanting1225.blogspot.com/2015/02/uva-10093-easy-problem.html


int main() {
    char input[100];
    while(~scanf("%s", input)) {
        int sum = 0, Max = 1;
        for (int i = 0; i < strlen(input); i++) {
            char c = input[i];
            int R = 0;
            if ('0' <= c && c <= '9') R = c - '0';
            else if ('A' <= c && c <= 'Z') R = c - 'A' + 10;
            else if ('a' <= c && c <= 'z') R = c - 'a' + 36;
            sum += R;
            if (R > Max) Max = R;
        }
        for (int i = Max; i <= 62; i++) {
            if (sum % i == 0) {
                cout << i+1 << endl;
                break;
            }
            else if (i == 62) cout << "such number is impossible!" << endl;
        }
    }
    return 0;
}