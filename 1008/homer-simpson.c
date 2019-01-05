#include <stdio.h>

int m, n, t;

int main()
{
    while(scanf("%d%d%d", &m, &n, &t) != EOF) {
        if (t < m && t < n) printf("0 %d\n", t); // if given time t smaller than m and n, drink beer
        else if ((t < m && t >= n) || (t >= m && t < n)) { // t is between n m or m n
            int target = (t >= n ? n : m);
            if (t % target == 0) printf("%d\n", t/target);
            else printf("%d %d\n", t/target, t%target);
        }
        else {
            int small, large, temp, flag = 0, i, j;
            large = (m >= n ? m : n);
            small = (m >= n ? n : m);
            temp = t / small;
            if (t % small == 0) {
                printf("%d\n", temp);
                flag = 1;
            }
            else {
                for (i = t/small; i >= 1; i++)
                    for (j = 1; j <= t/large; j++)
                        if (i*small+j*large == t) printf("%d\n", i+j);
            }
            if (flag == 0) {
                printf("%d %d\n", temp, t%small);
            }
        }
    }
    return 0;
}