#include <stdio.h>
#include <string.h>
#define N 110

int main()
{
    int sum[N] = {0};
    char line[N];
    int i;
    while (fgets(line, N, stdin) && !(line[0] == '0' && line[1] == '\0'))
    {
        int len = strlen(line) - 1;
        for (i = 0; i < len; i++)
        {
            sum[i] += line[len - i - 1] - '0';
            if (sum[i] >= 10)
            {
                sum[i + 1] += sum[i] / 10;
                sum[i] %= 10;
            }
        }

    }

    i = N - 1;
    while (sum[i] == 0 && i >= 0) i--;
    while (i >= 0)
    {
        printf("%d", sum[i--]);
    }
    printf("\n");

    return 0;
}
