#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    vector<int> f(n);
    for (int i = 0; i < n; ++ i) cin >> f[i];
    sort(f.begin(), f.end(), greater<int>());
    int ret = 0;
    for (int i = 0; i < n; i += k) {
        ret += 2 * f[i] - 2;
    }
    cout << ret << endl;
    return 0;
}
