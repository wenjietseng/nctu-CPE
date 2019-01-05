#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

char list[63] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
int maps[128];


int deal(char* buf)
{
    int i, j, min = 2;
    for (i = 0; buf[i]; ++i)
    {
        if (min <= maps[buf[i]])
            min = maps[buf[i]] + 1;
    }
    for (i = min; i < 63; ++i)
    {
        int r = 0;
        for (j = 0; buf[j]; ++j)
        {
            r = (r * i + maps[buf[j]]) % (i - 1);
        }
        if (r == 0) return i;
    }
    return -1;
}

int main()
{
    int i;
    char buf[10000];
    for (i = 0; list[i]; ++i)
    {
        maps[list[i]] = i;
    }
    while (~scanf("%s", buf))
    {
        int v = deal(buf);
        if (v != -1) printf("%d\n", v);
        else printf("such number is impossible!\n");
    }
    return 0;
}
