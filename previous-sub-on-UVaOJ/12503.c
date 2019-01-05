#include <stdio.h>
#include <string.h>

int main()
{
    int test_cases;
    scanf("%d", &test_cases);
    while (test_cases--)
    {
        int  i = 0, n, as, ins[105], robot = 0;
        char line[30];
        scanf("%d", &n);
        while (n--)
        {
            scanf("%s", line);
            if (strcmp(line, "LEFT") == 0)
            {
                robot += -1;
                ins[i] = -1;
            }
            else if (strcmp(line, "RIGHT") == 0)
            {
                robot += 1;
                ins[i] = 1;
            }
            else
            {
                scanf("%s %d", line, &as);
                robot += ins[as - 1];
                ins[i] = ins[as - 1];
            }
            i++;
        }
        printf("%d\n", robot);
    }
    return 0;
}
