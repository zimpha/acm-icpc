#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef double flt;
const int MAXN = 100000 + 10;
const flt eps = 1e-12;

int vw[MAXN], pf[MAXN], vf[MAXN], th[MAXN];
int N, pw;

flt calc(flt W) {
  flt cost = W * pw;
  for (int i = 0; i < N; ++ i) {
    flt need = th[i] - W * vw[i];
    if (need <= eps) continue;
    flt f = need / vf[i];
    cost += f * pf[i];
  }
  return cost;
}

int main() {
  while (scanf("%d", &N) == 1 && N) {
    scanf("%d", &pw);
    for (int i = 0; i < N; ++ i) {
      scanf("%d%d%d%d", vw + i, pf + i, vf + i, th + i);
    }
    flt left = 0, right = 200;
    for (int _ = 0; _ < 100; ++ _) {
      flt m1 = (left + left + right) / 3.0;
      flt m2 = (left + right + right) / 3.0;
      flt c1 = calc(m1), c2 = calc(m2);
      if (c1 < c2) right = m2;
      else left = m1;
    }
    printf("%.10f\n", calc(left));
  }
  return 0;
}