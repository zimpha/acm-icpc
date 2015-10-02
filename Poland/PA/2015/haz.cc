#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

struct FastIO {
  static const int S = 2310720;
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
  inline void xstring(char *s) {
    int c = xchar();
    while (c <= 32) c = xchar();
    for(; c > 32; c = xchar()) *s++ = c;
    *s = 0;
  }
} io;

const int MAXN = 1000000 + 10, SIZE = MAXN << 1;
char s[MAXN];
int id[SIZE], q[SIZE], r[SIZE];
int a[MAXN], n, m;

inline void upd(LL &x, LL y) {
  if (x == -1 || x > y) x = y;
}

int find(int l, int r, int v) {
  while (l < r) {
    int m = (l + r - 1) >> 1;
    if (::r[q[m]] >= v) r = m;
    else l = m + 1;
  }
  assert(::r[q[l]] == v);
  return l;
}

int main() {
  n = io.xint();
  for (int i = 0; i < n; ++ i) a[i] = io.xint();
  m = io.xint(); io.xstring(s);
  LL ret(-1);
  for (int i = 0; i < m; ++ i) if (s[i]) {
    int sz(0);
    for (int j = i; s[j]; j = (j + n) % m) {
      id[++ sz] = j;
      r[sz] = s[j] == 'W' ? 1 : -1;
      s[j] = 0;
    }
    for (int j = 1; j <= sz; ++ j) r[j + sz] = r[j];
    for (int j = 1; j <= sz * 2; ++ j) r[j] += r[j - 1];
    int h(1), t(0), sum(r[sz]);
    for (int j = sz; j >= 1; -- j) {
      while (h <= t && r[q[t]] >= r[j + sz]) -- t;
      q[++ t] = j + sz;
    }
    for (int j = sz; j >= 1; -- j) {
      while (h <= t && q[h] >= j + sz) ++ h;
      while (h <= t && r[q[t]] >= r[j]) -- t;
      q[++ t] = j; if (!a[id[j]]) continue;
      for (int k = id[j]; k < n; k += m) {
        if (r[q[h]] - r[j - 1] + a[k] <= 0) {
          int v = r[j - 1] - a[k];
          v = find(h, t, v); v = q[v];
          upd(ret, k + LL(v - j) * n + 1);
        }
        else if (sum < 0) {
          LL u = (r[j - 1] - a[k] - r[q[h]]) / sum;
          a[k] += u * sum;
          while (a[k] + r[q[h]] - r[j - 1] > 0) ++ u, a[k] += sum;
          assert(a[k] > 0);
          int v = r[j - 1] - a[k];
          v = find(h, t, v); v = q[v];
          upd(ret, k + LL(v - j) * n + u * n * sz + 1);
        }
        a[k] = 0;
      }
    }
  }
  printf("%lld\n", ret);
  return 0;
}