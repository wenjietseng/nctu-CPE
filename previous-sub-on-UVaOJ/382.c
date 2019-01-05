#include <stdio.h>

int main()
{
    int num, first = 1;
    while (scanf("%d", &num) == 1)
    {
        if (num == 0) break;
        while (1)
        {
            if (first)
            {
                printf("PERFECTION OUTPUT\n");
                first = 0;
            }
            int i, sum_of_proper_div = 0;
            for (i = 1; i <= (num / 2); i++)
            {
                if ((num % i) == 0) sum_of_proper_div += i;
            }
            printf("%5d  ", num);
            if (num == sum_of_proper_div) printf("PERFECT");
            else if (num > sum_of_proper_div) printf("DEFICIENT");
            else printf("ABUNDANT");
            printf("\n");
            break;
        }
    }
    printf("END OF OUTPUT\n");
    return 0;
}