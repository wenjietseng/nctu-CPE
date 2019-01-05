#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main()
{
    int test_case;
    while (scanf("%d", &test_case) != EOF)
    {
        int s[505], r, i, j, d, house;
        while (test_case--)
        {
            scanf("%d", &r);
            for (j = 0; j < r; j++)
            {
                scanf("%d", &s[j]);
            }
            sort(s, s + r);
            d = 0;
            house = s[r / 2];
            for (i = 0; i < r; i++)
                d += abs( house - s[i]);
            printf("%d\n", d);
        }
    }
    return 0;
}
