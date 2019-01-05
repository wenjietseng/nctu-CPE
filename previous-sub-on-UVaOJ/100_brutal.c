#include <stdio.h>
#define MAXN 1000000 + 5
int cycle_length[MAXN] = {0};

int main()
{
    int i, j, min_i_j, max_i_j;
    cycle_length[1] = 1;
    while (scanf("%d %d", &i, &j) != EOF)
    {
        int current_len, max_len = -1;
        min_i_j = (i < j) ? i : j;
        max_i_j = (i > j) ? i : j;
        for ( ; min_i_j <= max_i_j; min_i_j++)
        {
            if (cycle_length[min_i_j] == 0)
            {
                if (min_i_j == 1) cycle_length[min_i_j] = 1;
                if (min_i_j % 2 == 1) cycle_length[min_i_j] = 3 * min_i_j + 1;
                else cycle_length[min_i_j] = min_i_j / 2;
            }
            else
            {
                
            }
        }
    }
    return 0;
}
