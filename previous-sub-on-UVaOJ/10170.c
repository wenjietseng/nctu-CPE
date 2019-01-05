#include <stdio.h>

int main()
{
    long long S, D;
    while (scanf("%lld %lld", &S, &D) == 2)
    {
        long long i = S, sum = 0;
        while (1)
        {
            sum += i;
            if (sum >= D)
            {
                printf("%lld\n", i);
                break;
            }
            i++;
        }
    }
    return 0;
}
