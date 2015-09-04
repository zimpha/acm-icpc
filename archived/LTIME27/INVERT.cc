#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

namespace Splay {
const int SIZE = 200000 + 10, INF = 1 << 30;
struct Node {
  Node *ch[2], *p;
  int sz, val;
  Node() {sz = 0; val = -INF;}
  bool d() {return this == p->ch[1];}
  void setc(Node *c, int d) {ch[d] = c; c->p = this;}
  void upd() {sz = ch[0]->sz + ch[1]->sz + 1;}
  void psd();
} *null, pool[SIZE], *curNode;
inline Node *newNode(int v=0) {//Modify it according to problems
  curNode->val = v; curNode->sz = 1;
  curNode->ch[0] = curNode->ch[1] = curNode->p = null;
  return curNode ++;
}
void Node::psd() {//Modify it according to problems
}
void init() {
  curNode = pool; null = newNode(INF); null->sz = 0;
  null->ch[0] = null->ch[1] = null->p = null;
}
struct Splay {
  Node *rt;
  Splay(): rt(newNode()) {
    rt->setc(newNode(), 0);
    rt->setc(newNode(), 1);
    rt->upd();
  }
  Splay(int n, int a[]) {// a is 1-indexed
    rt = build(a, a + n + 2);
  }
  inline Node *rot(Node *t) {
    Node *p = t->p;
    p->psd(); t->psd();
    int d = t->d();
    p->p->setc(t, p->d());
    p->setc(t->ch[!d], d);
    t->setc(p, !d);
    p->upd();
    if (p == rt) rt = t;
    return t;
  } //make o become f's son, if f == null, then o become rt
  inline void splay(Node* o, Node *f = null) {
    for (o->psd(); o->p != f; rot(o)) {
      if (o->p->p != f) o->d() == o->p->d() ? rot(o->p) : rot(o);
    }
    o->upd();
  }
  inline Node *select(int k) { // find the kth element 0-based
    for (Node *t = rt;;) {
      t->psd();
      int c = t->ch[0]->sz;
      if (k == c) return t;
      if (k > c) k -= c + 1, t = t->ch[1];
      else t = t->ch[0];
    }
    return null;
  }
  // make range[l,r] root->ch[1]->ch[0]
  // make range[x+1,x] to add something after position x
  inline Node *get_seq(int l, int r) {
    Node *L = select(l - 1); splay(L, null);
    Node *R = select(r + 1); splay(R, rt);
    return rt->ch[1]->ch[0];
  }
  void ins(int x, Node *v) { // after x
    get_seq(x + 1, x);
    rt->ch[1]->setc(v, 0);
    splay(v, null);
  }
  Node* del(int l, int r) { //[l, r]
    Node *p = get_seq(l, r);
    rt->ch[1]->setc(null, 0);
    splay(rt->ch[1], null);
    return p;
  }
  Node *build(int *l, int *r) {
    if (l >= r) return null;
    if (l + 1 == r) return newNode(*l);
    int *m = (r - l) / 2 + l;
    Node *p = newNode(*m);
    p->setc(build(l, m), 0);
    p->setc(build(m + 1, r), 1);
    p->upd(); return p;
  }
  void dump(Node *p) {
    p->psd();
    if (p->ch[0] != null) dump(p->ch[0]);
    printf("%d ", p->val);
    if (p->ch[1] != null) dump(p->ch[1]);
  }
  void dump() {
    dump(rt); puts("");
  }
};
}

const int MAXN = 100000 + 10;

vector<int> Xs;
int val[MAXN], a[MAXN], b[MAXN];
int L[MAXN], R[MAXN], K[MAXN];
int n, q, m;
LL cnt_inv;

