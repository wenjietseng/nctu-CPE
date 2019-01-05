#include <stdio.h>
#include <math.h>
#define error 1e-8

int main()
{
    int H, num, m, N;

    while(scanf("%d %d", &H, &num) != EOF && !(H == 0 && num == 0))
    {
        if (H == 1 && num == 1) printf("0 1\n");
        
        m = 1;
        while(H != (int)(pow(pow(num, 1.0 / m) + 1.0, m) + error)) m++;
        N = (int)(pow(num, 1.0 / m) + error);
        if (N != 1)
            printf("%d %d\n", (1 - num) / (1 - N), (H - num)*(N + 1) + num);
        else
            printf("%d %d\n", m, (H - num) * (N + 1) + num);
    }
    return 0;
}
