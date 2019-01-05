#include <stdio.h>

long long int factorial(long long int n)
{
    /* positive input and 0 */
    if (n == 0) return 1;
    else return n * factorial(n - 1);
}

int main()
{
    long long int n, fac_out;
    while (scanf("%lli", &n) != EOF)
    {

        /* negative input */
        if (n < 0)
        {
            if ((n % 2) == 1) printf("Overflow!\n");
            else printf("Underflow!\n");
        }
        else
        {
            fac_out = factorial(n);
            if (fac_out < 10000) printf("Underflow!\n");
            else if (fac_out > 6227020800) printf("Overflow!\n");
            else printf("%lli\n", fac_out);
        }
    }
    return 0;
}