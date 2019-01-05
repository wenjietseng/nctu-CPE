/*
    This problem costs me much more time
    because I do not use scanf, getchar,
    or fgets very well.
*/


#include<stdio.h>
#include<string.h>
int main()
{
    int n, i, j, max, xs, tot, count_x[15];
    char c;
    while(scanf("%d", &n) && n != 0)
    {
        memset(count_x, 0, sizeof(count_x));
        max = tot = 0;
        for(i = 0; i < n; i++)
        {
            c = getchar();
            xs = 0;
            for(j = 0; j < 25; j++)
            {
                if((c = getchar()) == 'X') xs++;
            }
            count_x[i] = xs;
            if(xs > max) max = xs;
        }
        for(i = 0; i < n; i++)
            tot += max - count_x[i];
        printf("%d\n", tot);
        c = getchar();
    }
    return 0;
}
