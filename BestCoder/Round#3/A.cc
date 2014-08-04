#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXN = 100000 + 10;

int t[MAXN], f[MAXN];
int N, M;

int main() {
    int T; scanf("%d", &T);
    while (T --) {
        scanf("%d%d", &N, &M);
        for (int i = 0; i < N; ++ i) scanf("%d", t + i);
        sort(t, t + N);
        f[N - 1] = t[N - 1] + 1;
        for (int i = N - 2; i >= 0; -- i) {
            if (t[i] + 1 == t[i + 1]) f[i] = f[i + 1];
            else f[i] = t[i] + 1;
        }
        while (M --) {
            int q; scanf("%d", &q);
            int idx = lower_bound(t, t + N, q) - t;
            if (idx == N || t[idx] != q) printf("%d\n", q);
            else printf("%d\n", f[idx]);
        }
    }
    return 0;
}
