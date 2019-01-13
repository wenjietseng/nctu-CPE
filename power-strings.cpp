// Power strings 10298
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
#define MAXN 1000000 + 5
char s[MAXN], a[MAXN];

int main() {
    char line[MAXN];
    while (scanf("%s", line) == 1 && strcmp(line, ".")) {
        int length = strlen(line);
        vector<int> pi(length + 1, 0);
        for (int i = 2; i <= length; i++) {
            int k = pi[i - 1];
            while (k > 0 && line[k] != line[i - 1]) {
                k = pi[k];
            }
            if (line[k] == line[i-1]) pi[i] = k + 1;
            else pi[i] = 0;
        }
        int period = 0;
        for (int i = 1; i <= length; i++) {
            if (i - pi[i] > period) period = i - pi[i];
        }
        if (length % period != 0) period = length;
        cout << length / period << endl;
    }
    return 0;
}

/*int main() {
    while (scanf("%s", s) != EOF) {
        if (strlen(s) == 1 && s[0] == '.') break;
        int ans = 1;
        for (int i = 1; i < strlen(s)/2 && strlen(s)%i == 0; i++) { // 1 for a's length
            int is_power_string = 1;
            memset(a, 0, sizeof(a));
            strncpy(a, s, i);
            for (int j = 0; j < strlen(s); j += i) {
                if (strncmp(a, s+j, i) == 0) continue;
                else {
                    is_power_string = 0;
                    break;
                }
            }
            if (is_power_string) if (strlen(s)/i > ans) ans = strlen(s)/i;
        }
        cout << ans << endl;
    }
    return 0;
}*/

