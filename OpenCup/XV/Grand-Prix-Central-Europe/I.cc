#include <bits/stdc++.h>
#define lson (rt<<1)
#define rson (rt<<1|1)
#define mid ((l+r)>>1)
using namespace std;
typedef pair<int, int> PII;
const int MAXN = 200000 + 10;
vector<int> C[MAXN];
int p[MAXN], t[MAXN];
PII loc[MAXN];
bool vis[MAXN];
int n, m, ret;

struct ST {
    vector<int> u;
    void init(int n) {
        u.assign(n << 2, 0);
    }
    void ins(int rt, int l, int r, int p, int v) {
        if (l == r) {u[rt] = v; return;}
        if (p <= mid) ins(lson, l, mid, p, v);
        else ins(rson, mid + 1, r, p, v);
        u[rt] = u[rson] + u[lson];
    }
    int get(int rt, int l, int r, int L, int R) {
        if (L <= l && R >= r) return u[rt];
        int ret = 0;
        if (L <= mid) ret += get(lson, l, mid, L, R);
        if (R > mid) ret += get(rson, mid + 1, r, L, R);
        return ret;
    }
    int find(int rt, int l, int r, int k) {
        if (l == r) return l;
        if (k <= u[lson]) return find(lson, l, mid, k);
        else return find(rson, mid + 1, r, k - u[lson]);
    }
    int get(int rt, int l, int r, int p) {
        if (l == r) return u[rt];
        if (p <= mid) return get(lson, l, mid, p);
        else return get(rson, mid + 1, r, p);
    }
    void print(int rt, int l, int r) {
        if (l == r) {cout << u[rt] << " "; return;}
        print(lson, l, mid);
        print(rson, mid + 1, r);
    }
} T[MAXN];

int cc(int l) {return (l + 1) >> 1;}

void gao1(int id, int p) {//0 -> 1
    ST &S = T[id];
    int n = C[id].size() - 1;
    int sum = S.get(1, 1, n, 1, p), tot = S.get(1, 1, n, 1, n);
    if (tot == 0) {
        ret += cc(n - 1) - cc(n);
        S.ins(1, 1, n, p, 1);
        return;
    }
    if (sum == 0) {
        int l = S.find(1, 1, n, 1), r = S.find(1, 1, n, tot);
        int len = n - (r - l + 1);
        ret -= cc(len);
        int len1 = n - (r - p + 1);
        int len2 = l - p - 1;
        ret += cc(len1) + cc(len2);
    }
    else if (sum == tot) {
        int l = S.find(1, 1, n, 1), r = S.find(1, 1, n, sum);
        int len = n - (r - l + 1);
        ret -= cc(len);
        int len1 = p - r - 1;
        int len2 = n - (p - l + 1);
        ret += cc(len1) + cc(len2);
    }
    else {
        int l = S.find(1, 1, n, sum), r = S.find(1, 1, n, sum + 1);
        int len = r - l - 1;
        ret -= cc(len);
        int len1 = p - l - 1;
        int len2 = r - p - 1;
        ret += cc(len1) + cc(len2);
    }
    S.ins(1, 1, n, p, 1);
}

void gao2(int id, int p) {//1 -> 0
    ST &S = T[id];
    int n = C[id].size() - 1;
    int sum = S.get(1, 1, n, 1, p), tot = S.get(1, 1, n, 1, n);
    if (tot == 1) {
        ret += cc(n) - cc(n - 1);
        S.ins(1, 1, n, p, 0);
        return;
    }
    if (sum == 1) {
        int l = S.find(1, 1, n, tot), r = S.find(1, 1, n, 2);
        int len1 = n - (l - p + 1);
        int len2 = r - p - 1;
        ret -= cc(len1) + cc(len2);
        ret += cc(len1 + len2 + 1);
    }
    else if (sum == tot) {
        int l = S.find(1, 1, n, 1), r = S.find(1, 1, n, tot - 1);
        int len1 = n - (p - l + 1);
        int len2 = p - r - 1;
        ret -= cc(len1) + cc(len2);
        ret += cc(len1 + len2 + 1);
    }
    else {
        int l = S.find(1, 1, n, sum - 1), r = S.find(1, 1, n, sum + 1);
        int len1 = p - l - 1;
        int len2 = r - p - 1;
        ret -= cc(len1) + cc(len2);
        ret += cc(len1 + len2 + 1);
    }
    S.ins(1, 1, n, p, 0);
}

void modify(const vector<int> &v, int id, int p) {
    int n = v.size() - 1, nid, pid;
    if (p > n) p -= n; nid = v[p];
    if (p == 1) pid = v[n];
    else pid = v[p - 1];
    int ps = T[id].get(1, 1, n, p), ns;
    if (t[pid] < t[nid]) ns = 0;
    else ns = 1;
    if (ns == ps) return;
    else if (ps == 0) gao1(id, p);
    else gao2(id, p);
}

int main() {
    scanf("%d", &n); m = 0; ret = 0;
    for (int i = 1; i <= n; ++ i) scanf("%d", p + i);
    for (int i = 1; i <= n; ++ i) scanf("%d", t + i);
    for (int i = 1; i <= n; ++ i) {
        if (!vis[i]) {
            C[m].clear(); C[m].push_back(i); vis[i] = true;
            for (int j = p[i]; j != i; j = p[j]) {
                loc[j] = PII(m, C[m].size());
                C[m].push_back(j); vis[j] = true;
            }
            loc[i] = PII(m, C[m].size());
            C[m].push_back(i);
            ++ m;
        }
    }
    for (int i = 0; i < m; ++ i) {
        int l = C[i].size() - 1;
        T[i].init(l);
        vector<int> v;
        for (int j = 1; j <= l; ++ j) {
            int x = C[i][j - 1], y = C[i][j], r = 0;
            if (t[x] < t[y]) r = 0;
            else r = 1;
            v.push_back(r);
            T[i].ins(1, 1, l, j, r);
        }
        int j = 0;
        while (j < (int)v.size() && v[j] == 0) ++ j;
        rotate(v.begin(), v.begin() + j, v.end());
        for (int j = 0, k; j < (int)v.size(); j = k) {
            for (k = j; k < (int)v.size() && v[k] == v[j]; ++ k);
            if (v[j] == 0) ret += cc(k - j);
        }
    }
    printf("%d\n", ret);
    int Q; scanf("%d", &Q);
    for (int _ = 0; _ < Q; ++ _) {
        int k, v; scanf("%d%d", &k, &v);
        t[k] = v;
        int cid = loc[k].first, pos = loc[k].second;
        modify(C[cid], cid, pos);
        modify(C[cid], cid, pos + 1);
        printf("%d\n", ret);
    }
    return 0;
}