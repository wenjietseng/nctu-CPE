// uva 532 Dungeon Master
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <iostream>
using namespace std;

char dungeon[32][32][32];
int Distance[32][32][32]; // record the ans
int L, R, C;
const int direction[6][3] = {{-1,0,0}, {1,0,0}, {0,-1,0}, {0,1,0}, {0,0,-1}, {0,0,1}};
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
            // cout << nxt.x << " " << nxt.y << " " << nxt.z << endl;
            if (nxt.x < 0 || nxt.x >= L || nxt.y < 0 || nxt.y >= R || nxt.z < 0 || nxt.z >= C) continue;

            if (dungeon[nxt.x][nxt.y][nxt.z] != '#') {

                Distance[nxt.x][nxt.y][nxt.z] = Distance[cur.x][cur.y][cur.z] + 1;
                if (dungeon[nxt.x][nxt.y][nxt.z] == 'E') {
                    // cout << "find exit" << endl;
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
    while (scanf("%d%d%d", &L, &R, &C) == 3) {
        if (!L && !R && !C) break;
        int start_i = 0, start_j = 0, start_k = 0;

        for (int i = 0; i < L; i++) {
            for (int j = 0; j < R; j++) {
                scanf("%s", dungeon[i][j]);
                for (int k = 0; k < C; k++) {
                    if (dungeon[i][j][k] == 'S') {
                        start_i = i;
                        start_j = j;
                        start_k = k;
                    }
                }
            }
        }

        int minute = BFS(start_i, start_j, start_k);
        if (minute != -1) printf("Escaped in %d minute(s).\n", minute);
        else printf("Trapped!\n");
    }
    return 0;
}