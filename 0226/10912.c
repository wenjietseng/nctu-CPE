// Simple Minded Hashing, DP

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dp[30][30][400];
int sum[30][400];

int main()
{
	int l, e, s, t;
	memset(dp, 0, sizeof(dp));
	dp[0][0][0] = 1;
	for (l = 1; l <= 26; l++)
	{
		for (e = 1; e <= 26; ++e)
		{
			for (s = 0; s <= 351; ++s)
			{ 
				for (t = 0; t < e; ++t)
				{
					dp[l][e][s + e] += dp[l - 1][t][s];
				}
			}
		}
	}

	memset(sum, 0, sizeof(sum));
	for (l = 1; l <= 26; l++)
	{
		for (e = 1; e <= 26; ++e)
		{
			for (s = 0; s <= 351; ++s)
			{
				sum[l][s] += dp[l][e][s];
			}
		}
	}

	int L, S, cases = 1;
	while (scanf("%d %d", &L, &S) && L + S)
	{
		printf("Case %d: ", cases++);
		if (L <= 26 && S <= 351)
		{
			printf("%d\n", sum[L][S]);
		}
		else
		{
			printf("0");
		}
	}
}
