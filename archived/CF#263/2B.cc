#include <bits/stdc++.h>
using namespace std;

int cnt[26], n, k;
string s;

int main() {
    cin >> n >> k;
    cin >> s;
    for (int i = 0; i < n; ++ i) cnt[s[i] - 'A'] ++;
    sort(cnt, cnt + 26, greater<int>());
    long long ret = 0;
    for (int i = 0; i < 26 && k; ++ i) {
        if (k >= cnt[i]) {
            k -= cnt[i];
            ret += 1ll * cnt[i] * cnt[i];
        }
        else ret += 1ll * k * k, k = 0;
    }
    cout << ret << endl;
}
