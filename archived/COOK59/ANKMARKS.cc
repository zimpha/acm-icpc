#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL, int> PLI;
const LL inf = 1ll << 62;
const int MAXN = 1000 + 10;

LL dis[MAXN];
int a[MAXN], f[MAXN], N, K;
int rk[MAXN];

int get_vals(int n, int a[]) {
  priority_queue<PLI, vector<PLI>, greater<PLI> > Q;
  int X = *min_element(a, a + n);
  fill(dis, dis + X, inf);
  dis[0] = 0; Q.push(PLI(0, 0));
  while (!Q.empty()) {
    PLI nw = Q.top(); Q.pop();
    int u = nw.second;
    LL val = nw.first;
    if (dis[u] != val) continue;
    for (int i = 0; i < n; ++ i) {
      LL tmp = val + a[i];
      int v = tmp % X;
      if (dis[v] > tmp) {
        dis[v] = tmp;
        Q.push(PLI(tmp, v));
      }
    }
  }
  return X;
}

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    scanf("%d", &N);
    for (int i = 0; i < N; ++ i) {
      scanf("%d", f + i); rk[i] = 0;
    }
    for (int i = 1; i < N; ++ i) {
      if (f[i] > f[i - 1]) rk[i] = max(rk[i - 1] + 1, rk[i]);
    }
    for (int i = N - 2; i >= 0; -- i) {
      if (f[i] > f[i + 1]) rk[i] = max(rk[i + 1] + 1, rk[i]);
    }
    scanf("%d", &K);
    int g = 0;
    for (int i = 0; i < K; ++ i) {
      scanf("%d", a + i);
      g = __gcd(g, a[i]);
    }
    int X = get_vals(K, a);
    vector<LL> val; val.push_back(0);
    while (val.back() < inf) {
      LL x = val.back() * 2 + g;
      while (dis[x % X] > x) ++ x;
      val.push_back(x);
    }
    LL ret(0);
    for (int i = 0; i < N; ++ i) {
      ret += val[rk[i]];
    }
    printf("%.10f\n", 1.0 * ret / N);
  }
  return 0;
}