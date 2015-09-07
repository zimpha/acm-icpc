#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int MAXN = 100000 + 10;

LL A[MAXN], val[MAXN];
int L[MAXN], N;

int main() {
    int T; scanf("%d", &T);
    while (T --) {
        scanf("%d", &N);
        for (int i = 0; i < N; ++ i) scanf("%lld", A + i);
        LL ret = A[0]; L[0] = 0; val[0] = A[0];
        for (int i = 1; i < N; ++ i) {
            L[i] = i; val[i] = A[i];
            for (int cur = i; cur >= 0; cur = L[cur] - 1) {
                val[cur] = __gcd(val[cur], A[i]);
                while (L[cur] - 1 >= 0 && __gcd(A[i], val[L[cur] - 1]) == __gcd(A[i], val[cur])) {
                    L[cur] = L[L[cur] - 1];
                }
                ret = max(ret, val[cur] * (i - L[cur] + 1));
            }
        }
        printf("%lld\n", ret);
    }
    return 0;
}
