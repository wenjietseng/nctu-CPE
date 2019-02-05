// last digit uva 10162
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <iostream>
using namespace std;

char input[2000];
int maps[20] = {0, 1, 5, 2, 8, 3, 9, 2, 8, 7,
               7, 8, 4, 7, 3, 8, 4, 1, 5, 4};

int main() {
    while(scanf("%s", input) != EOF) {
        int len = strlen(input);
        if (input[0] == '0' && input[1] == '\0') break;
        int val = input[len-1] - '0';
        if (len > 1) val += (input[len - 2] - '0') * 10;
        printf("%d\n", (maps[val%20] + val/20*4)%10);
    }
    return 0;
}