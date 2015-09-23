#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int MAXN = 300000 + 10;
namespace SAM {
  struct Node {
    Node *ch[26], *fa;
    int val, sc;
    Node(): fa(0), val(0), sc(0) {
      memset(ch, 0, sizeof(ch));
    }
    void clear() {
      memset(ch, 0, sizeof(ch));
      fa = 0; val = sc = 0;
    }
  } pool[MAXN], *rt, *last;
  Node *sz = pool;
  vector<int> G[MAXN];
  int pos[MAXN];
  void init() {
    if (sz != pool) {
      for (Node *p = pool; p < sz; ++ p) p->clear();
    }
    sz = pool; rt = sz ++; last = rt;
  }
  void add(int i, int c) {
    Node *p = last, *np = sz ++;
    last = np; np->val = p->val + 1;
    pos[i] = last - pool;
    for (; p && !p->ch[c]; p = p->fa) p->ch[c] = np;
    if (p) {
      Node *q = p->ch[c];
      if (p->val + 1 == q->val) np->fa = q;
      else {
        Node *nq = sz ++; *nq = *q;
        nq->val = p->val + 1;
        q->fa = nq; np->fa = nq;
        for (; p && p->ch[c] == q; p = p->fa) p->ch[c] = nq;
      }
    }
    else np->fa = rt;
  }
  void build(char *s, int n) {
    init();
    for (int i = 0; i < n; ++ i) add(i, s[i] - 'a');
    for (Node *p = pool + 1; p < sz; ++ p) {
      G[p->fa - pool].push_back(p - pool);
    }
  }
}

namespace Treap {
  const int INF = ~0U>>1;
  struct Node {
    int val, pri, sz;
    int cnt, sum;
    Node* ch[2];
    Node() {}
    Node (int v, Node* n) : val(v) {
      ch[0]=ch[1]=n; sz=1; cnt = sum = 0;
      pri=rand()-1;
    }
    void upd() {
      sz=ch[0]->sz+ch[1]->sz+1;
      sum=ch[0]->sum+ch[1]->sum+cnt;
    }
  } pool[MAXN << 5], *null, *np;
  Node *newNode(int v) {
    np->val = v; np->sz = 1; np->pri = rand() - 1;
    np->cnt = np->sum = 1;
    np->ch[0] = np->ch[1] = null; return np ++;
  }
  void rot(Node* &o,int d) { //d = 1, left; d = 0, right
    Node* k=o->ch[d];
    o->ch[d]=k->ch[!d]; k->ch[!d]=o;
    o->upd(); k->upd(); o=k;
  }
  void ins(Node* &o,int val) {
    if (o==null) o = newNode(val);
    else {
      if (val==o->val) { //same val
        o->cnt ++; o->upd();
        return;
      }
      int d=val>o->val; ins(o->ch[d],val);
      if (o->ch[d]->pri<o->pri) rot(o,d);
      else o->upd();
    }
  }
  void del(Node* &o,int val) {
    if (o==null) return;
    if (o->val==val) {
      int d=o->ch[1]->pri<o->ch[0]->pri;
      if (o->ch[d]==null) {
        o->cnt --; o->upd();
        return;
      }
      rot(o,d); del(o->ch[!d],val);
    } else del(o->ch[val>o->val], val);
    o->upd();
  }
  int rank(Node* o,int val) { //return how many elements smaller than val
    if (o==null) return 0;
    if (val==o->val) return o->ch[0]->sum;
    if (val<o->val) return rank(o->ch[0],val);
    else return o->ch[0]->sum+o->cnt+rank(o->ch[1],val);
  }
  bool find(Node *o, int x) {
    if (o==null) return 0;
    if (x==o->val) return o->cnt;
    else return find(o->ch[x>o->val],x);
  }
  void init() {
    null=new Node(0,0); np = pool;
    null->ch[0]=null->ch[1]=null;
    null->sz=null->cnt=null->sum;
    null->pri=INF;
  }
}

namespace ST {
  #define lson (rt<<1)
  #define rson (rt<<1|1)
  #define mid ((l+r)>>1)
  Treap::Node *u[MAXN << 2];
  void build(int rt, int l, int r) {
    u[rt] = Treap::null;
    if (l == r) return;
    build(lson, l, mid); build(rson, mid + 1, r);
  }
  void ins(int rt, int l, int r, int p, int v, int f) {
    if (f) Treap::ins(u[rt], v); else Treap::del(u[rt], v);
    if (l == r) return;
    if (p <= mid) ins(lson, l, mid, p, v, f);
    else ins(rson, mid + 1, r, p, v, f);
  }
  int ask(int rt, int l, int r, int a, int b, int k) {// a <= x < b
    if (l == r) {
      int cnt = Treap::rank(u[rt], b) - Treap::rank(u[rt], a);
      if (cnt >= k) return l;
      else return -1;
    }
    int cnt = Treap::rank(u[lson], b) - Treap::rank(u[lson], a);
    if (cnt >= k) return ask(lson, l, mid, a, b, k);
    else return ask(rson, mid + 1, r, a, b, k - cnt);
  }
}

using SAM::G;
using SAM::pos;

Treap::Node* rt[MAXN];

char s[MAXN];
int fa[MAXN][20], st[MAXN], ed[MAXN];
int n, m, ind;

void dfs(int u, int f = 0) {
  st[u] = ind ++; fa[u][0] = f;
  for (int i = 1; i < 20; ++ i) fa[u][i]=fa[fa[u][i-1]][i-1];
  for (auto &v: G[u]) dfs(v, u);
  ed[u] = ind;
}

int get_node(int u, int len) {
  for (int i = 19; i >= 0; -- i) {
    int t = fa[u][i];
    if (SAM::pool[t].val >= len) u = t;
  }
  return u;
}

int main() {
  scanf("%s", s);
  n = strlen(s);
  SAM::init();
  SAM::build(s, n);
  m = SAM::sz - SAM::pool;
  dfs(0);

  Treap::init();
  for (int i = 0; i < m; ++ i) rt[i] = Treap::null;
  ST::build(1, 1, n);

  int q; scanf("%d", &q); 
  for (int _ = 0; _ < q; ++ _) {
    int op, x, p, k;
    scanf("%d%d%d", &op, &x, &p);
    int u = get_node(pos[p], x);
    if (op == 1) {
      if (Treap::find(rt[u], x)) continue;
      Treap::ins(rt[u], x);
      ST::ins(1, 1, n, x, st[u], 1);
    }
    else if (op == 2) {
      if (!Treap::find(rt[u], x)) continue;
      Treap::del(rt[u], x);
      ST::ins(1, 1, n, x, st[u], 0);
    }
    else {
      scanf("%d", &k);
      k += Treap::rank(rt[u], x);
      printf("%d\n", ST::ask(1, 1, n, st[u], ed[u], k));
    }
  }
  return 0;
}