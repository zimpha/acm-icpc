#include <bits/stdc++.h>
#define MP make_pair
using namespace std;
const int MAXN = 100000 + 10;
typedef pair<int, int> PII;
typedef pair<PII, int> actor;
int a[MAXN], b[MAXN], c[MAXN], d[MAXN], k[MAXN];
int ret[MAXN];
set<actor> S;
vector<PII> ev;
int n, m;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i) {
        scanf("%d%d", a + i, b + i);
        ev.push_back(PII(a[i], i));
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; ++ i) {
        scanf("%d%d%d", c + i, d + i, k + i);
        ev.push_back(PII(c[i], -i));
    }
    sort(ev.begin(), ev.end()); S.clear();
    bool flag = true;
    for (int i = 0; i < (int)ev.size(); ++ i) {
        int x = ev[i].first, id = ev[i].second;
        if (id < 0) {
            id = -id;
            S.insert(MP(PII(d[id], k[id]), id));
        }
        else {
            int rr = b[id];
            auto it = S.lower_bound(MP(PII(rr, 0), 0));
            if (it == S.end()) {
                flag = false;
                break;
            }
            rr = it->second;
            ret[id] = rr;
            S.erase(MP(PII(d[rr], k[rr]), rr));
            k[rr] --;
            if (k[rr]) S.insert(MP(PII(d[rr], k[rr]), rr));
        }
    }
    if (flag) {
        puts("YES");
        for (int i = 1; i <= n; ++ i) {
            printf("%d%c", ret[i], " \n"[i == n]);
        }
    }
    else puts("NO");
    return 0;
}