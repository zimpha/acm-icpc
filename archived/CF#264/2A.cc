#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, s; cin >> n >> s;
    int mx = 0, c = 0;
    for (int i = 0; i < n; ++ i) {
        int x, y; cin >> x >> y;
        if (x * 100 + y <= s * 100) c = 1, mx = max(mx, (100 - y) % 100);
    }
    if (!c) mx = -1;
    cout << mx << endl;
    return 0;
}
