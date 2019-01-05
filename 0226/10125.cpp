// Use brutral force
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
int find(std::vector<int>& set)
{
	for (int d = set.size() - 1; d >= 0; --d)
		for (int a = 0; a < set.size(); ++a)
			for (int b = a + 1; b < set.size(); ++b)
				for (int c = b + 1; c < set.size(); ++c)
					if ((set[d] == set[a] + set[b] + set[c]) &&
							a != d && b != d && c != d)
						return set[d];
	return INT_MAX;
}

int main()
{
	/*
#ifndef ONLINE_JUDGE
	freopen("10125.in", "r", stdin);
#endif
*/

	int n;
	while (std::cin >> n)
	{
		if (n == 0) break;

		std::vector<int> set(n);
		for (int i = 0; i < n; i++)
			std::cin >> set[i];

		sort(set.begin(), set.end());

		int d = find(set);
		if (d == INT_MAX)
		{
			std::cout << "no solution\n";
		}
		else
		{
			std::cout << d << "\n";
		}
	}
	return 0;
}
