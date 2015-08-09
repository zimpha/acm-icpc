#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 10000, MOD = 1e9 + 7;

PII fib(LL n, int m){
  if(n<=2) return PII(!!n%m,n/2%m);
  PII t=fib(n/2+1,m);
  int x=t.first,y=t.second;
  int p=(LL(x)*x+LL(y)*y)%m;
  int q=(x*2ll*y-LL(y)*y%m+m)%m;
  if(n&1) return PII(p,q);
  return PII(q,(p-q+m)%m);
}

vector<int> G[MAXN];
int T[MAXN << 2];
int st[MAXN], ed[MAXN];
int n, Q, sz;

void dfs(int u, int f = -1) {
  st[u] = sz ++;
  for (auto &v: G[u]) if (v != f) {
    dfs(v, u);
  }
  ed[u] = sz;
}

#define lson (rt<<1)
#define rson (rt<<1|1)
#define mid ((l+r)>>1)
void build(int rt, int l, int r) {
  T[rt] = r - l;
  if (l + 1 == r) return;
  build(lson, l, mid);
  build(rson, mid, r);
}

void modify(int rt, int l, int r, int p, int v) {
  if (l + 1 == r) {
    T[rt] = (T[rt] + v) % MOD;
    return;
  }
  if (p < mid) modify(lson, l, mid, p, v);
  else modify(rson, mid, r, p, v);
  T[rt] = (T[lson] + T[rson]) % MOD;
}

LL ask(int rt, int l, int r, int L, int R) {
  if (L <= l && R >= r) return T[rt];
  LL ret(0);
  if (L < mid) ret += ask(lson, l, mid, L, R);
  if (R > mid) ret += ask(rson, mid, r, L, R);
  return ret;
}

int main() {
  scanf("%d%d", &n, &Q);
  for (int i = 1; i < n; ++ i) {
    int u, v; scanf("%d%d", &u, &v);
    G[u].push_back(v);
    G[v].push_back(u);
  }
  sz = 0; dfs(1);
  build(1, 0, n);
  for (int i = 0; i < Q; ++ i) {
    int op, v, m, add; scanf("%d%d", &op, &v);
    if (op == 0) {
      scanf("%d", &m);
      if (m & 1) add = 0;
      else {
        PII t = fib(m / 2 + 1, 100000);
        add = t.first;
      }
      add = (LL)add * m % MOD;
      modify(1, 0, n, st[v], add);
    }
    else {
      printf("%lld\n", ask(1, 0, n, st[v], ed[v]) % MOD);
    }
  }
}