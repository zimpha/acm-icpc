#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int MAXN = 250000 + 10;
struct Node {
  Node *ch[52], *fa;
  int val, sc, vis, deg;
  LL cnt;
  Node(): fa(0), val(0), sc(0), vis(0), deg(0), cnt(0) {
    memset(ch, 0, sizeof(ch));
  }
  void clear() {
    memset(ch, 0, sizeof(ch));
    fa = 0; val = sc = vis = deg =  cnt = 0;
  }
} pool[MAXN << 1], *rt, *last;
namespace SAM {
  Node *sz = pool;
  void init() {
    if (sz != pool) {
      for (Node *p = pool; p < sz; ++ p) p->clear();
    }
    sz = pool; rt = sz ++; last = rt;
  }
  int id(char c) {
    if (c >= 'a' && c <= 'z') return c - 'a';
    else return c - 'A' + 26;
  }
  void add(int c) {
    Node *p = last, *np = sz ++;
    last = np; np->val = p->val + 1;
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
  void getRight(char *s, int n) {
    static Node* Q[MAXN << 1];
    static int cnt[MAXN];
    for (int i = 0; i <= n; ++ i) cnt[i] = 0;
    for (Node *p = pool; p < sz; ++ p) p->sc = 0, cnt[p->val] ++;
    for (int i = 1; i <= n; ++ i) cnt[i] += cnt[i - 1];
    for (Node *p = pool; p < sz; ++ p) Q[-- cnt[p->val]] = p;
    for (Node *p = rt; ; p = p->ch[id(s[p->val])]) {
      p->sc = 1; if (p->val == n) break;
    }
    for (int i = (sz - pool) - 1; i >= 0; -- i) {
      Node *p = Q[i]; if (p->fa) p->fa->sc += p->sc;
    }
  }
  void build(char *s, int n) {
    init();
    for (int i = 0; i < n; ++ i) add(id(s[i]));
    getRight(s, n);
  }
  void dfs(Node *p) {
    p->vis = 1;
    for (int c = 0; c < 52; ++ c) {
      Node *v = p->ch[c];
      if (v == NULL) continue;
      v->deg ++;
      if (!v->vis) dfs(v);
    }
  }
  int solve() {
    rt->cnt = 1;
    dfs(rt);
    queue<Node*> Q; Q.push(rt);
    int ret(0);
    while (!Q.empty()) {
      Node *u = Q.front(); Q.pop();
      if (u != rt && u->sc > 1) ret += u->cnt;
      for (int c = 0; c < 52; ++ c) {
        Node *v = u->ch[c];
        if (v == NULL) continue;
        if (!(-- v->deg)) Q.push(v);
        v->cnt += u->cnt;
      }
    }
    return ret;
  }
}

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    static char s[200000]; scanf("%s", s);
    SAM::build(s, strlen(s));
    printf("%d\n", SAM::solve());
  }
  return 0;
}

