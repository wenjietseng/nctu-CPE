#include <stdio.h>
long long kuti = 10000000, lakh = 100000, hajar = 1000, shata = 100;

void printNum(long long n)
{
    if (n >= kuti)
    {
        printNum(n / kuti);
        printf(" kuti");
        printNum(n % kuti);
    }
    else
    {
        if (n >= lakh)
        {
            printf(" %lld lakh", n / lakh);
        }
        n %= lakh;

        if (n >= hajar)
        {
            printf(" %lld hajar", n / hajar);
        }
        n %= hajar;

        if (n >= shata)
        {
            printf(" %lld shata", n / shata);
        }
        n %= shata;
        if (n >= 0LL)
        {
            printf(" %lld", n);
        }
    }
}

int main()
{
    long long n;
    int case_no = 1;
    while (scanf("%lld", &n) != EOF)
    {
        printf("%d.", case_no++);
        printNum(n);
        if (n == 0LL)
            printf(" 0");
        printf("\n");
    }
    return 0;
}
