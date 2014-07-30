#include <cstdio>
typedef long long LL;

const int MAXN = 100000 + 10;
int f[MAXN], g[MAXN];

int main() {
    int n, p; scanf("%d%d", &n, &p);
    -- n; f[n] = 1; g[0] = 1;
    for (int i = n - 1; i >= 0; -- i) {
        f[i] = (LL)f[i + 1] * (i + 1) % p;
        g[0] = (LL)g[0] * (p - 1) % p;
    }
    for (int i = 0; i < n; ++ i) {
        g[i + 1] = LL(n - i) * (n + i + 1) / 2 % p * g[i] % p;
        g[i + 1] = (LL)g[i + 1] * (p - 1) % p;
    }
    int ret = 0;
    for (int i = 0; i <= n; ++ i) {
        ret += (LL)g[i] * f[i] % p;
        ret %= p;
    }
    printf("%d\n", ret);
    return 0;
}
