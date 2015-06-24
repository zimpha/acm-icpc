#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2000 + 10;
typedef long long LL;

LL f[MAXN << 1], g[MAXN << 1], a[MAXN][MAXN];
LL sol[2][3];

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < n; ++ j) {
            cin >> a[i][j];
            f[i + j] += a[i][j]; g[i - j + n] += a[i][j];
        }
    }
    sol[0][0] = sol[1][0] = -1;
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < n; ++ j) {
            int o = (i + j) & 1;
            LL c = f[i + j] + g[i - j + n] - a[i][j];
            if (c > sol[o][0]) {
                sol[o][0] = c;
                sol[o][1] = i + 1;
                sol[o][2] = j + 1;
            }
        }
    }
    cout << sol[0][0] + sol[1][0] << endl;
    cout << sol[0][1] << " " << sol[0][2] << " " << sol[1][1] << " " << sol[1][2] << endl;
    return 0;
}
