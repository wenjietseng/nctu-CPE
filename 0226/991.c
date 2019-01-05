// Safe Salutation:
// the sequence describe in problem is a catalan series

#include <stdio.h>

#define NMAX 10

int main(int argc, char *argv[])
{
	int i, catalan[NMAX + 2] = {1};
	for (i = 1; i < NMAX + 2; i++)
	{
		catalan[i] = catalan[i - 1] * 2 * (2 * i - 1) / (i + 1);
	}
	int N, index = 0;
	while (scanf("%d", &N) != EOF && ++index)
	{
		if (index > 1) printf("\n");
		printf("%d\n", catalan[N]);
	}
	return 0;
}
