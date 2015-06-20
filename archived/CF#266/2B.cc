#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, a, b;
    cin >> n >> a >> b; n *= 6;
    long long ret = 1ll << 60, l, r, is = 0;
    if (a > b) swap(a, b), is = 1;
    for (long long i = 1; i <= n; ++ i) {
        long long x = i, y = (n + i - 1) / i;
        if (y < x) break;
        x = max(x, a); y = max(y, b);
        if (x * y < ret) ret = x * y, l = x, r = y;
    }
    if (is) swap(l, r);
    cout << ret << endl << l << " " << r << endl;
}
