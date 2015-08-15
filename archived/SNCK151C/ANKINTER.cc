#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
const int MAXN = 1000000 + 10;
vector<PII> ql[MAXN];
int C[MAXN << 1];
int lmx[MAXN], lmi[MAXN], rmx[MAXN], rmi[MAXN];
int a[MAXN], n, w;

LL gao(int n, const int* lmx, const int* lmi, int m, const int* rmx, const int* rmi) {
  LL ret(0);
  for (int i = 0; i <= m; ++ i) ql[i].clear();
  for (int i = 0, pmx(0), pmi(0); i < n; ++ i) {
    int len = lmx[i] - lmi[i] + 1, val = lmx[i] - i - 1;
    if (len >= w && len > i + 1) {
      int x = len - i - 2;
      if (x < m && rmx[x] < lmx[i] && rmi[x] > lmi[i]) ++ ret;
    }
    while (pmx < m && rmx[pmx] < lmx[i]) ++ pmx;
    while (pmi < m && rmi[pmi] > lmi[i]) ++ pmi;
    int l = max(w - i - 2, pmi), r = pmx;
    if (r > l) {
      ql[l].push_back(PII(val, 1));
      ql[r].push_back(PII(val, -1));
    }
  }
  for (int i = m - 1; i >= 0; -- i) {
    C[i + rmi[i]] ++;
    for (auto &x: ql[i]) {
      ret += C[x.first] * x.second;
    }
  }
  for (int i = 0; i < m; ++ i) C[i + rmi[i]] --;
  return ret;
}

LL solve(int l, int r) {
  if (l + 1 == r) {return w == 1;}
  int m = (l + r) >> 1;
  LL ret = solve(l, m) + solve(m, r);
  int ls = m - l, rs = r - m;
  for (int i = 0; i < ls; ++ i) {
    int x = m - i - 1;
    lmx[i] = lmi[i] = a[x];
    if (i) {
      lmx[i] = max(lmx[i], lmx[i - 1]);
      lmi[i] = min(lmi[i], lmi[i - 1]);
    }
  }
  for (int i = 0; i < rs; ++ i) {
    int x = m + i;
    rmx[i] = rmi[i] = a[x];
    if (i) {
      rmx[i] = max(rmx[i], rmx[i - 1]);
      rmi[i] = min(rmi[i], rmi[i - 1]);
    }
  }
  return ret + gao(ls, lmx, lmi, rs, rmx, rmi) + gao(rs, rmx, rmi, ls, lmx, lmi);
}

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    scanf("%d%d", &n, &w);
    for (int i = 0; i < n; ++ i) {
      scanf("%d", a + i);
    }
    printf("%lld\n", solve(0, n));
  }
  return 0;
}

