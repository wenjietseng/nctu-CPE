// Common permutation uva 10252
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <iostream>
using namespace std;
#define MAXN 1000

char a[MAXN+5], b[MAXN+5];

int main() {
    while (gets(a) != NULL && gets(b) != NULL) {
        int len_a = strlen(a), len_b = strlen(b);
        sort(a, a+len_a);
        sort(b, b+len_b);

        for (int i = 0, j =0; i < len_a && j < len_b;) {
            if (a[i] == b[j]) {
                printf("%c", a[i]);
                i++, j++;
            }
            else if (a[i] > b[j]) j++;
            else i++;
        }
        printf("\n");
    }
    return 0;
}