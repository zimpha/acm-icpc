#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 80000 + 10;

int a[MAXN], cnt[MAXN], N, M, pos;

int main() {
    while (scanf("%d%d", &N, &M) == 2) {
        for (int i = 0; i < N; ++ i) {
            scanf("%d", &a[i]);
            if (a[i] == M) pos = i;
        }
        for (int i = 0; i <= 2 * N; ++ i) cnt[i] = 0;
        cnt[N] = 1;
        for (int i = pos + 1, sum = 0; i < N; ++ i) {
            if (a[i] > M) ++ sum;
            else -- sum;
            ++ cnt[N + sum];
        }
        long long ret = cnt[N];
        for (int i = pos - 1, sum = 0; i >= 0; -- i) {
            if (a[i] < M) ++ sum;
            else -- sum;
            ret += cnt[sum + N];
        }
        cout << ret << endl;
    }
    return 0;
}
