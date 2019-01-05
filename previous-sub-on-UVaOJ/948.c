#include <stdio.h>

int main()
{
    int fib_arr[39];
    fib_arr[0] = 1, fib_arr[1] = 2;
    int i = 2;
    while (i < 39)
    {
        fib_arr[i] = fib_arr[i - 2] + fib_arr[i - 1];
        i++;
    }
    int n;
    scanf("%d", &n);
    while (n--)
    {
        int dec, mark;
        scanf("%d", &dec);
        mark = dec;
        printf("%d = ", dec);
        for (i = 38; i >= 0; i--)
        {
            if (dec == 0) break;
            if (dec - fib_arr[i] < 0)
            {
                if (dec < mark) printf("0");
                else continue;
            }
            else
            {
                dec -= fib_arr[i];
                printf("1");
            }
        } 
        while (i >= 0)
        {
            printf("0");
            i--;
        }
        printf(" (fib)\n");
    }
    return 0;
}
