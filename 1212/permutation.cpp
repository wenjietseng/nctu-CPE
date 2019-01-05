#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAXN 1005

int main() {
    char a[MAXN], b[MAXN];
    while (gets(a) != NULL && gets(b) != NULL) {
    // while (fgets(a, sizeof(a), stdin) != NULL && fgets(b, sizeof(b), stdin) != NULL) {
        std::sort(a, a + strlen(a));
        std::sort(b, b + strlen(b));
        //printf("%s\n%s\n", a, b);
        for (int i = 0, j = 0; i < strlen(a) && j < strlen(b);) {
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