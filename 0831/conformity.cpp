// Conformity 11286
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <iostream>
using namespace std;

int courses[5];
int main() {
    int n;
    while (cin >> n && n) {
        map<long long, int> Map;
        int maxv = 1, count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 5; j++) cin >> courses[j];
            sort(courses, courses+5);
            long long value = 0;
            for (int i = 0; i < 5; i++) {
                value *= 1000;
                value += courses[i];
            }
            maxv = max(maxv, Map[value] += 1);
        }
        for (map<long long, int>::iterator it = Map.begin(); it != Map.end(); it++) {
            // cout << it->first << endl;
            if (it->second == maxv) count += maxv;
        }
        cout << count << endl;
    }
    return 0;
}



/* old method
int n, course_sets[10000 + 5];

int main() {
    while (scanf("%d", &n) != EOF && n) {
        memset(course_sets, 0, sizeof(course_sets));
        for (int i = 0; i < n; i++) {
            int tmp, sum = 0;
            for (int j = 0; j < 5; j++) {
                scanf("%d", &tmp);
                sum += tmp;
            }
            course_sets[i] = sum;
        }
        sort(course_sets, course_sets+n);
        for (int i = 0; i < n; i++) cout << course_sets[i] << endl;
    }
    return 0;    
}*/