#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int MAXN = 10000 + 10;

LL wx[MAXN], wy[MAXN];
LL Sx, Sy, Fx, Fy, V;
int t[MAXN], n, k;

int main() {
  freopen("joy.in", "r", stdin);
  freopen("joy.out", "w", stdout);
  scanf("%lld%lld%lld%lld", &Sx, &Sy, &Fx, &Fy);
  scanf("%d%d%lld", &n, &k, &V);
  for (int i = 0; i < n; ++ i) scanf("%d%lld%lld", t + i, wx + i, wy + i);
  t[n] = k;
  LL Tx(Fx), Ty(Fy);
  for (int i = 0; i < n; ++ i) {
    int dt = t[i + 1] - t[i];
    Tx -= dt * wx[i];
    Ty -= dt * wy[i];
  }
  Tx -= Sx; Ty -= Sy;
  if (Tx * Tx + Ty * Ty > V * V * k * k) {puts("No"); return 0;}
  double vx = (double)Tx / k, vy = (double)Ty / k;
  double sx = Sx, sy = Sy;
  puts("Yes");
  for (int i = 0; i < n; ++ i) {
    for (int j = t[i]; j < t[i + 1]; ++ j) {
      sx += vx + wx[i];
      sy += vy + wy[i];
      printf("%.10f %.10f\n", sx, sy);
    }
  }
  return 0;
}