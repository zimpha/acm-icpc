#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MOD = 1e9 + 7;

vector<pair<int, string> > q;
string s;
int n;

int main() {
    LL val[10], pow[10];
    ios::sync_with_stdio(false);
    cin >> s >> n;
    for (int i = 0; i < n; ++ i) {
        string buf; cin >> buf;
        q.push_back(make_pair(buf[0] - '0', buf.substr(3, buf.size() - 3)));
    }
    reverse(q.begin(), q.end());
    for (int i = 0; i < 10; ++ i) val[i] = i, pow[i] = 10;
    for (auto &x : q) {
        int &d = x.first;
        string &rep = x.second;
        LL tv = 0, tp = 1;
        for (int i = 0; i < (int)rep.size(); ++ i) {
            tv = (tv * pow[rep[i] - '0'] % MOD + val[rep[i] - '0']) % MOD;
            tp = tp * pow[rep[i] - '0'] % MOD;
        }
        val[d] = tv; pow[d] = tp;
    }
    LL ret = 0;
    for (int i = 0; i < (int)s.size(); ++ i) {
        ret = (ret * pow[s[i] - '0'] % MOD + val[s[i] - '0']) % MOD;
    }
    cout << ret << endl;
    return 0;
}
