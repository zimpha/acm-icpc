#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;
const int MAXN = 100010;
struct Node *null;
struct Node{
  Node *fa,*ch[2];
  int val,size;
  int same,rev;
  int sum;
  inline void clear(int _val){
    fa = ch[0] = ch[1] = null;
    sum = val = _val; size = 1;
    same = -INF;
  }
  inline void push_up(){
    size = 1 + ch[0]->size + ch[1]->size;
    sum = val + ch[0]->sum + ch[1]->sum;
  }
  inline void setc(Node *p,int d){
    ch[d] = p;
    p->fa = this;
  }
  inline bool d(){
    return fa->ch[1] == this;
  }
  inline bool isroot(){
    return fa == null || fa->ch[0] != this && fa->ch[1] != this;
  }
  inline void flip(){
    if(this == null)return;
    swap(ch[0],ch[1]);
    rev ^= 1;
  }
  inline void update_same(int w){
    if(this == null)return;
    sum = w * size; val = w;
    same = w;
  }
  inline void push_down(){
    if(same != -INF){
      ch[0]->update_same(same);
      ch[1]->update_same(same);
      same = -INF;
    }
    if(rev){
      ch[0]->flip();
      ch[1]->flip();
      rev = 0;
    }
  }
  inline void go(){
    if(!isroot())fa->go();
    push_down();
  }
  inline void rot(){
    Node *f = fa, *ff = fa->fa;
    int c = d(), cc = fa->d();
    f->setc(ch[!c],c);
    this->setc(f,!c);
    if(ff->ch[cc] == f)ff->setc(this,cc);
    else this->fa = ff;
    f->push_up();
  }
  inline Node* splay(){
    go();
    while(!isroot()){
      if(!fa->isroot())
        d()==fa->d() ? fa->rot() : rot();
      rot();
    }
    push_up();
    return this;
  }
  inline Node* access(){
    for(Node *p = this,*q = null; p != null; q = p, p = p->fa){
      p->splay()->setc(q,1);
      p->push_up();
    }
    return splay();
  }
  inline Node* find_root(){
    Node *x;
    for(x = access(); x->push_down(), x->ch[0] != null; x = x->ch[0]);
    return x;
  }
  void make_root(){
    access()->flip();
  }
  void cut(){
    access();
    ch[0]->fa = null;
    ch[0] = null;
    push_up();
  }
  void cut(Node *x){
    if(this == x || find_root() != x->find_root())return;
    else{
      x->make_root();
      cut();
    }
  }
  void link(Node *x){
    if(find_root() == x->find_root())return;
    else {
      make_root(); fa = x;
    }
  }
};

void SAME(Node *x,Node *y,int w){
  x->access();
  for(x = null; y != null; x = y, y = y->fa){
    y->splay();
    if(y->fa == null){
      y->ch[1]->update_same(w);
      x->update_same(w);
      y->val = w;
      y->push_up();
      return;
    }
    y->setc(x,1);
    y->push_up();
  }
}

int ask(Node *x,Node *y){
  x->access();
  for(x=null; y != null; x = y, y = y->fa){
    y->splay();
    if(y->fa == null) return y->ch[1]->sum + x->sum + y->val;
    y->setc(x,1);
    y->push_up();
  }
  return 0;
}

Node pool[MAXN],*tail;
Node *node[MAXN];

struct FastIO {
  static const int S = 131072;
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

struct Query {
  int op, a, b;
} ql[MAXN];

int ans[MAXN], dsu[MAXN], n, m, q;

int get(int x) {
  if (x != dsu[x]) dsu[x] = get(dsu[x]);
  return dsu[x];
}

int main() {
  int T; T = io.xint();
  for (int cas = 1; cas <= T; ++ cas) {
    printf("Case #%d:\n", cas);

    n = io.xint(), m = io.xint(), q = io.xint();
    map<PII, int> E;
    for (int i = 0; i < m; ++ i) {
      int u = io.xint();
      int v = io.xint();
      if (u > v) swap(u, v);
      E[PII(u, v)] ++;
    }
    
    for (int i = 0; i < q; ++ i) {
      ql[i].op = io.xint();
      ql[i].a = io.xint();
      ql[i].b = io.xint();
      if (ql[i].a > ql[i].b) swap(ql[i].a, ql[i].b);
      if (ql[i].op == 1) {
        E[PII(ql[i].a, ql[i].b)] --;
      }
    }

    tail = pool;
    null = tail++;
    null->fa = null->ch[0] = null->ch[1] = null;
    null->size = null->rev = 0;
    null->same = -INF; null->sum = null->val = 0;

    for (int i = 1; i <= n; ++ i) {
      node[i] = tail ++; dsu[i] = i;
      node[i]->clear(0);
    }

    for (auto &e: E) if (e.second) {
      int u = e.first.first, v = e.first.second;
      int a = get(u), b = get(v);
      if (a != b) {
        dsu[a] = b; ++ n;
        node[n] = tail ++; node[n]->clear(1);
        node[u]->link(node[n]);
        node[n]->link(node[v]);
        e.second --;
      }
    }
    for (auto &e: E) if (e.second) {
      int u = e.first.first, v = e.first.second;
      if (u == v) continue;
      SAME(node[u], node[v], 0);
    }
    for (int i = q - 1; i >= 0; -- i) {
      ans[i] = -1;
      if (ql[i].op == 1) {
        SAME(node[ql[i].a], node[ql[i].b], 0);
      }
      else ans[i] = ask(node[ql[i].a], node[ql[i].b]);
    }
    for (int i = 0; i < q; ++ i) {
      if (ans[i] != -1) printf("%d\n", ans[i]);
    }
  }
  return 0;
}