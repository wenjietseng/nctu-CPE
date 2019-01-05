/* Secret Research */

#include <stdio.h>
#include <string.h>
int main() {
    int n;
    char S[1000];
    while(scanf("%d", &n) != EOF) {
        int i = 0;
        while(n >= 0) {
            fgets(S, sizeof(S), stdin);        
            int len = strlen(S);
            if(S[len - 2] == '5' && S[len - 3] == '3')
                printf("-\n");
            else if(S[0] == '9' && S[len - 2] == '4')
                printf("*\n");
            else if(S[0] == '1' && S[1] == '9' && S[2] == '0')
                printf("?\n");
            else if((S[0] == '1') ||
                    (S[0] == '4') ||
                    (S[0] == '7' && S[1] == '8'))
                printf("+\n");
            i++;
            n--;
        }
    }
}