namespace ST {
  const int SIZE = MAXN << 7;
  int ls[SIZE], rs[SIZE], cnt[SIZE];
  int rt[MAXN], n, m, sz;
  void init(int _n, int _m) {
    n = _n; // sizeof bit
    m = _m; // sizeof segment tree
    sz = 1; ls[0] = rs[0] = cnt[0] = 0;
    for (int i = 1; i <= n; ++ i) rt[i] = 0;
  }
  void ins(int &rt, int l, int r, int p) {
    if (rt == 0) rt = sz ++;
    cnt[rt] ++;
    if (l + 1 == r) return;;
    int mid = (l + r) >> 1;
    if (p < mid) ins(ls[rt], l, mid, p);
    else ins(rs[rt], mid, r, p);
  }
  int get_less(int rt, int l, int r, int x) { // <= x
    if (rt == 0) return 0;
    if (l + 1 == r) return cnt[rt];
    int mid = (l + r) >> 1;
    if (x < mid) return get_less(ls[rt], l, mid, x);
    else return cnt[ls[rt]] + get_less(rs[rt], mid, r, x);
  }
  int get_more(int rt, int l, int r, int x) { // >= x
    if (rt == 0) return 0;
    if (l + 1 == r) return cnt[rt];
    int mid = (l + r) >> 1;
    if (x < mid) return get_more(ls[rt], l, mid, x) + cnt[rs[rt]];
    else return get_more(rs[rt], mid, r, x);
  }
  int get_less(int x, int v) { // < v
    int r(0);
    for (; x; x -= x & -x) {
      r += get_less(rt[x], 0, m, v - 1);
    }
    return r;
  }
  int get_more(int x, int v) { // > v
    int r(0);
    for (; x; x -= x & -x) {
      r += get_more(rt[x], 0, m, v + 1);
    }
    return r;
  }
  int get_less(int l, int r, int x) {
    return get_less(r, x) - get_less(l - 1, x);
  }
  int get_more(int l, int r, int x) {
    return get_more(r, x) - get_more(l - 1, x);
  }
  int add(int p, int v) {
    int ret = get_more(1, p - 1, v) + get_less(p + 1, n, v);
    for (; p <= n; p += p & -p) {
      ins(rt[p], 0, m, v);
    }
    return ret;
  }
}

void find_index(Splay::Node *p) {
  if (p->ch[0] != Splay::null) find_index(p->ch[0]);
  b[p->val] = m ++;
  if (p->ch[1] != Splay::null) find_index(p->ch[1]);
}

void make_change(Splay::Node *p) {
  if (p->ch[0] != Splay::null) make_change(p->ch[0]);

  cnt_inv += ST::add(b[p->val], val[p->val]);

  if (p->ch[1] != Splay::null) make_change(p->ch[1]);
}

int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; ++ i) {
    scanf("%d", val + i); a[i] = i;
    Xs.push_back(val[i]);
  }
  sort(Xs.begin(), Xs.end());
  Xs.erase(unique(Xs.begin(), Xs.end()), Xs.end());
  for (int i = 1; i <= n; ++ i) {
    val[i] = lower_bound(Xs.begin(), Xs.end(), val[i]) - Xs.begin();
  }
  Splay::init();
  Splay::Splay *SA = new Splay::Splay(n, a);
  Splay::Splay *SB = new Splay::Splay();
  for (int i = 0; i < q; ++ i) {
    scanf("%d%d%d", L + i, R + i, K + i);
    Splay::Node *p = SA->del(L[i], R[i]);
    SB->ins(K[i] - 1, p);
    //SB->dump();
  }
  for (int i = 1; i <= n; ++ i) b[i] = 0;
  find_index(SB->rt);
  //for (int i = 1; i <= n; ++ i) cout << b[i] << " "; cout << endl;
  Splay::init();
  SA = new Splay::Splay(n, a);
  ST::init(n, Xs.size());
  cnt_inv = 0;
  for (int i = 0; i < q; ++ i) {
    Splay::Node *p = SA->del(L[i], R[i]);
    make_change(p);
    printf("%lld\n", cnt_inv);
  }
  return 0;
}