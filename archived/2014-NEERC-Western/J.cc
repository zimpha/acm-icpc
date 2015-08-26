#include <bits/stdc++.h>
#define lson (rt<<1)
#define rson (rt<<1|1)
#define mid ((l+r)>>1)
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 100000 + 10;
struct Node {
  int cnt[26];
} mx[MAXN << 2];
char s[MAXN];
int n, q;

void upd(Node &x, Node y) {
  int a = 25, b = 25;
  for (; a >= 0 && !x.cnt[a]; -- a);
  for (; b >= 0 && !y.cnt[b]; -- b);
  if (a == -1 || a < b) x = y;
  else if (a == b) y.cnt[a] += x.cnt[a], x = y;
  else {
    if (b >= 0) x.cnt[b] += y.cnt[b];
    for (int i = b - 1; i >= 0; -- i) x.cnt[i] = y.cnt[i];
  }
}

void build(int rt = 1, int l = 0, int r = n) {
  if (l + 1 == r) {
    mx[rt].cnt[s[l] - 'a'] = 1;
    return;
  }
  build(lson, l, mid); build(rson, mid, r);
  mx[rt] = mx[lson]; upd(mx[rt], mx[rson]);
}

void modify(int p, int v, int rt = 1, int l = 0, int r = n) {
  if (l + 1 == r) {
    memset(mx[rt].cnt, 0, sizeof(mx[rt].cnt));
    mx[rt].cnt[v] = 1; return;
  }
  if (p < mid) modify(p, v, lson, l, mid);
  else modify(p, v, rson, mid, r);
  mx[rt] = mx[lson]; upd(mx[rt], mx[rson]);
}

Node ret;
void ask(int L, int R, int rt = 1, int l = 0, int r = n) {
  if (L <= l && R >= r) {
    upd(ret, mx[rt]);
    return;
  }
  if (L < mid) ask(L, R, lson, l, mid);
  if (R > mid) ask(L, R, rson, mid, r);
}

int main() {
  scanf("%s", s); n = strlen(s);
  build();
  scanf("%d", &q);
  for (int _ = 0; _ < q; ++ _) {
    int op; scanf("%d", &op);
    if (op == 1) {
      int l, r, k; scanf("%d%d%d", &l, &r, &k);
      memset(ret.cnt, 0, sizeof(ret.cnt));
      ask(l - 1, r);
      char ans = '-';
      for (int i = 25, s = 0; i >= 0; -- i) {
        s += ret.cnt[i];
        if (s >= k) {ans = 'a' + i; break;}
      }
      printf("%c\n", ans);
    }
    else {
      scanf("%d%s", &op, s);
      modify(op - 1, s[0] - 'a');
    }
  }
  return 0;
}