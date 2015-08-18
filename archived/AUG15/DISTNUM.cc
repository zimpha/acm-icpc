#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 200000 + 10, MOD = 1e9 + 7;

int a[MAXN], s[MAXN], n, q;

inline int sqr(LL x) {return x * x % MOD;}
inline int cub(LL x) {return sqr(x) * x % MOD;}

namespace Treap {
  const int INF = ~0U>>1;
  struct Node {
    int val, pri, sz;
    vector<int> pt;
    Node* ch[2];
    void update() {sz=ch[0]->sz+ch[1]->sz+val;}
  } pool[MAXN], *rt, *null, *cnt, *seq[MAXN];
  int tot;
  Node* newNode(int v, int pri = -1) {
    cnt->sz = 1; cnt->val = 1;
    cnt->pt.push_back(v);
    cnt->ch[0] = cnt->ch[1] = null;
    if (pri == -1) cnt->pri = rand() - 1;
    else cnt->pri = pri;
    return cnt ++;
  }
  void rot(Node* &o,int d) { //d = 1, left; d = 0, right
    Node* k=o->ch[d];
    o->ch[d]=k->ch[!d]; k->ch[!d]=o;
    o->update(); k->update(); o=k;
  }
  void ins_kth(Node *&o, int k, int v) {// become kth after insert
    if (o == null) o = newNode(v);
    else {
      int c = o->ch[0]->sz, d;
      if (c + o->val >= k) ins_kth(o->ch[d = 0], k, v);
      else ins_kth(o->ch[d = 1], k - c - o->val, v);
      if (o->ch[d]->pri < o->pri) rot(o, d);
      else o->update();
    }
  }
  void del(Node *o, int k, int v) {// del k-th, k >= 1
    if (o->ch[0]->sz + o->val == k && o->val == 1) {
      o->val = 0; o->update();
      o->pt.push_back(v);
      return;
    }
    if (o->ch[0]->sz >= k) del(o->ch[0], k, v);
    else del(o->ch[1], k - o->ch[0]->sz - o->val, v);
    o->update();
  }
  Node* kth(Node* o, int k, int v) { //k-th node, k >= 1
    if (o->ch[0]->sz + o->val == k && o->val == 1) {
      o->pt.push_back(v);
      return o;
    }
    if (o->ch[0]->sz >= k) return kth(o->ch[0], k, v);
    else return kth(o->ch[1], k - o->ch[0]->sz - o->val, v);
  }
  Node* build(int l, int r, int pri[]) {
    if (l > r) return null;
    if (l == r) return newNode(-l, pri[tot ++]);
    int m = (l + r) >> 1;
    Node *p = newNode(-m, pri[tot ++]);
    p->ch[0] = build(l, m - 1, pri);
    p->ch[1] = build(m + 1, r, pri);
    p->update(); return p;
  }
  void travel(Node *o) {
    if (o == null) return;
    travel(o->ch[0]);
    seq[tot ++] = o;;
    travel(o->ch[1]);
  }
  void init(int n) {
    static int pri[MAXN];
    for (int i = 0; i < n; ++ i) pri[i] = rand() - 1;
    cnt = pool; null = newNode(0);
    null->sz = null->val = 0; null->pt.clear();
    null->ch[0] = null->ch[1] = null;
    null->pri = INF;
    tot = 0; sort(pri, pri + n);
    rt = build(1, n, pri);
    tot = 0;
  }
}

