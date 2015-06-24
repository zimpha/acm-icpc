#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s, t;
    cin >> n >> s;
    t = s;
    for (int i = 0, c = 1; i < n; ++ i) {
        s[i] += c;
        if (s[i] == '2') s[i] = '0', c = 1;
        else c = 0;
    }
    int cnt = 0;
    for (int i = 0; i < n; ++ i) cnt += (s[i] != t[i]);
    cout << cnt << endl;
    return 0;
}
