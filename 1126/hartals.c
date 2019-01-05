#include <stdio.h>
int test_cases, days, num_of_parties, i;

int main() {

    scanf("%d", &test_cases);
    while (test_cases--) {
        scanf("%d", &days);
        scanf("%d", &num_of_parties);
        int hartals_array[3651] = {0}, temp = 0, x;
        for (i = 0; i < num_of_parties; i++) {
            scanf("%d", &x);
            temp = x;
            while (x <= days) {
                hartals_array[x] = 1;
                x = x + temp;
            }
        }
        int count = 0;
        for (i = 0; i <= days; i++) {
            if (hartals_array[i] == 1 && (i % 7 != 0) && (i % 7 != 6))
                count++;
        }
        printf("%d\n", count);
    }
    return 0;
}