#include <stdio.h>

int countBits(int v)
{
    int count = 0;
    while (v != 0)
    {
        if (v & 1) count++;
        v = v >> 1;
    }
    return count;
}

int main()
{
    int N, M;
    scanf("%d", &N);
    while (N--)
    {
        scanf("%d", &M);
        printf("%d ", countBits(M));
        char conv[30];
        sprintf(conv, "%d", M);
        sscanf(conv, "%x", &M);
        printf("%d\n", countBits(M));
    }
    return 0;
}
