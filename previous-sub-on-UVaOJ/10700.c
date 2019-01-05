#include <stdio.h>
#include <string.h>

int main()
{
	int n_line;
	char buf[300];
	scanf("%d", &n_line);
	while (n--)
	{
		int i, num_buf[15] = {0}, num_buf_i = 0, op_buf_i = 0;
		char op_buf[15];
		fgets(stdin, 300, buf);
		for (i = 0; i < strlen(buf) - 1; i++)
		{
			if (buf[i] == '+' || buf[i] == '*')
			{
				op_buf[op_buf_i++] = buf[i];
			}
			else
			{
				
			}
		}

	}
	return 0;
}
