#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 100000 + 10;
int t[MAXN], n, k;

bool check(LL lim) {
    LL cnt = 0;
    for (int i = 0; i < n; ++ i) {
        cnt += lim / t[i];
        if (cnt >= k) return true;
    }
    return false;
}

int main() {
    int T; scanf("%d", &T);
    while (T --) {
        scanf("%d%d", &n, &k);
        for (int i = 0; i < n; ++ i) scanf("%d", t + i);
        LL left = 1, right = (LL)1ll<<60;
        while (left < right) {
            LL mid = (left + right - 1) >> 1;
            if (check(mid)) right = mid;
            else left = mid + 1;
        }
        printf("%lld\n", right);
    }
    return 0;
}