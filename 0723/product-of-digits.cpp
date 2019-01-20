// uva 993 Products of digits
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



int main() {
    int num, N;
    scanf("%d", &num);
    while (num--) {
        int digits[10];
        memset(digits, 0, sizeof(digits));
        scanf("%d", &N);
        if (N == 1) printf("1\n");
        else {
            for (int i = 9; i > 1 && N > 1; i--) {
                while (N % i == 0) {
                    N /= i;
                    digits[i] += 1;
                }
            }
            if (N != 1) printf("-1\n");
            else {
                for (int i = 2; i <= 9; i++)
                    for (int j = 0; j < digits[i]; j++)
                        printf("%d", i);
                printf("\n");
            }
        }
    }
    return 0;
}