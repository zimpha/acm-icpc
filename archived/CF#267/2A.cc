#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int ret = 0;
    while (n --) {
        int p, q; cin >> p >> q;
        if (p + 2 <= q) ++ ret;
    }
    cout << ret << endl;
    return 0;
}
