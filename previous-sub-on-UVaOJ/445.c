/*
    Marvelous Mazes:
    - One digit + letter, repeat letter for digit times.
    - Two digits + letter, repeat letter for sum of digit times.
    - ! means end of line ("\n").
    - There should be blank line between each ouput maze.
*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAXN 100000
char output[MAXN];
 
int main()
{
    int i = 0, digit_1 = 0, digit_2 = 0;
    char c;
    c = getchar();
    while(c != EOF)
    {
        if(c == '\n')
        {
            output[i] = c;
            i++;
        }
        else
        {
            if(isdigit(c))
            {
                digit_1 = c;
                c = getchar();
                if(isdigit(c))
                {
                    digit_2 = c;
                    c = getchar();
                    for(i = 0; i < (digit_1 + digit_2); i++) output[i] = c;
                }
                else
                {
                    for(i = 0; i < digit_1; i++) output[i] = c;
                }
            }
        }
        c = getchar();
    }

    for(i = 0; i < strlen(output); i++) printf("%c", output[i]);
    return 0;
}
