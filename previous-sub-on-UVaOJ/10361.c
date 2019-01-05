#include <stdio.h>
#include <string.h>
#define MAXN 110

void splitstr(char s[])
{
    int i;
    for(i = 0; i < MAXN; i++)
    {
        if((s[i] = getchar()) == '<' || s[i] == '>' || s[i] == '\n')
        {
            s[i] = '\0';
            break;
        }
    }
}

int main()
{
    char sa[MAXN], sb[MAXN], s2[MAXN], s3[MAXN], s4[MAXN], s5[MAXN], c;
    int n;
    scanf("%d", &n);
    c = getchar();
    while(n--)
    {
        splitstr(sa);
        splitstr(s2);
        splitstr(s3);
        splitstr(s4);
        splitstr(s5);
        splitstr(sb);
        sb[strlen(sb) - 3] = '\0';
        printf("%s%s%s%s%s\n", sa, s2, s3, s4, s5);
        printf("%s%s%s%s%s\n", sb, s4, s3, s2, s5);
    }
    return 0;
}

