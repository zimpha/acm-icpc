#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL, LL> PII;

#define x first
#define y second

const int MAXN = 400 + 10;

PII dp[MAXN][MAXN];
bool vs[MAXN][MAXN];

int a[MAXN], n;
char op[MAXN];

PII sub(PII a, PII b) {
  return PII(a.x - b.y, a.y - b.x);
}

PII mul(PII &a, PII &b) {
  LL x = min(a.x * b.x, a.x * b.y);
  x = min(x, a.y * b.x);
  x = min(x, a.y * b.y);
  LL y = max(a.x * b.x, a.x * b.y);
  y = max(y, a.y * b.x);
  y = max(y, a.y * b.y);
  return PII(x, y);
}

PII add(PII &a, PII &b) {
  return PII(a.x + b.x, a.y + b.y);
}

PII solve(int s, int d) {
  if (vs[s][d]) return dp[s][d];
  vs[s][d] = 1;
  if (d == 1) return dp[s][d] = PII(a[s], a[s]);
  PII ret(9223372036854775807LL, -9223372036854775807LL - 1);
  for (int i = 1; i < d; ++ i) {
    PII l = solve(s, i);
    PII r = solve(s + i,  d - i);
    PII rt, tp;
    if (op[s + i - 1] == '?') {
      rt = sub(l, r);
      tp = add(l, r);
      rt.x = min(rt.x, tp.x);
      rt.y = max(rt.y, tp.y);
      tp = mul(l, r);
      rt.x = min(rt.x, tp.x);
      rt.y = max(rt.y, tp.y);
    }
    else if (op[s + i - 1] == '-') rt = sub(l, r);
    else if (op[s + i - 1] == '+') rt = add(l, r);
    else rt = mul(l, r);
    ret.x = min(ret.x, rt.x);
    ret.y = max(ret.y, rt.y);
  }
  return dp[s][d] = ret;
}

int main() {
  while (scanf("%d", &n) == 1) {
    for (int i = 0; i < n; ++ i) {
      scanf("%d", a + i);
      char s[10]; scanf("%s", s);
      op[i] = s[0];
      a[i + n] = a[i];
      op[i + n] = op[i];
    }
    memset(vs, 0, sizeof(vs));
    stringstream sin;
    for (int i = 0; i < n; ++ i) {
      PII rt = solve(i, n);
      sin << abs(rt.x) << abs(rt.y);
    }
    string ret;
    sin >> ret;
    printf("%s\n", ret.c_str());
  }
  return 0;
}

