#include <stdio.h>

int main() {
    int N; 
    while (scanf("%d", &N) != EOF) {
        int sum = 0, emp = 0;
        while (N + emp > 2) {
            sum += N;
            emp += N;
            N = emp / 3;
            emp %= 3;
        }
        sum += N;
        if (N + emp == 2) printf("%d\n", sum + 1);
        else printf("%d\n", sum);
    }
    return 0;
}