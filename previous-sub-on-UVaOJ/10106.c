#include <stdio.h>
#include <string.h>
#define N 255 

int main()
{
    int i, j;
    char x[N], y[N];
    while (fgets(x, N, stdin) != NULL && fgets(y, N, stdin) != NULL)
    {
        int multiply[N * 2] = {0};
        int lenx = strlen(x) - 1, leny = strlen(y) - 1;
        for (i = 0; i < lenx; i++)
        {
            for (j = 0; j < leny; j++)
            {
                multiply[i + j] += (x[lenx - 1 - i] - '0') * (y[leny - 1 - j] - '0');
                if(multiply[i + j] >= 10)
                {
                    multiply[i + j + 1] += multiply[i + j] / 10;
                    multiply[i + j] %= 10;
                }
            }
        }
        i = N * 2 - 1; /* forgot N = 255 */                              
        while (!multiply[i] && i >= 1) i--;   
        while (i >= 0)
        {
            printf("%d", multiply[i--]);
        }
        printf("\n");
    }
    return 0;
}