struct W {
  LL v[4];
  W() {memset(v, 0, sizeof(v));}
  W(LL a) {
    if (a == 0) memset(v, 0, sizeof(v));
    else if (a > 0) {
      v[0] = 1; v[1] = a; v[2] = sqr(a); v[3] = cub(a);
    }
    else {
      v[0] = -1; v[1] = a; v[2] = -sqr(-a); v[3] = -cub(-a);
    }
  }
  W(LL a, LL b, LL c, LL d) {
    v[0] = a; v[1] = b; v[2] = c; v[3] = d;
  }
  W& operator += (const W &r) {
    v[0] += r.v[0]; v[1] += r.v[1];
    v[2] += r.v[2]; v[3] += r.v[3];
    return *this;
  }
  W& operator -= (const W &r) {
    v[0] -= r.v[0]; v[1] -= r.v[1];
    v[2] -= r.v[2]; v[3] -= r.v[3];
    return *this;
  }
} ans[MAXN], bit[MAXN];

struct Query {
  int t, x, y;
} ql[MAXN];

LL pm(LL a, LL n) {
  LL r(1);
  for (; n; n >>= 1) {
    if (n & 1) r = r * a % MOD;
    a = a * a % MOD;
  }
  return r;
}

struct FastIO {
  static const int S = 1310720;
  int wpos; char wbuf[S];
  FastIO() : wpos(0) {}
  inline int xchar() {
    static char buf[S];
    static int len = 0, pos = 0;
    if (pos == len)
      pos = 0, len = fread(buf, 1, S, stdin);
    if (pos == len) return -1;
    return buf[pos ++];
  }
  inline int xint() {
    int c = xchar(), x = 0;
    while (c <= 32) c = xchar();
    for (;'0' <= c && c <= '9'; c = xchar()) x = x * 10 + c - '0';
    return x;
  }
  ~FastIO() {
    if (wpos) fwrite(wbuf, 1, wpos, stdout), wpos = 0;
  }
} io;

struct Event {
 int type, t, x, y, loc;
 bool operator < (const Event &rhs) const {
  return t < rhs.t || (t == rhs.t && type > rhs.type);
 }
 Event() {}
 Event(int type, int t, int x, int y, int loc = 0): 
  type(type), t(t), x(x), y(y), loc(loc) {}
} E[MAXN << 2], ls[MAXN << 2];

void solve(int l, int r, int n) {
  if (l + 1 == r) return;
  if (r - l <= 700) {
    int tot(0);
    for (int i = l; i < r; ++ i) {
      if (E[i].type == 0) ls[tot ++] = E[i];
      else {
        for (int j = 0; j < tot; ++ j) {
          if (ls[j].t < E[i].t && E[i].x <= ls[j].x && ls[j].x < E[i].y) {
            ans[E[i].loc] += W(ls[j].y);
          }
        }
      }
    }
    return;
  }
  int mid = (l + r) >> 1;
  solve(l, mid, n);
  solve(mid, r, n);
  bool f1(0), f2(0);
  int tot(0);
  for (int i = l; i < mid; ++ i) {
    if (E[i].type == 0) ls[tot ++] = E[i], f1 = 1;
  }
  if (!f1) return;
  for (int i = mid; i < r; ++ i) {
    if (E[i].type == 1) ls[tot ++] = E[i], f2 = 1;
  }
  if (!f2) return;
  sort(ls, ls + tot);
  for (int i = 0; i < tot; ++ i) {
    W tp(ls[i].y);
    if (ls[i].type == 0) {
      for (int j = ls[i].x + 1; j <= n; j += j & -j) bit[j] += tp;
    }
    else {
      W r(0);
      for (int j = ls[i].y; j > 0; j -= j & -j) r += bit[j];
      for (int j = ls[i].x; j > 0; j -= j & -j) r -= bit[j];
      ans[ls[i].loc] += r;
    }
  }
  for (int i = 0; i < tot; ++ i) {
    W tp(ls[i].y);
    if (ls[i].type == 0) {
      for (int j = ls[i].x + 1; j <= n; j += j & -j) bit[j] -= tp;
    }
  }
}

