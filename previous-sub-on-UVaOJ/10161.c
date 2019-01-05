#include <stdio.h>

int main()
{
    int N;
    while(scanf("%d", &N) == 1)
    {
        if(N == 0) break;
        int num_l = 0, count_l = 1, count_tot = 1;
        while(N - count_tot > 0)
        {
            num_l++;
            count_l = 2 * num_l + 1;
            count_tot += count_l;
        }
        int rest = N - count_tot + count_l;
        int i, j;
        if(num_l % 2 == 0)
        {
            i = num_l;
            j = 0;
            while(rest > 1)
            {
                if(j < num_l) j++;
                else i--;
                rest--;
            }
        }
        else
        {
            i = 0;
            j = num_l;
            while(rest > 1)
            {
                if(i < num_l) i++;
                else j--;
                rest--;
            }
        }
        printf("%d %d\n", i + 1, j + 1);
    }
    return 0;
}
