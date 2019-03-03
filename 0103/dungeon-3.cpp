// Dungeon practice - uva 532

// C libraries
#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>

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


const int direction[6][3] = {{-1, 0, 0}, {1, 0, 0}, {0, -1, 0}, {0, 1, 0}, {0, 0, -1}, {0, 0, 1}};
char dungeon[32][32][32];
int Distance[32][32][32];
int l, r, c;
struct point_type {
    int x;
    int y;
    int z;
};


int BFS(int i, int j, int k) {
    Distance[i][j][k] = 0;
    queue<point_type> q;
    point_type a = {i, j, k};
    q.push(a);

    dungeon[i][j][k] = '#';
    point_type cur, nxt;
    
    while (!q.empty()) {
        cur = q.front();
        q.pop();

        for (int i = 0; i < 6; i++) {
            nxt.x = cur.x + direction[i][0];
            nxt.y = cur.y + direction[i][1];
            nxt.z = cur.z + direction[i][2];
            if (nxt.x < 0 || nxt.x >= l || nxt.y < 0 || nxt.y >= r || nxt.z < 0 || nxt.z >= c) continue;

            if (dungeon[nxt.x][nxt.y][nxt.z] != '#') {
                Distance[nxt.x][nxt.y][nxt.z] = Distance[cur.x][cur.y][cur.z] + 1;
                if (dungeon[nxt.x][nxt.y][nxt.z] == 'E') {
                    return Distance[nxt.x][nxt.y][nxt.z];
                }
                dungeon[nxt.x][nxt.y][nxt.z] = '#';
                q.push(nxt);
            }
        }
    }
    return -1;
}


int main() {
    while (scanf("%d%d%d", &l, &r, &c) == 3) {
        if (!l && !r && !c) break;
        int start_i, start_j, start_k;
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < r; j++) {
                scanf("%s", dungeon[i][j]);
                for (int k = 0; k < c; k++) {
                    if (dungeon[i][j][k] == 'S') {
                        start_i = i;
                        start_j = j;
                        start_k = k;
                    }
                }
            }
        }

        int minute = BFS(start_i, start_j, start_k);
        if (minute == -1) printf("Trapped!\n");
        else printf("Escaped in %d minute(s).\n", minute);
    }
    return 0;
}