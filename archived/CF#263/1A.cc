#include <bits/stdc++.h>
using namespace std;

int a[400000];

int main() {
    long long sum = 0, ret = 0;
    int n; cin >> n;
    for (int i = 0; i < n; ++ i) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a, a + n);
    for (int i = 0; i < n; ++ i) {
        ret += sum + a[i];
        sum -= a[i];
    }
    cout << ret - a[n - 1] << endl;
}
