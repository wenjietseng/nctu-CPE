#include <stdio.h>
#define BIT(i) (1LL << i)
#define OR(x, i) (x | BIT(i))
#define AND(x, i) (x & BIT(i))

int main()
{
    long long int n, l, u, ans, i;
    while (scanf("%lld%lld%lld", &n, &l, &u) != EOF) {
        ans = 0;
        for (i = 31; i >=0; i--)
            if (OR(ans, i) <= (AND(n, i) ? l : u)) ans |= BIT(i);
        printf("%lld\n", ans);
    }
    return 0;
}