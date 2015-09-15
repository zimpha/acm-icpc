#include <bits/stdc++.h>
#define lson (rt<<1)
#define rson (rt<<1|1)
#define mid ((l+r)>>1)
using namespace std;
const int SIZE = 40000 + 10;

struct ST {
    int mx[SIZE], sgn;
    void build(int rt, int l, int r) {
        if (l + 1 == r) {mx[rt] = r * sgn; return;}
        build(lson, l, mid);
        build(rson, mid, r);
        mx[rt] = max(mx[lson], mx[rson]);
    }
    void ins(int rt, int l, int r, int p) {
        if (l + 1 == r) {mx[rt] ++; return;}
        if (p <= mid) ins(lson, l, mid, p);
        else ins(rson, mid, r, p);
        mx[rt] = max(mx[lson], mx[rson]);
    }
    int ask(int rt, int l, int r, int L, int R) {
        if (L <= l && R >= r) return mx[rt];
        int ret = -1e9;
        if (L < mid) ret = max(ret, ask(lson, l, mid, L, R));
        if (R > mid) ret = max(ret, ask(rson, mid, r, L, R));
        return ret;
    }
}T[2];

int solve(int w, int h, int n) {
    T[0].sgn = 1; T[1].sgn = -1;
    T[0].build(1, 0, w); T[1].build(1, 0, w);
    for (int i = 1; i <= n; ++ i) {
        int l, r, mx; scanf("%d%d", &l, &r);
        if (l <= r) mx = T[0].ask(1, 0, w, l - 1, r) - r;
        else  mx = T[1].ask(1, 0, w, r - 1, l) + r;
        if (abs(l - r) >= h - max(mx, 0)) return i;
        T[0].ins(1, 0, w, r); T[1].ins(1, 0, w, r);
    }
    return 0;
}

int main() {
    int w, h, n; scanf("%d%d%d", &w, &h, &n);
    cout << solve(w, h, n) << endl;
    return 0;
}