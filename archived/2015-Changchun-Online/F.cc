#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long LL;
const int MAXN = 40000 + 10, seed = 65537;

LL hs[MAXN], pw[MAXN];
char s[MAXN];

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
} pool[MAXN << 1];

namespace SAM {
  Node *sz = pool, *rt, *last;
  void init() {
    if (sz != pool) {
      for (Node *p = pool; p < sz; ++ p) p->clear();
    }
    sz = pool; rt = sz ++; last = rt;
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
    for (Node *p = rt; ; p = p->ch[s[p->val] - 'a']) {
      p->sc = 1; if (p->val == n) break;
    }
    for (int i = (sz - pool) - 1; i >= 0; -- i) {
      Node *p = Q[i]; if (p->fa) p->fa->sc += p->sc;
    }
  }
  void build(char *s, int n) {
    init();
    for (int i = 0; i < n; ++ i) add(s[i] - 'a');
  }
  void get(char s[], int n) {
    Node *p = rt;
    for (int i = 0; i < n; ++ i) {
      for (int c = 25; c >= 0; -- c) {
        if (p->ch[c]) {
          p = p->ch[c];
          s[i] = c + 'a';
          break;
        }
      }
    }
  }
}

LL get(LL s, LL l) {
  return hs[s] - hs[s + l] * pw[l];
}

int main() {
  pw[0] = 1;
  for (int i = 1; i < MAXN; ++ i) pw[i] = pw[i - 1] * seed;
  int T, n; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    scanf("%d", &n);
    scanf("%s", s);
    for (int i = 0; i < n; ++ i) s[i + n] = s[i];
    hs[n * 2] = 0;
    for (int i = n * 2 - 1; i >= 0; -- i) {
      hs[i] = hs[i + 1] * seed + s[i];
    }

    static char a[MAXN], b[MAXN];
    SAM::build(s, n * 2);
    SAM::get(a, n);

    reverse(s, s + n * 2);
    SAM::build(s, n * 2);
    SAM::get(b, n);

    int r1(-1), r2(-1);
    LL tmp(0);
    for (int i = n - 1; i >= 0; -- i) tmp = tmp * seed + a[i];
    for (int i = 0; i < n; ++ i) {
      if (get(i, n) == tmp) {r1 = i; break;}
    }
    hs[n * 2] = 0;
    for (int i = n * 2 - 1; i >= 0; -- i) {
      hs[i] = hs[i + 1] * seed + s[i];
    }
    tmp = 0;
    for (int i = n - 1; i >= 0; -- i) tmp = tmp * seed + b[i];
    for (int i = 0; i < n; ++ i) {
      if (get(i, n) == tmp) r2 = i;
    }
    r2 = n - r2 - 1;
    int res = strcmp(a, b);
    if (res < 0) printf("%d 1\n", r2 + 1);
    else if (res > 0) printf("%d 0\n", r1 + 1);
    else {
      if (r1 <= r2) printf("%d 0\n", r1 + 1);
      else printf("%d 1\n", r2 + 1);
    }
  }
  return 0;
}