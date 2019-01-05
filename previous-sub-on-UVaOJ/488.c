#include<stdio.h>
int main()
{
    int n, i, j, k, amp, freq;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d %d", &amp, &freq);
        for(i = 0; i < freq; i++)
        {
            for(j = 1; j <= amp; j++)
            {
                for(k = 1; k <= j; k++)
                    printf("%d", j);
                printf("\n");
            }
            for(j = amp - 1; j >= 1; j--)
            {
                for(k = j; k >= 1; k--)
                    printf("%d", j);
                printf("\n");
            }
            printf("\n");
        }
    }
    return 0;
}
