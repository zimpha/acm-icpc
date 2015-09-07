#include <bits/stdc++.h>
#define lson (rt<<1)
#define rson (rt<<1|1)
#define mid ((l+r)>>1)

using namespace std;

const int MAXN = 100000 + 10;

struct Node {
    int mi, ma, rev;
} SegTree[MAXN << 2];

char S[MAXN], P[MAXN];
int val[MAXN], N, L;

inline char change(char c) {
    if (c >= 'a' && c <= 'z') return c - 'a' + 'A';
    else return c - 'A' + 'a';
}

int mismatch(int st) {
    int ret = 0;
    if (st + L > N) return -1;
    for (int i = 0; i < L; ++ i) {
        if (tolower(S[st + i]) != tolower(P[i])) return -1;
        else ret += (S[st + i] != P[i]);
    }
    return ret;
}

inline int tmax(int a, int b) {return max(a, b);}
inline int tmin(int a, int b) {
    if (a == -1) return b;
    else if (b == -1) return a;
    else return min(a, b);
}

inline void update(int rt) {
    SegTree[rt].mi = tmin(SegTree[lson].mi, SegTree[rson].mi);
    SegTree[rt].ma = tmax(SegTree[lson].ma, SegTree[rson].ma);
}

inline void Set(int rt) {
    SegTree[rt].rev ^= 1;
    if (SegTree[rt].mi != -1) SegTree[rt].mi = L - SegTree[rt].mi;
    if (SegTree[rt].ma != -1) SegTree[rt].ma = L - SegTree[rt].ma;
    swap(SegTree[rt].mi, SegTree[rt].ma);
}

inline void pushdown(int rt) {
    if (SegTree[rt].rev) {
        SegTree[rt].rev = 0;
        Set(lson); Set(rson);
    }
}

void build(int rt, int l, int r) {
    SegTree[rt].rev = 0;
    if (l + 1 == r) {
        SegTree[rt].mi = SegTree[rt].ma = val[l];
        return;
    }
    build(lson, l, mid); build(rson, mid, r);
    update(rt);
}

void reverse(int rt, int l, int r, int L, int R) {
    if (L <= l && R >= r) {
        Set(rt);
        return;
    }
    pushdown(rt);
    if (L < mid) reverse(lson, l, mid, L, R);
    if (R > mid) reverse(rson, mid, r, L, R);
    update(rt);
}

int query(int rt, int l, int r, int L, int R) {
    if (R <= L) return -1;
    if (L <= l && R >= r) return SegTree[rt].ma;
    pushdown(rt);
    int ret = -1;
    if (L < mid) ret = tmax(ret, query(lson, l, mid, L, R));
    if (R > mid) ret = tmax(ret, query(rson, mid, r, L, R));
    return ret;
}

void push(int rt, int l, int r, int p) {
    if (p < l || p >= r) return;
    if (l + 1 == r) {
        if (SegTree[rt].rev) {
            S[l] = change(S[l]);
            SegTree[rt].rev = 0;
        }
        return;
    }
    pushdown(rt);
    if (p < mid) push(lson, l, mid, p);
    else push(rson, mid, r, p);
}

void modify(int rt, int l, int r, int p, int v) {
    if (l + 1 == r) {
        SegTree[rt].mi = SegTree[rt].ma = v;
        return;
    }
    pushdown(rt);
    if (p < mid) modify(lson, l, mid, p, v);
    else modify(rson, mid, r, p, v);
    update(rt);
}

int main() {
    for (int Q; scanf("%d%s", &Q, P) == 2; ) {
        L = strlen(P); scanf("%s", S); N = strlen(S);
        for (int i = 0; i < N; ++ i) val[i] = mismatch(i);
        build(1, 0, N);
        while (Q --) {
            int l, r; scanf("%d%d", &l, &r); -- l, -- r;
            printf("%d\n", query(1, 0, N, l, r - L + 2));
            reverse(1, 0, N, l, r + 1);
            for (int i = l - L; i <= l + L; ++ i) push(1, 0, N, i);
            for (int i = r - L; i <= r + L; ++ i) push(1, 0, N, i);
            for (int i = l - L; i < l; ++ i) {
                if (i < 0 || i >= N || val[i] == -1) continue;
                val[i] = mismatch(i);
                modify(1, 0, N, i, val[i]);
            }
            for (int i = r - L; i <= r; ++ i) {
                if (i < 0 || i >= N || val[i] == -1) continue;
                val[i] = mismatch(i);
                modify(1, 0, N, i, val[i]);
            }
        }
    }
    return 0;
}
