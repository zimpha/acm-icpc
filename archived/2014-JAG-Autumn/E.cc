#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef double flt;
const int MAXN = 50000 + 10;
const flt eps = 1e-10;

int X[MAXN], R[MAXN], N;

flt sqr(flt x) {
  return x * x;
}

flt get(flt xa, flt ra, flt xb, flt rb) {
  flt len = xb - xa;
  flt cosa = (sqr(ra) + sqr(len) - sqr(rb)) / (2.0 * ra * len);
  flt sina = sqrt(1.0 - sqr(cosa));
  //flt h = ra * sina;
  flt w = ra * cosa;
  flt xx = xa + w;
  return xx;
}

typedef pair<flt, flt> PDD;

PDD get(flt x, flt r, flt y) {
  if (y >= r - eps) return PDD(0, 0);
  flt x1 = x - sqrt(sqr(r) - sqr(y));
  flt x2 = x + sqrt(sqr(r) - sqr(y));
  return PDD(x1, x2);
}

bool check(flt y) {
  vector<PDD> v;
  for (int i = 0; i < N; ++ i) {
    v.push_back(get(X[i], R[i], y));
  }
  sort(v.begin(), v.end());
  flt l = v[0].first, r = v[0].second;
  flt mx = 0;
  for (auto &se : v) {
    if (se.first <= r + eps) r = max(se.second, r);
    else {
      mx = max(mx, r - l);
      l = se.first, r = se.second;
    }
  }
  mx = max(mx, r - l);
  return mx >= 2.0 * y - eps;
}

int main() {
  while (scanf("%d", &N) == 1 && N) {
    flt ret = 0;
    for (int i = 0; i < N; ++ i) {
      scanf("%d%d", X + i, R + i);
      ret = max(ret, sqrt(2.0) * R[i]);
    }
    flt left = 0, right = 2e5;
    for (int _ = 0; _ < 50; ++ _) {
      flt mid = (left + right) * 0.5;
      if (check(mid)) left = mid;
      else right = mid;
    }
    printf("%.18f\n", left + right);
  }
  return 0;
}