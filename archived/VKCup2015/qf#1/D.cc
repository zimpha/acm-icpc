#include <bits/stdc++.h>
#define lson (rt<<1)
#define rson (rt<<1|1)
#define mid ((l+r)>>1)
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 500000 + 10, inf = 1e9;

map<int, int> mp;
int mx[MAXN << 2], a[MAXN];
int n, m;

void build(int rt = 1, int l = 0, int r = n) {
  if (l + 1 == r) {
    mx[rt] = l - a[l];
    if (a[l] == -1) mx[rt] = inf;
    return;
  }
  build(lson, l, mid);
  build(rson, mid, r);
  mx[rt] = min(mx[lson], mx[rson]);
}

void modify(int p, int rt = 1, int l = 0, int r = n) {
  if (l + 1 == r) {
    mx[rt] = inf;
    return;
  }
  if (p < mid) modify(p, lson, l, mid);
  else modify(p, rson, mid, r);
  mx[rt] = min(mx[lson], mx[rson]);
}

int ask(int L, int R, int rt = 1, int l = 0, int r = n) {
  if (L <= l && R >= r) return mx[rt];
  int ret = inf;
  if (L < mid) ret = min(ret, ask(L, R, lson, l, mid));
  if (R > mid) ret = min(ret, ask(L, R, rson, mid, r));
  return ret;
}

PII p[MAXN], as[MAXN];
int id[MAXN], ret[MAXN];

bool cmp(int a, int b) {
  return as[a] < as[b];
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++ i) {
    int x; scanf("%d", &x);
    if (mp.count(x)) a[i] = mp[x];
    else a[i] = -1; mp[x] = i;
    p[i] = PII(a[i], i);
  }
  for (int i = 0; i < m; ++ i) {
    scanf("%d%d", &as[i].first, &as[i].second);
    as[i].first --; id[i] = i;
  }
  sort(p, p + n); sort(id, id + m, cmp);
  build(1, 0, n);
  for (int i = 0, j = 0; i < m; ++ i) {
    while (j < n && p[j].first < as[id[i]].first) {
      modify(p[j].second); ++ j;
    }
    ret[id[i]] = ask(as[id[i]].first, as[id[i]].second);
    if (ret[id[i]] == inf) ret[id[i]] = -1;
  }
  for (int i = 0; i < m; ++ i) printf("%d\n", ret[i]);
  return 0;
}