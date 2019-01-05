/*
    uva 299 Train swapping, I think it is a buble sort.
    Just record the counts of swap.
*/
#include <stdio.h>

int main()
{
    int test_cases, length;
    while(scanf("%d", &test_cases) != EOF)
    {
        int train[55], k, count;
        for (k = 0; k < test_cases; k++)
        {
            scanf("%d", &length);
            int i, j;
            for (i = 0; i < length; i++)
            {
                scanf("%d", &train[i]); 
            }
            count = 0;
            for (i = 0; i < length; i++)
            {
                for (j = length - 1; i < j; j--)
                {
                    if (train[j - 1] > train[j])
                    {
                        int tmp;
                        tmp = train[j - 1];
                        train[j - 1] = train[j];
                        train[j] = tmp;
                        count++;
                    }
                }
            }
            printf("Optimal train swapping takes %d swaps.\n", count);
        }
    }
    return 0;
}
