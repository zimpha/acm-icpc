#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
const int MOD = 1e9 + 7;
LL sqr(LL x) {return x * x % MOD;}
LL pm(LL a, LL n, LL m = MOD) {
  LL r = 1;
  for (; n; n >>= 1) {
    if (n & 1) r = r * a % m;
    a = a * a % m;
  }
  return r;
}

LL gao(LL q, LL n) {
  if (q == 0) return 0;
  if (q == 1) return n;
  return (pm(q, n) - 1 + MOD) * pm(q - 1, MOD - 2) % MOD;
}

LL gao2(LL c, LL n) {
  if (c == 0) return 0;
  if (c == 1) return n * (n + 1) / 2 % MOD;
  LL ret = n * pm(c, n + 2) % MOD - (n + 1) * pm(c, n + 1) % MOD + c;
  ret %= MOD; ret = (ret + MOD) % MOD;
  return ret * pm(sqr(c - 1), MOD - 2) % MOD;
}

LL solve1(LL N, LL K) {
  LL q = pm(K, MOD - 2);
  LL ret = pm(K, N * 3) * gao(q * q % MOD, N) % MOD;
  ret -= 3ll * pm(K, N * 2) % MOD * gao(q, N) % MOD;
  ret += 3ll * pm(K, N) % MOD * N % MOD;
  ret -= gao(K, N);
  ret %= MOD; ret = (ret + MOD) % MOD;
  return ret * K * (K - 1) * (K - 2) % MOD * pm((K - 1) * sqr(K - 1), MOD - 2) % MOD;
}

LL solve2(LL N, LL K) {
  LL rv = pm(K - 1, MOD - 2);
  LL ret = pm(K, 3) * gao(K * K, N - 1) % MOD - sqr(K) * gao(K, N - 1) % MOD;
  ret = ret * pm(K, N + 1) % MOD * rv % MOD;

  ret -= 2ll * pm(K, N) % MOD * (gao2(K, N) - K - K * K * gao(K, N - 1) % MOD) % MOD;
  ret %= MOD; ret = (ret + MOD) % MOD;

  ret += pm(K, N + 1) * rv % MOD * (K * gao(K, N - 1) % MOD - N + 1) % MOD;
  ret %= MOD; ret = (ret + MOD) % MOD;

  ret -= pm(K, N + 1) * rv % MOD * (K * gao(K, N - 1) % MOD - N + 1) % MOD;
  ret %= MOD; ret = (ret + MOD) % MOD;

  ret += 2ll * pm(K, N) % MOD * N % MOD * (N - 1) % MOD * pm(2, MOD - 2) % MOD;
  ret %= MOD; ret = (ret + MOD) % MOD;

  ret -= rv * (pm(K, N) * (N - 1) % MOD - K * gao(K, N - 1) % MOD) % MOD;
  ret %= MOD; ret = (ret + MOD) % MOD;

  return ret * K * 3 % MOD * pm(K - 1, MOD - 2) % MOD;
}

bool isp(string a, string b) {
  if (a.size() > b.size()) swap(a, b);
  for (size_t i = 0; i < a.size(); ++ i) {
    if (a[i] != b[i]) return false;
  }
  return true;
}
bool check(string a, string b, string c) {
  return !isp(a, b) && !isp(a, c) && !isp(b, c);
}
int main() {
  int T; scanf("%d", &T);
  while (T --) {
    int n, k; scanf("%d%d", &n, &k);
    LL ret = 0;
    if (k >= 3) ret += solve1(n, k);
    if (n >= 2) ret += solve2(n, k);
    printf("%lld\n", ret % MOD);
  }
  return 0;
}
