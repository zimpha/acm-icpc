#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100 + 10;
int n, m, a[MAXN], b[MAXN];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    int ret = 1e9;
    for (int i = 2; i < n; ++ i) {
        m = 0;
        for (int j = 1; j < i; ++ j) b[++ m] = a[j];
        for (int j = i + 1; j <= n; ++ j) b[++ m] = a[j];
        int d = 0;
        for (int j = 1; j < m; ++ j) d = max(d, b[j + 1] - b[j]);
        ret = min(ret, d);
    }
    cout << ret << endl;
    return 0;
}
