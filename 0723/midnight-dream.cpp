// A mid-summer night’s dream uva 10057
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n, m, M;
    while (scanf("%d", &n) != EOF) {
        int arr[n + 5], med_count = 0;
        for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
        sort(arr, arr + n);
        m = arr[(n-1) / 2];
        M = arr[n / 2];;
        for (int i = 0; i < n; i++) if (arr[i] == m || arr[i] == M) med_count++;
        printf("%d %d %d\n", m, med_count, M-m+1);
    }
    return 0;
}