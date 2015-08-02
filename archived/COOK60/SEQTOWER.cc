#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000 + 10;
int a[MAXN], n, m;

int pm(int a, int n, int m) {
  int r(1);
  for (a %= m; n; n >>= 1) {
    if (n & 1) r = r * a % m;
    a = a * a % m;
  }
  return r;
}

int phi(int n) {
  int ret = n;
  for (int i = 2; i * i <= n; ++ i) {
    if (n % i == 0) {
      ret = ret / i * (i - 1);
      while (n % i == 0) n /= i;
    }
  }
  if (n > 1) ret = ret / n * (n - 1);
  return ret;
}

vector<int> solve(int l, int mod) {
  vector<int> ret(mod, 0), freq(mod, 0);
  for (int i = 0; i < n; ++ i) freq[a[i] % mod] ++;
  for (int i = 0; i < mod; ++ i) freq[i] %= m;
  if (l == 1) return freq;
  if (mod == 1) {
    ret[0] = pm(n, l, m);
    return ret;
  }
  int p = phi(mod);
  vector<int> prev = solve(l - 1, p);
  for (int i = 0; i < mod; ++ i) if (freq[i]) {
    int pw = pm(i, p, mod);
    for (int j = 0; j < p; ++ j) {
      if (prev[j]) {
        ret[pw] = (ret[pw] + freq[i] * prev[j]) % m;
      }
      pw = pw * i % mod;
    }
  }
  return ret;
}

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++ i) scanf("%d", a + i);
    vector<int> pv = solve(n, m);
    int ret(0);
    for (int i = 0; i < m; ++ i) {
      ret = (ret + i * pv[i]) % m;
    }
    printf("%d\n", ret);
  }
  return 0;
}