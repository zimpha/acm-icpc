#include <bits/stdc++.h>
using namespace std;
typedef long long ULL;

int main() {
    int n, m;
    while (scanf("%d%d", &n, &m) == 2 && n) {
        if (n > m) swap(n, m);
        ULL N = n, M = m, K = (n + 1) / 2;
        ULL S1 = K * (K + 1) / 2;
        ULL S2 = K * (K + 1) * (2 * K + 1) / 6;
        ULL S3 = K * K * (K + 1) * (K + 1) / 4;
        cout << 8 * S3 - (4 * M + 4 * N + 20) * S2 + ((2 * N + 6) * (M + 2) + 2 * N + 4) * S1 - (N + 2) * (M + 2) * K << endl;
    }
    return 0;
}
