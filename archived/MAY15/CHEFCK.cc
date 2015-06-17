#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
const int MAXN = 10000000 + 10, MOD = 1e9 + 7;
LL A[MAXN], ms[MAXN], mp[MAXN];
LL a,b, c, d, e, f, r, s, t, m;
LL L1, La, Lc, Lm, D1, Da, Dc, Dm;
int N, Q, K;

int main() {
  cin >> N >> K >> Q;
  cin >> a >> b >> c >> d >> e >> f >> r >> s >> t >> m;
  cin >> A[0];
  cin >> L1 >> La >> Lc >> Lm >> D1 >> Da >> Dc >> Dm;
  LL pt = t;
  for (int x = 1; x < N; ++ x) {
    pt = pt * t % s;
    if (pt <= r) A[x] = (A[x - 1] * (a * A[x - 1] % m + b) + c) % m;
    else A[x] = (A[x - 1] * (d * A[x - 1] % m + e) + f) % m;
  }
  for (int i = 0; i < N; ++ i) {
    if (i % K == 0) mp[i] = A[i];
    else mp[i] = min(mp[i - 1], A[i]);
  }
  for (int i = N - 1; i >= 0; -- i) {
    if (i % K == K - 1) ms[i] = A[i];
    else ms[i] = min(ms[i + 1], A[i]);
  }
  LL sum = 0, pro = 1;
  for (int i = 1; i <= Q; ++ i) {
    L1 = (La * L1 + Lc) % Lm;
    D1 = (Da * D1 + Dc) % Dm;
    int L = L1 + 1, R = min(L + K - 1 + (int)D1, N);
    -- L; -- R;
    int pl = L / K, pr = R / K, mx;
    if (L % K == 0) mx = min(mp[R], ms[L]);
    else {
      mx = min(ms[L], mp[R]);
      if (pl + 1 != pr) mx = min((LL)mx, mp[pr * K - 1]);
    }
    sum += mx, pro = pro * mx % MOD;
  }
  printf("%lld %lld\n", sum, pro);
  return 0;
}