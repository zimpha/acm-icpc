#include <bits/stdc++.h>
using namespace std;

int main() {
    int T; cin >> T;
    while (T --) {
        long long n, ret, ps = 0; cin >> n;
        ret = n * n;
        for (long long i = 1, j; i <= n; i = j + 1) {
            j = n / (n / i);
            ret -= n / i * ((1 + j) * j / 2 - ps);
            ps = j * (1 + j) / 2;
        }
        cout << ret << endl;
    }
    return 0;
}
