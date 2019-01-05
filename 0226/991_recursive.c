#include <stdio.h>

unsigned long int catalan(unsigned int n)
{
	// Base case
	if (n <= 1) return 1;

	// catalan(n) = sum of catalan(i) * catalan(n - i - 1)
	unsigned long int res = 0;
	for (int i = 0; i < n; i++)
	{ 
		res += catalan(i) * catalan(n - i - 1);
	}
	return res;
}

int main()
{
	for (int i = 0; i < 10; i++)
	{
		printf("%lu\n", catalan(i));
	}
}
