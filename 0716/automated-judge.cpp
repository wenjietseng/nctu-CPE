// Automated judge script uva 10188
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <iostream>
using namespace std;

int main() {
    int n, m;
    int runcase = 0;
    string ans, output;
    string input;
    bool ac, pe;

    while (scanf("%d", &n) != EOF && n) {
        getchar();
        ans = "";
        output = "";


        for (int i = 0; i < n; i++) {
            getline(cin, input);
            if (i) ans += '\n', ans += input;
            else ans = input;
        }
        scanf("%d", &m);
        getchar();
        for (int i = 0; i < n; i++) {
            getline(cin, input);
            if (i) output += '\n', output += input;
            else output = input;
        }

        ac = true;
        if (ans != output) ac = false;

        if (ac) {
            printf("Run #%d: Accepted\n", ++runcase);
            continue;
        }

        pe = true;
        for (int i = 0; i < ans.length(); i++)
            if (!isdigit(ans[i])) ans.erase(i, 1), i--;
        for (int i = 0; i < output.length(); i++)
            if (!isdigit(output[i])) output.erase(i, 1), i--;
        
        if (ans != output) pe = false;

        if (pe) {
            printf("Run #%d: Presentation Error\n", ++runcase);
            continue;
        }

        printf("Run #%d: Wrong Answer\n", ++runcase);
    }

    return 0;
}