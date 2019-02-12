// Rank the language - uva 10336
// DFS
// C libraries
#include <cstdio>
#include <cstring>
#include <cmath>

// C++ libraries
#include <iostream>
#include <string>
// STL libraries
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <stack>
// namespace
using namespace std;

// define marcos
#define MAXN 1000
char landkarte[25][25];
int visited[25][25];
int langs[30];
int directions[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
int n = 0, test_cases = 1, H = 0, W = 0;


void DFS(int r, int c, char lang) {
    if (r < 0 || r >= H || c < 0 || c >= W ||
        lang != landkarte[r][c] || visited[r][c]) return;
    visited[r][c] = 1;
    for (int i = 0; i < 4; i++) {
        int nxt_r = r + directions[i][0];
        int nxt_c = c + directions[i][1];
        DFS(nxt_r, nxt_c, lang);
    }
}

int main() {
    scanf("%d", &n);
    while (n--) {
        scanf("%d %d", &H, &W);
        for (int i = 0; i < H; i++) scanf("%s", landkarte[i]);
        
        memset(langs, 0, sizeof(langs));
        memset(visited, 0, sizeof(visited));
        
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (visited[i][j] == 0) {
                    DFS(i, j, landkarte[i][j]);
                    int idx = landkarte[i][j] - 'a';
                    langs[idx] += 1;
                }
            }
        }

        printf("World #%d\n", test_cases++);
        // for (int i = 0; i < 26; i++) {
        //     printf("%c: %d\n", 'a'+i, langs[i]);
        // }



        int Max = 0;
        for (int i = 0; i < 26; i++) if (langs[i] > Max) Max = langs[i];
        // cout << Max << endl;
        while (Max) {
            for (int i = 0; i < 26; i++) if (Max == langs[i]) printf("%c: %d\n", 'a'+i, langs[i]);
            Max--;
        }
    }
    return 0;
}