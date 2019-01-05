// Light, more light

#include<stdio.h>
#include<math.h>

int main()
{
	long n_of_bulbs;
	while (scanf("%ld", &n_of_bulbs) == 1)
	{
		if (n_of_bulbs == 0) break;
		long root = sqrt(n_of_bulbs);
		if (root * root == n_of_bulbs) printf("yes\n");
		else printf("no\n");
		/*	
		for (i = 1; i <= n_of_bulbs; i++)
		{
			if (n_of_bulbs % i == 0)
			{
				if (on_off_flag == 0) on_off_flag = 1;
				else on_off_flag = 0;
			}
		}
		if (on_off_flag == 0) printf("no\n");
		else printf("yes\n");
		*/
	}
	return 0;
}