int main() {
  srand(time(NULL));
  n = io.xint(); q = io.xint();
  for (int i = 1; i <= n; ++ i) s[i] = io.xint();
  Treap::init(n);
  int tmp(0);
  for (int i = 0; i < q; ++ i) {
    int t, x(0), y(0);
    t = io.xint(); x = io.xint();
    ql[i].t = t;
    if (t == 1) {
      y = io.xint(); ++ tmp;
      Treap::kth(Treap::rt, x, i);
      Treap::kth(Treap::rt, y, i);
      x = y = -1;
    }
    else if (t == 2) {
      y = io.xint();
      Treap::kth(Treap::rt, x, i);
    }
    else if (t == 3) {
      Treap::del(Treap::rt, x, i);
    }
    else if (t == 4) {
      y = io.xint();
      Treap::ins_kth(Treap::rt, x + 1, i);
    }
    else {
      y = io.xint(); ++ tmp;
      Treap::kth(Treap::rt, x, i);
      Treap::kth(Treap::rt, y, i);
      x = y = -1;
    }
    ql[i].x = x; ql[i].y = y;
  }
  if (tmp == 0) return 0;
  Treap::travel(Treap::rt);
  for (int i = 0; i < Treap::tot; ++ i) {
    Treap::Node* p = Treap::seq[i]; a[i] = 0;
    for (auto &v: p->pt) {
      if (v < 0) a[i] = s[-v];
      else {
        if (ql[v].t == 1 || ql[v].t == 5) {
          if (ql[v].x == -1) ql[v].x = i;
          else ql[v].y = i + 1;
        }
        else ql[v].x = i;
      }
    }
  }
  n = Treap::tot;
  map<int, int> mp;
  map<int, set<int> > pt;
  int all(0);
  for (int i = 0; i < n; ++ i) {
    if (!mp.count(a[i])) mp[a[i]] = -1;
    int pv = mp[a[i]]; mp[a[i]] = i;
    if (a[i]) E[all ++] = Event(0, pv, i, a[i]);
    if (pt[a[i]].empty()) pt[a[i]].insert(-1);
    pt[a[i]].insert(i);
  }
  for (int i = 0; i < q; ++ i) {
    if (ql[i].t == 1 || ql[i].t == 5) {
      E[all ++] = Event(1, ql[i].x, ql[i].x, ql[i].y, i);
    }
    else {
      int x = ql[i].x, y = ql[i].y;
      set<int> &s = pt[a[x]];
      auto p = s.lower_bound(x);
      auto l = p, r = p; -- l; ++ r;
      if (r != s.end() && a[*r]) {
        E[all ++] = Event(0, *p, *r, -a[*r]);
        E[all ++] = Event(0, *l, *r, +a[*r]);
      }
      if (a[*p]) E[all ++] = Event(0, *l, *p, -a[*p]);
      s.erase(x); a[x] = y;
      set<int> &t = pt[a[x]];
      if (t.empty()) t.insert(-1);
      t.insert(x); p = t.lower_bound(x);
      l = p; r = p; -- l; ++ r;
      if (a[*p]) E[all ++] = Event(0, *l, *p, a[*p]);
      if (r != t.end() && a[*r]) {
        E[all ++] = Event(0, *l, *r, -a[*r]);
        E[all ++] = Event(0, *p, *r, +a[*r]);
      }
    }
  }
  solve(0, all, n);
  LL inv6 = pm(6, MOD - 2);
  for (int i = 0; i < q; ++ i) {
    if (ql[i].t == 1) {
      LL s0 = ans[i].v[1] % MOD;
      LL s1 = ans[i].v[2] % MOD;
      LL s2 = ans[i].v[3] % MOD;
      LL ret = cub(s0) - s2;
      ret -= 3 * (s0 * s1 % MOD - s2) % MOD;
      ret %= MOD; ret = ret * inv6 % MOD;
      if (ret < 0) ret += MOD;
      printf("%lld\n", ret);
    }
    else if (ql[i].t == 5) {
      printf("%d\n", (int)ans[i].v[0]);
    }
  }
  return 0;
}