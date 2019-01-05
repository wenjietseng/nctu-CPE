#include <stdio.h>
#include <string.h>

typedef struct turtle Turtle;

struct turtle {
    int no, n, m;
};

/* define moving directions
                'N' 'S' 'E' 'W' 'NE' 'NW' 'SE' 'SW' */
int moveN[8] = {-1,  1,  0,  0, -1,  -1,   1,   1};
int moveM[8] = { 0,  0,  1, -1,  1,  -1,   1,  -1};
 
void printPond(int N, int M, int P[N][M]) {
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            if (P[i][j]) printf("*");
            else printf(" ");
        }
        printf("\n");
    }
    printf("\n");
}


int stringToMove(char string[]) {
    int len = strlen(string);
    if (len == 1)
    {
        if (string[0] == 'N') return 0;
        else if (string[0] == 'S') return 1;
        else if (string[0] == 'E') return 2;
        else return 3;
    }
    else
    {
        if (string[0] == 'N')
        {
            if (string[1] == 'E') return 4;
            else return 5;
        }
        else
        {
            if (string[1] == 'E') return 6;
            else return 7;
        }
    }
}

int main()
{
    int N, M, T, K, turtle_num;
    char query[5]; // string literal has '\0' at the end, so set a larger size
    while (scanf("%d %d %d %d", &N, &M, &T, &K) == 4)
    {
        int pond[N][M];          /* create pond by N and M */
        memset( pond, 0, N * M * sizeof(int));
        Turtle turtle[T];        /* initialize turtles */
        int i;
        for (i = 0; i < T; i++)
        {
            scanf("%d %d %d", &turtle[i].no, &turtle[i].n, &turtle[i].m);
            pond[turtle[i].n][turtle[i].m] = 1;
        }

        printPond(N, M, pond);

        // process turtle movement queries
        for (i = 0; i < K; i++)
        {
            int next_n = 0, next_m = 0;
            scanf("%d %s", &turtle_num, query);
            int direction = stringToMove(query);

            if (!pond[next_n][next_m] &&
                next_n >= 0 && next_n < N && next_m >= 0 && next_m < M)
            {
                pond[turtle[turtle_num - 1].n][turtle[turtle_num - 1].m] = 0;                
                next_n = turtle[turtle_num - 1].n + moveN[direction];
                next_m = turtle[turtle_num - 1].m + moveM[direction];
                pond[next_n][next_m] = 1;                
            }
        }
        printPond(N, M, pond);
    }
    return 0;
}

