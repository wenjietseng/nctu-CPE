#include<stdio.h>
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))

typedef struct guard_info {
    int x1, y1, x2, y2;
} guard;

int main()
{
    int N, night = 1;
    guard g1, g2;
    scanf("%d", &N);
    while (N--)
    {
        int A, B, C, p, q, r, s;
        scanf("%d %d %d %d", &g1.x1, &g1.y1, &g1.x2, &g1.y2);
        scanf("%d %d %d %d", &g2.x1, &g2.y1, &g2.x2, &g2.y2);
        p = max(g1.x1, g2.x1);
        q = max(g1.y1, g2.y1);
        r = min(g1.x2, g2.x2);
        s = min(g1.y2, g2.y2);
        A = (g1.x2 - g1.x1) * (g1.y2 - g1.y1);
        B = (g2.x2 - g2.x1) * (g2.y2 - g2.y1);
        C = (p - r) * (q - s);
        printf("Night %d: ", night++);
        if (p >= r || q >= s) printf("0 %d %d\n", A + B, 10000 - A - B);
        else printf("%d %d %d\n", C, A + B - 2 * C, 10000 - A - B + C);
    }
    return 0;
}
