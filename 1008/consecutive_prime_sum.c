#include <stdio.h>
#include <string.h>
#define MAXN 10010
int prime[MAXN], visit[MAXN];
int prime_count, i, j;

int find_primes() {
    int count = 0;
    for (i = 2; i < MAXN; i++) {
        if (!visit[i]) {
            prime[count++] = i;
            for (j = i+i; j < MAXN; j += i) visit[j] = 1;
        }
    }
    return count;
}

int main() {
    memset(prime, 0, sizeof(prime));
    memset(visit, 0, sizeof(visit));
    int prime_count = find_primes();
    int n;
    while (scanf("%d", &n) != EOF && n) {
        int l = 0, r = 0, ans = 0, sum = 0;
        for (r = 0; n >= prime[r]; r++) {
            sum += prime[r];
            while (sum > n) sum -= prime[l++];
            if (sum == n) ans++;
        }
        printf("%d\n", ans);
    }
    // for (i = 0; i < prime_count; i++) printf("%d\n", prime[i]);
    // printf("prime_count = %d\n", prime_count);
    return 0;
}