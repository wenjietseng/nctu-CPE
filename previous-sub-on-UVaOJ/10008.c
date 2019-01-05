#include <stdio.h>
#include <ctype.h>

int alpha[100] = {0};

int main()
{
    int n, max = 0, i, j;
    char line[500];
    scanf("%d\n", &n);
    while (n--)
    {
        fgets(line, sizeof(line), stdin);
        for (i = 'A'; i <= 'Z'; i++)
        {
            for (j = 0; line[j] != '\0'; j++)
            {
                if (toupper(line[j]) == i)
                    alpha[i]++;
                if (alpha[i] > max)
                    max = alpha[i];
            }
        }
    }
    for (i = max; i > 0; i--)
    {
        for (j = 'A'; j <= 'Z'; j++)
        {
            if (alpha[j] == i)
                printf("%c %d\n", j, i);
        }
    }
    return 0;
}
