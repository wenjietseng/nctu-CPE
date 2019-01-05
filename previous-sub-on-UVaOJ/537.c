#include <stdio.h>

float convert_unit(double num, char prefix)
{
    float out;
    out = num;
    if(prefix == 'm')
        out *= 0.001;
    else if(prefix == 'k')
        out *= 1000;
    else if(prefix == 'M')
        out *= 1000000;
    return out;
}

int main()
{
    int test_case, i;
    while(scanf("%d\r", &test_case) == 1)
    {
        for(i = 0; i < test_case; i++)
        {
            double P = -1, U = -1, I = -1;
            char c;
            while((c = getchar()) != '\n')
            {
                char unit;
                if(c == 'P')
                {
                    if((c = getchar()) == '=')
                    {
                        scanf("%lf%c", &P, &unit);           
                        P = convert_unit(P, unit);
                    }
                }
                else if(c == 'U')
                {
                    if((c = getchar()) == '=')
                    {
                        scanf("%lf%c", &U, &unit);           
                        U = convert_unit(U, unit);
                    }
                }
                else if(c == 'I')
                {
                    if((c = getchar()) == '=')
                    {
                        scanf("%lf%c", &I, &unit);           
                        I = convert_unit(I, unit);
                    }
                }
            }
            printf("Problem #%d\n", i + 1);
            if(U != -1 && I != -1)
                printf("P=%.2lfW\n\n", U * I);
            else if(P != -1 && U != -1)
                printf("I=%.2lfA\n\n", P / U);
            else if(P != -1 && I != -1)
                printf("U=%.2lfV\n\n", P / I);
        }
    }
    return 0;
}
