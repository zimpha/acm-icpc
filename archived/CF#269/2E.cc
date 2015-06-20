#include <bits/stdc++.h>
#define lson (rt<<1)
#define rson (rt<<1|1)
#define mid ((l+r)>>1)
using namespace std;
typedef long long LL;
const int MAXN = 400000 + 10, inf = 1e9;

vector<int> CY;
int X1[MAXN], X2[MAXN], Y1[MAXN], Y2[MAXN], n;
LL ret;

struct Event { //type 0: st, 1: ver, 2: ed
    int pos, type, id;
    Event() {}
    Event(int _p, int _t, int _i): pos(_p), type(_t), id(_i) {}
    bool operator < (const Event &rhs) const {
        if (pos != rhs.pos) return pos < rhs.pos;
        if (type != rhs.type) return type < rhs.type;
        return Y1[id] < Y1[rhs.id];
    }
};

vector<Event> events;

struct Interval {
    int l, r, id;
    Interval(int l = 0, int r = 0, int id = 0): l(l), r(r), id(id) {}
    bool operator < (const Interval &rhs) const {
        if (l != rhs.l) return l < rhs.l;
        return r < rhs.r;
    }
};

set<Interval> S;
set<int> YS;

namespace SegTree {
    int u[MAXN << 2];
    void init() {
        memset(u, 0, sizeof(u));
    }
    void modify(int rt, int l, int r, int x, int v) {
        if (l == r) {u[rt] += v; return;}
        if (x <= mid) modify(lson, l, mid, x, v);
        else modify(rson, mid + 1, r, x, v);
        u[rt] = u[lson] + u[rson];
    }
    int get(int rt, int l, int r, int L, int R) {
        if (L <= l && R >= r) return u[rt];
        int ret = 0;
        if (L <= mid) ret += get(lson, l, mid, L, R);
        if (R > mid) ret += get(rson, mid + 1, r, L, R);
        return ret;
    }
}

namespace DSU {
    int dsu[MAXN];
    LL sum[MAXN];
    void init() {
        for (int i = 0; i < n * 2; ++ i) dsu[i] = i;
        for (int i = 0; i < n * 2; ++ i) sum[i] = 0;
    }
    void add(int x, LL v) {
        sum[x] += v;
    }
    int get(int x) {
        if (x != dsu[x]) dsu[x] = get(dsu[x]);
        return dsu[x];
    }
    bool merge(int x, int y) {
        x = get(x); y = get(y);
        if (x == y) return false;
        dsu[x] = y; sum[y] += sum[x];
        return true;
    }
}

int YS_prev(int y) {return *(-- YS.upper_bound(y));}
int YS_next(int y) {return *YS.lower_bound(y);}

void START(int id) {
    auto it = S.lower_bound(Interval(Y1[id], inf));
    if (it != S.begin()) {
        -- it;
        if (it->l <= Y1[id] && it->r >= Y1[id]) {
            auto now = *it; S.erase(it);
            S.insert(Interval(now.l, YS_prev(Y1[id] - 1), now.id));
            S.insert(Interval(YS_next(Y1[id] + 1), now.r, now.id));
        }
    }
    DSU::add(id, X2[id] - X1[id]);
    S.insert(Interval(Y1[id], Y1[id], id));
    SegTree::modify(1, 0, CY.size() - 1, Y1[id], 1);
    YS.insert(Y1[id]);
}

bool check(const Interval &now, int id) {
    int l = max(Y1[id], now.l), r = min(Y2[id], now.r);
    if (l > r) return false;
    return SegTree::get(1, 0, CY.size() - 1, l, r) > 0;
}

void VERTICAL(int id) {
    int cross = SegTree::get(1, 0, CY.size() - 1, Y1[id], Y2[id]);
    if (!cross) ret = max(ret, (LL)CY[Y2[id]] - CY[Y1[id]]);
    else {
        auto it = S.lower_bound(Interval(Y1[id], inf));
        if (it != S.begin()) -- it;
        while (!check(*it, id)) ++ it;
        auto now = *it; S.erase(it ++);
        int dist = 1;
        while (it != S.end() && check(*it, id)) {
            if (DSU::merge(now.id, it->id)) ++ dist;
            now.r = it->r;
            S.erase(it ++);
        }
        int u = DSU::get(now.id);
        LL cost = CY[Y2[id]] - CY[Y1[id]] - cross + dist;
        DSU::add(u, cost);
        S.insert(now);
    }
}

void END(int id) {
    auto it = S.lower_bound(Interval(Y1[id], inf)); -- it;
    SegTree::modify(1, 0, CY.size() - 1, Y1[id], -1); YS.erase(Y1[id]);
    if (SegTree::get(1, 0, CY.size() - 1, it->l, it->r) == 0) {
        ret = max(ret, DSU::sum[DSU::get(it->id)]);
        S.erase(it);
    }
    else if (Y1[id] == it->l) {
        auto now = Interval(YS_next(it->l + 1), it->r, it->id);
        S.erase(it); S.insert(now);
    }
    else if (Y1[id] == it->r) {
        auto now = Interval(it->l, YS_prev(it->r - 1), it->id);
        S.erase(it); S.insert(now);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++ i) {
        cin >> X1[i] >> Y1[i] >> X2[i] >> Y2[i];
        CY.push_back(Y1[i]); CY.push_back(Y2[i]);
    }
    sort(CY.begin(), CY.end());
    CY.erase(unique(CY.begin(), CY.end()), CY.end());
    for (int i = 0; i < n; ++ i) {
        Y1[i] = lower_bound(CY.begin(), CY.end(), Y1[i]) - CY.begin();
        Y2[i] = lower_bound(CY.begin(), CY.end(), Y2[i]) - CY.begin();
        if (Y1[i] != Y2[i]) {
            events.push_back(Event(X1[i], 1, i));
        }
        else {
            events.push_back(Event(X1[i], 0, i));
            events.push_back(Event(X2[i], 2, i));
        }
    }
    sort(events.begin(), events.end());
    DSU::init(); SegTree::init();
    for (auto &event : events) {
        if (event.type == 0) START(event.id);
        else if (event.type == 1) VERTICAL(event.id);
        else END(event.id);
    }
    cout << ret << endl;
    return 0;
}
