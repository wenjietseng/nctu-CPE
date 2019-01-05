#include<stdio.h>

int cycle_length(int n)
{
    if (n == 1) return 1;
    if (n % 2 == 1) return 1 + cycle_length(3 * n + 1);
    else return 1 + cycle_length (n / 2);
}

int main()
{
    int i, j;
    while (scanf("%d %d", &i, &j) != EOF)
    {
        
        int min_i_j, max_i_j, current_len,  max_len = 0;
        min_i_j = (i < j) ? i : j;
        max_i_j = (i > j) ? i : j;
        for ( ; min_i_j <= max_i_j; min_i_j++)
        {
            current_len = cycle_length(min_i_j);
            if (max_len < current_len) max_len = current_len;
        }
        printf("%d %d %d\n", i, j, max_len);
    }
    return 0;
}
