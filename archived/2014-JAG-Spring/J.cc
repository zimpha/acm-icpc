#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 100000 + 10;
int s[MAXN], n, a, b;

bool nim(int m) {
  int r = 0;
  for (int i = 0; i < n; ++ i) {
    r ^= s[i] % m;
  }
  return r != 0;
}

bool solve() {
  if (a == b) return nim(a + 1);
  else if (a > b) {
    if (nim(b + 1)) return true;
    else return s[0] >= b + 1;
  }
  else {
    if (s[0] <= a) return nim(a + 1);
    else if (n >= 2 && s[0] > a && s[1] > a) return false;
    else {
      int r = 0;
      for (int i = 1; i < n; ++ i) r ^= s[i];
      if (r > a || (s[0] - r) > a) return false;
      else return true;
    }
  }
}

int main() {
  scanf("%d%d%d", &n, &a, &b);
  for (int i = 0; i < n; ++ i) scanf("%d", s + i);
  sort(s, s + n, greater<int>());
  puts(solve() ? "Hanako" : "Jiro");
  return 0;
}