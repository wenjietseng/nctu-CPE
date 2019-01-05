#include <stdio.h>
#include <stdlib.h> /* atof */
#include <limits.h> /* INT_MAX */
int main()
{
    double a, b; /* for sum and product */
    char x[500], y[500], op;
    while (scanf("%s %c %s\n", x, &op, y) == 3)
    {
        a = atof(x);
        b = atof(y);
        printf("%s %c %s\n", x, op, y);
        if (a > INT_MAX) printf("first number too big\n");
        if (b > INT_MAX) printf("second number too big\n");
        if (op == '+' && a + b > INT_MAX) printf("result too big\n");
        if (op == '*' && a * b > INT_MAX) printf("result too big\n");
    }
    return 0;
}
