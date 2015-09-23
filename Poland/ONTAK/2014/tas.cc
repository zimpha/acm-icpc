#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
const int MAXN = 100000 + 10;
int a[MAXN], n, k;
PII op[MAXN];

bool ok() {
    for (int i = 1; i <= n; ++ i) 
        if (a[i] != i) return false;
    return true;
}

bool dfs(int d) {
    if (d == 0) {
        return ok();
    }
    if (d == 1) {
        int x = 1, y = n;
        while (x == a[x] && x < n) ++ x;
        while (y == a[y] && y > x) -- y;
        reverse(a + x, a + y + 1);
        if (ok()) {
            op[d] = PII(x, y);
            return true;
        }
        reverse(a + x, a + y + 1);
        return false;
    }
    vector<int> v;
    v.push_back(1); v.push_back(n);
    for (int i = 2; i <= n; ++ i) {
        if (abs(a[i] - a[i - 1]) > 1) {
            if (i != n) v.push_back(i);
            if (i != 2) v.push_back(i - 1);
        }
    }
    if (v.size() > 14 || (d == 2 && v.size() > 10)) return false;
    sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 0; i < (int)v.size(); ++ i) {
        for (int j = i; j < (int)v.size(); ++ j) {
            reverse(a + v[i], a + v[j] + 1);
            if (dfs(d - 1)) {
                op[d] = PII(v[i], v[j]);
                return true;
            }
            reverse(a + v[i], a + v[j] + 1);
        }
    }
    return false;
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++ i) scanf("%d", a + i);
    if (dfs(k)) {
        puts("TAK");
        for (int i = k; i > 0; -- i) {
            printf("%d %d\n", op[i].first, op[i].second);
        }
    }
    else puts("NIE");
}
