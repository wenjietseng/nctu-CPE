#include<stdio.h>
#include<math.h>

typedef struct
{
    double x, y, z;
} point;

double dist(point a, point b)
{
    double X, Y, Z;
    X = a.x - b.x;
    Y = a.y - b.y;
    Z = a.z - b.z;
    return sqrt(X * X + Y * Y + Z * Z);
}

point P[5005];

int main()
{
    int count = 0;
    while (scanf("%lf %lf %lf", &P[count].x, &P[count].y, &P[count].z) == 3)
    {
        if (P[count].x + P[count].y + P[count].z == 0) break;
        count++;
    }
    int hist[10] = {0};
    int i, j;
    for (i = 0; i < count; i++)
    {
        double min = 10, temp;
        for (j = 0; j < count; j++)
        {
            if (i == j) continue;
            temp = dist(P[i], P[j]);
            if (min < temp)
                min = temp;
        }
        if (min < 10)
            hist[(int) floor(min)] += 1;
    }

    for (i = 0; i < 10; i++)
        printf("%4d", hist[i]);
    printf("\n");
    return 0;
}
