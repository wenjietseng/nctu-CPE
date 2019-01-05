#include <stdio.h>

int main()
{
    long int a, b;
    while (scanf("%lu %lu", &a, &b) && a != 0 && b != 0)
    {
        int carry = 0, count = 0;
        while (a || b)
        {
            carry = (carry + a % 10 + b % 10) / 10;
            a /= 10;
            b /= 10;
            if (carry) count++;
        }
        if (!count) printf("No carry operation.\n");
        else if (count == 1) printf("1 carry operation.\n");
        else printf("%d carry operations.\n", count);
    }
    return 0;
}
