#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m), fail(m);
    for (int i = 0; i < n; ++ i) cin >> a[i];
    for (int i = 0; i < m; ++ i) cin >> b[i];
    for (int i = 0; i + 1 < n; ++ i) a[i] = a[i + 1] - a[i];
    for (int i = 0; i + 1 < m; ++ i) b[i] = b[i + 1] - b[i];
    fail[0] = -1; m --; n --;
    a[n] = b[m] = 0;
    for (int i = 1, j; i < m; ++ i) {
        for (j = fail[i - 1]; j >= 0 && b[j + 1] != b[i]; ) j = fail[j];
        fail[i] = (b[j + 1] == b[i]) ? ++ j : j;
    }
    int ret = 0;
    for (int i = 0, j = -1; i < n; ++ i) {
        while (j >= 0 && b[j + 1] != a[i]) j = fail[j];
        if (b[j + 1] == a[i]) ++ j;
        if (j + 1 == m) {
            ++ ret;
            if (j >= 0) j = fail[j];
        }
    }
    if (m == 0) ret = n + 1;
    cout << ret << endl;
    return 0;
}
