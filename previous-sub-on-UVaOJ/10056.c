#include <stdio.h>
#include <math.h>

int main()
{
    int S, N, I;
    double p;
    while (scanf("%d", &S) == 1)
    {
        while (S--)
        {
            scanf("%d %lf %d", &N, &p, &I);
            if (p == 0) printf("0.0000");
            printf("%.4lf\n", pow(1 - p, I - 1) * p / (1 - pow(1 - p, N)));
        }
    }
    return 0;
}
