#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int MAXN = 400000 + 10;

struct Node {
  Node *ch[2];
  int sz;
} pool[MAXN << 6], *rt, *cnt;

Node *newNode() {
  cnt->ch[0] = cnt->ch[1] = NULL;
  cnt->sz = 0;
  return cnt ++;
}

void ins(int n) {
  Node *p = rt;
  for (int i = 30; i >= 0; -- i) {
    int o = n >> i & 1;
    if (!p->ch[o]) p->ch[o] = newNode();
    p = p->ch[o];
  }
}

int ask(int n) {
  Node *p = rt;
  int ret(0);
  for (int i = 30; i >= 0; -- i) {
    if (!p) break;
    int o = n >> i & 1;
    if (p->ch[o ^ 1]) o ^= 1, ret |= 1 << i;
    p = p->ch[o];
  }
  return ret;
}

int a[MAXN], s[MAXN], t[MAXN];

int main() {
  int n; scanf("%d", &n);
  for (int i = 1; i <= n; ++ i) scanf("%d", a + i);
  cnt = pool; rt = newNode();
  ins(0);
  for (int i = 1, p(0); i <= n; ++ i) {
    p ^= a[i];
    s[i] = ask(p);
    ins(p);
    if (i > 1) s[i] = max(s[i], s[i - 1]);
  }
  cnt = pool; rt = newNode();
  ins(0);
  for (int i = n, p(0); i >= 1; -- i) {
    p ^= a[i];
    t[i] = ask(p);
    ins(p);
    if (i < n) t[i] = max(t[i], t[i + 1]);
  }
  int ret(0);
  for (int i = 1; i + 1 <= n; ++ i) {
    ret = max(ret, s[i] + t[i + 1]);
  }
  printf("%d\n", ret);
  return 0;
}
