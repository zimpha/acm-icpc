#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2000000 + 10;
typedef long long LL;
int a[MAXN], b[MAXN], s[MAXN];
int n, m;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i) {
        scanf("%d", a + i);
        a[i + n] = a[i];
    }
    for (int i = 1; i <= n * 2; ++ i) s[i] = s[i - 1] + a[i];
    int sum = s[n] / 2; m = 0;
    if (s[n] & 1) {puts("0"); return 0;}
    for (int i = 1, j = 1; i <= n; ++ i) {
        while (j < 2 * n && s[j] - s[i - 1] < sum) ++ j;
        if (s[j] - s[i - 1] == sum) a[m] = i, b[m ++] = j;
    }
    LL ret = 0;
    if (m < 2) {puts("0"); return 0;}
    for (int i = 0, j = 0; i < m && a[i] < n; ++ i) {
        while (j < m && a[j] <= b[i] && s[a[j] - 1] - s[a[i] - 1] < sum / 2) ++ j;
        if (j < m && a[j] <= b[i]) {
            LL x = s[a[j] - 1] - s[a[i] - 1];
            ret = max(ret, x * (sum - x));
            x = s[a[j - 1] - 1] - s[a[i] - 1];
            ret = max(ret, x * (sum - x));
        }
    }
    printf("%lld\n", ret);
    return 0;
}
