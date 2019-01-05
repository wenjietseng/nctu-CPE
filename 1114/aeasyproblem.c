#include <stdio.h>
#include <string.h>

int main(){

    char input[10001];
    while (scanf("%s", input) != EOF) {
        int sum = 0, max = 1, i;

        for (i = 0; i < strlen(input); i++) {
            int temp = input[i];
            if (temp >= '0' && temp <= '9') {
                temp = temp - '0';
            }
            else if (temp >= 'a' && temp <= 'z') {
                temp = temp - 'a' + 36;
            }
            else if (temp >= 'A' && temp <= 'Z') {
                temp = temp - 'A' + 10;
            }
            if (temp > max) max = temp;
            sum += temp;
        }
    
        for (i = max; i < 62; i++) {
            if (!(sum % i)) {
                printf("%d\n", i + 1);
                break;
            }
        }

        if (i == 62) printf("such number is impossible!\n");
    }
    return 0;
}