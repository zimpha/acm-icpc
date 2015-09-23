#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1000000;
LL a[MAXN], b[MAXN];

int main() {
    int T; scanf("%d", &T);
    while (T --) {
        LL n, k; scanf("%lld%lld", &n, &k);
        a[0] = b[0] = 1;
        int i = 0, j = 0;
        while (a[i] < n) {
            ++ i; a[i] = b[i - 1] + 1;
            while (a[j + 1] * k < a[i]) ++ j;
            if (a[j] * k < a[i]) b[i] = b[j] + a[i];
            else b[i] = a[i];
        }
        if (a[i] == n) puts("R");
        else puts("C");
    }
    return 0;
}
