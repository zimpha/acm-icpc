#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000000 + 10;

int rk[MAXN], sa[MAXN], a[MAXN], n, m;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i) scanf("%d", rk + i), sa[rk[i]] = i;
    rk[n + 1] = 1e9; a[sa[1]] = m = 1;
    for (int i = 2; i <= n; ++ i) {
        int r1 = sa[i - 1] + 1, r2 = sa[i] + 1;
        if (rk[r1] > rk[r2]) ++ m;
        a[sa[i]] = m;
    }
    for (int i = 1; i <= n; ++ i) {
        printf("%d%c", a[i], " \n"[i == n]);
    }
    return 0;
}
