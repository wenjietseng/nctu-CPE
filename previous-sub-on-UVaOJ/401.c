#include <stdio.h>
#include <string.h>
const char letter_reverse[] = {
    'A', ' ', ' ', ' ', '3', ' ', ' ',
    'H', 'I', 'L', ' ', 'J', 'M', ' ',
    'O', ' ', ' ', ' ', '2', 'T', 
    'U', 'V', 'W', 'X', 'Y', '5'
};
const char number_reverse[] = {
    ' ', '1', 'S', 'E', ' ', 'Z', ' ', ' ', '8', ' '
};
char a[100];

int main()
{
    int i, j;
    while(scanf("%s", a) != EOF)
    {
        int palindrome = 1, mirrored = 1;
        for(i = 0, j = strlen(a)-1; i <= j; i++, j--)
        {
            if (a[i] != a[j]) palindrome = 0;
            if ('A' <= a[i] && a[i] <= 'Z')
            {
                if (letter_reverse[a[i] - 'A'] != a[j])
                    mirrored = 0;
            }
            else
            {
                if (number_reverse[a[i] - '0'] != a[j])
                    mirrored = 0;
            }
        }
        printf("%s -- ", a);
        if (palindrome)
        {
            if (mirrored) printf("is a mirrored palindrome.\n");
            else printf("is a regular palindrome.\n");
        }
        else
        {
            if (mirrored) printf("is a mirrored string.\n");
            else printf("is not a palindrome.\n");
        }
        printf("\n");
    }
    return 0;
}
