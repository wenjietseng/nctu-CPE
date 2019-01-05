// 572 Oil Deposits

#include <stdio.h>
#include <string.h>

const int MAX_MAP_LIMIT = 100;

void visit(int isVisited[][MAX_MAP_LIMIT + 5],
		   char map[][MAX_MAP_LIMIT + 5],
		   int i, int j)
{
	if (map[i][j] == '@' && !isVisited[i][j])
	{
		isVisited[i][j] = 1;
		visit(isVisited, map, i - 1, j);
		visit(isVisited, map, i + 1, j);
		visit(isVisited, map, i, j + 1);
		visit(isVisited, map, i, j - 1);
		visit(isVisited, map, i + 1, j - 1);
		visit(isVisited, map, i + 1, j + 1);
		visit(isVisited, map, i - 1, j - 1);
		visit(isVisited, map, i - 1, j + 1);
	}
}

int main(int argc, char *argv[])
{
	int m, n, c;
	while (scanf("%d %d", &m, &n) != EOF && m > 0)
	{
		char map[MAX_MAP_LIMIT + 5][MAX_MAP_LIMIT + 5];
		memset(map, 0, sizeof(map));
		int i, j;
		c = getchar();
		for (i = 1; i <= m; i++)
			fgets(map[i], MAX_MAP_LIMIT, stdin);

		int isVisited[MAX_MAP_LIMIT + 5][MAX_MAP_LIMIT + 5];
		memset(isVisited, 0, sizeof(isVisited));
		int oilCount = 0;
		for (i = 1; i <= m; i++)
		{
			for (j = 0; j < n; j++)
			{
				if (map[i][j] == '@' && !isVisited[i][j])
				{
					visit(isVisited, map, i, j);
					oilCount++;
				}
			}
		}
		printf("%d\n", oilCount);
	}
	return 0;
}
