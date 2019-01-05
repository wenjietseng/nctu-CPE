#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 1005

int main() {
    char s1[MAXN], s2[MAXN];
    int LCS[MAXN][MAXN];
    while (gets(s1) != NULL && gets(s2) != NULL) {
        memset(LCS, 0, sizeof(LCS));
        for (int i = 1; i <= strlen(s1); i++) {
            for (int j = 1; j <= strlen(s2); j++) {
                if (s1[i-1] == s2[j-1]) LCS[i][j] = LCS[i-1][j-1] + 1;
                else LCS[i][j] = LCS[i][j-1] > LCS[i-1][j] ? LCS[i][j-1] : LCS[i-1][j];
            }
        }
        printf("%d\n", LCS[strlen(s1)][strlen(s2)]);
    }
    return 0;
}