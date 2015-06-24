#include <bits/stdc++.h>
using namespace std;

int x[2000];

int main() {
    int n, m, k, ret = 0;
    cin >> n >> m >> k;
    for (int i = 0; i <= m; ++ i) cin >> x[i];
    for (int i = 0; i < m; ++ i) ret += (__builtin_popcount(x[i] ^ x[m]) <= k);
    cout << ret << endl;
    return 0;
}
