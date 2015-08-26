#include <cstdio>
#include <cstring>
#include <algorithm>
#define lson (rt<<1)
#define rson (rt<<1|1)
#define mid ((l+r)>>1)
using namespace std;
typedef long long LL;
const int MAXN = 100000 + 10, MOD = 1e9 + 7;

struct Node {
    int cnt, mul, sum;
} SegTree[MAXN << 2];

struct Point {
    int a, b;
    bool operator < (const Point &rhs) const {
        return a < rhs.a || (a == rhs.a && b < rhs.b);
    }
} A[MAXN];

int C[MAXN], N, M;

LL pow_mod(LL a, LL n) {
    LL ret = 1;
    for (; n; n >>= 1) {
        if (n & 1) ret = ret * a % MOD;
        a = a * a % MOD;
    }
    return ret;
}

inline void update(int rt) {
    SegTree[rt].sum = (SegTree[lson].sum + SegTree[rson].sum) % MOD;
    SegTree[rt].cnt = SegTree[lson].cnt + SegTree[rson].cnt;
}

inline void pushdown(int rt) {
    if (SegTree[rt].mul) {
        LL mul = pow_mod(2, SegTree[rt].mul);
        SegTree[lson].sum = mul * SegTree[lson].sum % MOD;
        SegTree[rson].sum = mul * SegTree[rson].sum % MOD;
        SegTree[lson].mul += SegTree[rt].mul;
        SegTree[rson].mul += SegTree[rt].mul;
        SegTree[rt].mul = 0;
    }
}

void build(int rt, int l, int r) {
    SegTree[rt].mul = SegTree[rt].cnt = SegTree[rt].sum = 0;
    if (l + 1 == r) return;
    build(lson, l, mid); build(rson, mid, r);
}

int query_cnt(int rt, int l, int r, int L, int R) {
    if (L >= R) return 0;
    if (L <= l && R >= r) return SegTree[rt].cnt;
    pushdown(rt);
    int ret = 0;
    if (L < mid) ret += query_cnt(lson, l, mid, L, R);
    if (R > mid) ret += query_cnt(rson, mid, r, L, R);
    return ret;
}

int query_sum(int rt, int l, int r, int L, int R) {
    if (L >= R) return 0;
    if (L <= l && R >= r) return SegTree[rt].sum;
    pushdown(rt);
    int ret = 0;
    if (L < mid) ret += query_sum(lson, l, mid, L, R);
    if (R > mid) ret += query_sum(rson, mid, r, L, R);
    return ret % MOD;
}

void modify_range(int rt, int l, int r, int L, int R) {
    if (L <= l && R >= r) {
        SegTree[rt].mul ++;
        SegTree[rt].sum = SegTree[rt].sum * 2 % MOD;
        return;
    }
    pushdown(rt);
    if (L < mid) modify_range(lson, l, mid, L, R);
    if (R > mid) modify_range(rson, mid, r, L, R);
    update(rt);
}

void modify_single(int rt, int l, int r, int p, int v) {
    if (l + 1 == r) {
        SegTree[rt].sum = (SegTree[rt].sum + v) % MOD;
        SegTree[rt].cnt ++;
        return;
    }
    pushdown(rt);
    if (p < mid) modify_single(lson, l, mid, p, v);
    else modify_single(rson, mid, r, p, v);
    update(rt);
}

int main() {
    while (scanf("%d", &N) == 1) {
        for (int i = 0; i < N; ++ i) {
            scanf("%d%d", &A[i].a, &A[i].b);
            C[i] = A[i].b;
        }
        sort(A, A + N); sort(C, C + N);
        M = unique(C, C + N) - C;
        build(1, 0, M);
        int ret = 0;
        for (int i = 0; i < N; ++ i) {
            int idx = lower_bound(C, C + M, A[i].b) - C;
            int cnt = query_cnt(1, 0, M, 0, idx);
            LL mul = pow_mod(2, cnt), p2 = pow_mod(2, A[i].a), p3 = pow_mod(3, A[i].b);
            ret = (ret + mul * p2 % MOD * p3 % MOD) % MOD;
            LL sum = query_sum(1, 0, M, idx, M);
            ret = (ret + sum * p2 % MOD) % MOD;
            modify_range(1, 0, M, idx, M);
            modify_single(1, 0, M, idx, mul * p3 % MOD);
        }
        printf("%d\n", ret);
    }
    return 0;
}
