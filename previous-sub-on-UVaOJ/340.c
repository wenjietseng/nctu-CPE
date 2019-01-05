#include <stdio.h>
#define MAXN 1000 + 10

/* if found the first one is 0, it could directly terminate 
int isAllZero(int N, int guess[])
{
    int i;
    for (i = 0; i < N; i++)
    {
        if (guess[i] != 0) return 0;
    }
    return 1;
}
*/

int main()
{
    int N, Game = 1, i, j;
    while(scanf("%d", &N) == 1 && N)
    {   /* read N, max N is 1000 */
        int ans[MAXN], guess[MAXN];
        if (N == 0) break;
        for (i = 0; i < N; i++)
        {   /* read answer */
            scanf("%d", &ans[i]);
        }
        /* output format: Game 1: */
        printf("Game %d:\n", Game++);
        for (;;)
        {
            int strong = 0, weak = 0;
            /* read arbitrary guesses */
            for(i = 0; i < N; i++)
            {
                scanf("%d", &guess[i]);
                /* check strong match */
                if (ans[i] == guess[i]) strong++;
            }
            /* if a line with N 0s, next game 
            if (isAllZero(N, guess)) break; */

            if (guess[0] == 0) break;

            /* check weak match, count 1 - 9, guess - ans*/
            for (j = 1; j < 10; j++)
            {
                int num_in_ans = 0, num_in_guess = 0;
                for (i = 0; i < N; i++)
                {
                    if (ans[i] == j) num_in_ans++;
                    if (guess[i] == j) num_in_guess++;
                }
                /* pick the small one for counts */
                if (num_in_ans < num_in_guess) weak += num_in_ans;
                else weak += num_in_guess; 
            }
            /* print hint */
            printf("    (%d,%d)\n", strong, weak - strong);
        }
    }
    return 0;
}
