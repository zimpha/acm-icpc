#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    int mx = 0;
    for (int i = 0; i < n; ++ i) {
        int x; cin >> x;
        mx = max(x, mx);
    }
    cout << mx << endl;
    return 0;
}
