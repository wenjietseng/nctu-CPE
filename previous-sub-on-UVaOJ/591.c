/*  591 Box of Bricks */
#include <stdio.h>
int main() 
{
    int n, h[60], i, set = 1, sum, mean, moves;
    while(scanf("%d", &n) == 1 && n) 
    {
        sum = mean = moves = 0;
        for (i = 0; i < n; i++) 
        {
            scanf("%d", &h[i]);
            sum += h[i];
        }
        mean = sum / n;
        for (i = 0; i < n; i++)
        {
            if (h[i] > mean) moves += h[i] - mean;
        }
        printf("Set #%d\nThe minimum number of moves is %d.\n\n", set++, moves);
    }
    return 0;
}
