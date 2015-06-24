#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

LL C[100][100];
LL m, k;

LL F(LL n) {
    LL ret = 0, cnt = 0;
    for (int i = 63; i >= 0; -- i) {
        if ((n >> i) & 1) ret += (k >= cnt ? C[i][k - cnt] : 0), ++ cnt;
    }
    return ret + (cnt == k);
}

int main() {
    cin >> m >> k;
    for (int i = 0; i < 100; ++ i) {
        C[i][i] = C[i][0] = 1;
        for (int j = 0; j < i; ++ j) {
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
        }
    }
    LL left = 1, right = 1000000000000000000ll;
    while (left < right) {
        LL mid = (left + right - 1) >> 1;
        LL cnt = F(mid << 1) - F(mid);
        if (cnt >= m) right = mid;
        else left = mid + 1;
    }
    cout << left << endl;
    return 0;
}
