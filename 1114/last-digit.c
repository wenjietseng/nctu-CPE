#include <stdio.h>
#include <string.h>
#define MAXN 2000
char input[MAXN];
int map[20] = {0, 1, 5, 2, 8, 3, 9, 2, 8, 7,
               7, 8, 4, 7, 3, 8, 4, 1, 5, 4};

int main() {
    while (scanf("%s", input) !=EOF) {
        int len = strlen(input);
        if (input[0] == '0' && input[1] == '\0') break;
        int value = input[len - 1] - '0';
        if (len > 1) value += (input[len - 2] - '0') * 10;
        printf("%d\n", (map[value%20] + value/20*4)%10);
    }
    return 0;
}