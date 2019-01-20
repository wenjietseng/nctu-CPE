// Extend to Palindromes uva 11475
// https://timbian.wordpress.com/2015/02/23/uva-11475-extend-to-palindrome/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <iostream>
using namespace std;


#define MAXN 100000
int f[MAXN + 10];

void failure(char *P) {
    int i, j;
    f[0] = -1;
    for (i = 1, j = -1; P[i]; i++) {
        while (j >= 0 && P[j+1] != P[i]) {
            j = f[j];
        }
        if (P[j+1] == P[i]) j++;
        f[i] = j;
    }
}
int KMP(char *S, char *P) {
    int i, j;
    failure(P);
    for (i = 0, j = -1; S[i]; i++) {
        while (j >= 0 && P[j+1] != S[i]) j = f[j];
        if (P[j+1] == S[i]) j++;
    }
    return j;
}
int main() {
    char S[MAXN + 10];
    char P[MAXN + 10];
    int i, j, len, cut;
    while (scanf("%s", S) != EOF) {
        len = strlen(S);

        for (i = 0, j = len - 1; i <= len - 1; i++, j--) {
            P[i] = S[j];
        }
        P[len] = '\0';
        cut = KMP(S, P);
        printf("%s", S);
        for (i = cut + 1; i <= len - 1; i++) {
            printf("%c", P[i]);
        }
        printf("\n");
    }
    return 0;
}