#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long LL;
typedef pair<int, int> PII;
const int SEED = 1e9 + 7;
const int MAXN = 100000 + 10;

LL hs1[MAXN], hs2[MAXN], pw[MAXN];
char s[MAXN];
int n, Q;

LL get1(int l, int r) {
  if (l > r) return 0;
  else return (hs1[r + 1] - hs1[l]) * pw[n - 1 - l];
}
LL get2(int l, int r) {
  if (l > r) return 0;
  else return (hs2[r + 1] - hs2[l]) * pw[r];
}

int main() {
  pw[0] = 1;
  for (int i = 1; i < MAXN; ++ i) pw[i] = pw[i - 1] * SEED;
  scanf("%s", s);
  n = strlen(s);
  hs1[0] = hs2[0] = 0;
  for (int i = 0; i < n; ++ i) {
    hs1[i + 1] = hs1[i] + s[i] * pw[i];
    hs2[i + 1] = hs2[i] + s[i] * pw[n - 1 - i];
  }
  scanf("%d", &Q);
  for (int _ = 0; _ < Q; ++ _) {
    int i, j, k, l; scanf("%d%d%d%d", &i, &j, &k, &l);
    -- i; -- j; -- k; -- l;
    if (j < k || i > l) {
      if (get1(k, l) == get2(k, l)) puts("Yes");
      else puts("No");
      continue;
    }
    if (i <= k && l <= j) {
      k = j - (k - i);
      l = i + (j - l);
      swap(k, l);
      if (get1(k, l) == get2(k, l)) puts("Yes");
      else puts("No");
      continue;
    }
    if (k <= i && j <= l) {
      LL s = get1(k, i - 1);
      s += get2(i, j) * pw[i - k];
      s += get1(j + 1, l) * pw[j - k + 1];

      LL t = get2(k, i - 1) * pw[l - i + 1];
      t += get1(i, j) * pw[l - j];
      t += get2(j + 1, l);
      if (s == t) puts("Yes");
      else puts("No");
      continue;
    }
    if (k <= j && j <= l) {
      int m = j - k, r = k - i;
      LL s = get2(i, i + m) + get1(j + 1, l) * pw[m + 1];
      LL t = get1(i, i + m) * pw[l - j] + get2(j + 1, l);
      if (s == t) puts("Yes");
      else puts("No");
      continue;
    }
    if (k <= i && i <= l) {
      int m = l - i, r = j - l;
      LL s = get1(k, i - 1) + get2(j - m, j) * pw[i - k];
      LL t = get2(k, i - 1) * pw[m + 1] + get1(j - m, j);
      if (s == t) puts("Yes");
      else puts("No");
      continue;
    }
  }
  return 0;
}

