#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

typedef long long LL;

int main() {
    freopen("nim.in", "r", stdin);
    freopen("nim.out", "w", stdout);
    LL n, p[60]; p[0] = 1;
    for (int i = 1; i < 60; ++ i) p[i] = p[i - 1] * 2ll;
    scanf("%I64d", &n);
    LL sum = 0, K = 0;
    while (1) {
        K ++;
        sum += p[K] + (p[K] + p[K + 1]) * (p[K + 1] - p[K] - 1);
        if (sum >= n) break;
    }
    sum -= p[K] + (p[K] + p[K + 1]) * (p[K + 1] - p[K] - 1);
    n -= sum;
    if (n <= p[K]) {
        if (n == p[K]) puts("LOSE");
        else puts("WIN");
    } else {
        n -= p[K];
        LL left = 1, right = p[K] - 1;
        while (left < right) {
            LL mid = (left + right - 1) >> 1ll;
            LL tmp = 2ll * (p[K] * mid + (mid + 1) * mid / 2);
            if (tmp >= n) right = mid;
            else left = mid + 1;
        }
        LL tmp = 2ll * (p[K] * (left - 1) + (left - 1) * left / 2);
        if (n == tmp + p[K] + left || n == tmp + p[K] * 2 + left * 2) puts("LOSE");
        else puts("WIN");
    }

    fclose(stdin); fclose(stdout);
    return 0;
}
