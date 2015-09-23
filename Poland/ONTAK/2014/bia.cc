#include <bits/stdc++.h>
#define PB push_back
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 10000 + 10;
int x[MAXN], y[MAXN];
int n, m, k;

LL solve(int lx) {
    map<int, int> mp;
    map<int, int>::iterator it;
    vector<PII> vc, sc;
    for (int i = 0; i < k; ++ i) {
        if (x[i] <= lx) {
            if (!mp.count(y[i])) mp[y[i]] = lx;
            mp[y[i]] = min(mp[y[i]], lx - x[i]);
        }
    }
    for (it = mp.begin(); it != mp.end(); ++ it) sc.PB(*it);
    for (int i = 0; i < (int)sc.size(); ++ i) {
        if (i == 0) {
            if (sc[0].first > 1) vc.PB(PII(sc[i].first - 1, lx));
        }
        else {
            if (sc[i].first != sc[i - 1].first) vc.PB(PII(sc[i].first - 1, lx));
        }
        vc.PB(sc[i]);
    }
    if (sc.empty()) vc.PB(PII(m, lx));
    else if (sc.back().first < m) vc.PB(PII(m, lx));
    sc.assign(vc.size() + 10, PII(0, 0));
    LL ret = 0, sum = 0;
    for (int i = 0, t = 0; i < (int)vc.size(); ++ i) {
        while (t && sc[t].second >= vc[i].second) {
            sum -= sc[t].second * (sc[t].first - sc[t - 1].first);
            -- t;
        }
        LL l, w = vc[i].second;
        if (i) l = vc[i].first - vc[i - 1].first;
        else l = vc[i].first;
        sum += w * (vc[i].first - sc[t].first);
        ret += sum * l - w * l * (l - 1) / 2;
        sc[++ t] = vc[i];
    }
    return ret;
}

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < k; ++ i) scanf("%d%d", x + i, y + i);
    LL ret = 0;
    for (int i = 1; i <= n; ++ i) ret += solve(i);
    cout << ret << endl;
    return 0;
}
