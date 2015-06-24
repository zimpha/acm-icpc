#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    int ret = 1e9;
    for (int i = 0; i <= n; ++ i) {
        int tmp = i * a + b * ((n - i) / m + ((n - i) % m != 0));
        ret = min(ret, tmp);
    }
    cout << ret << endl;
    return 0;
}
