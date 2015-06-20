#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<string> f(n), s(n), name(n);
    vector<int> p(n);
    for (int i = 0; i < n; ++ i) {
        cin >> f[i] >> s[i];
        if (f[i] > s[i]) swap(f[i], s[i]);
    }
    for (int i = 0; i < n; ++ i) {
        cin >> p[i];
        p[i] --;
    }
    name[0] = f[p[0]];
    bool flag = true;
    for (int i = 1; i < n && flag; ++ i) {
        if (f[p[i]] > name[i - 1]) name[i] = f[p[i]];
        else {
            if (s[p[i]] > name[i - 1]) name[i] = s[p[i]];
            else flag = false;
        }
    }
    if (flag) cout << "YES" << endl;
    else cout << "NO" << endl;
}
