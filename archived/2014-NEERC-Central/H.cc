#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 100000 + 10;
unsigned int a[MAXN];
int n;

bool check(int l, int r, int k, int b) {
  vector<int> v;
  for (int i = l; i < r; ++ i) {
    v.push_back((a[i] >> k & 1) ^ b);
  }
  v.erase(unique(v.begin(), v.end()), v.end());
  return v.size() == 1 || (v.size() == 2 && v[0] == 1);
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++ i) scanf("%u", a + i);
  reverse(a, a + n);
  unsigned int ret(0), flag(1);
  vector<PII> pt; pt.push_back(PII(0, n));
  for (int i = 31; i >= 0; -- i) {
    bool f1(1), f2(1);
    for (auto &x: pt) {
      f1 &= check(x.first, x.second, i, 0);
      f2 &= check(x.first, x.second, i, 1);
    }
    if ((f1 && f2) || (!f1 && !f2)) {flag = 0; break;}
    vector<PII> tmp;
    if (f1) {
      for (auto &x: pt) {
        int c(0);
        for (int j = x.first; j < x.second; ++ j) {
          if (a[j] >> i & 1) ++ c;
        }
        if (c == 0 || c == x.second - x.first) tmp.push_back(x);
        else {
          tmp.push_back(PII(x.first, x.first + c));
          tmp.push_back(PII(x.first + c, x.second));
        }
      }
    }
    else if (f2) {
      ret |= 1 << i;
      for (auto &x: pt) {
        int c(0);
        for (int j = x.first; j < x.second; ++ j) {
          if (!(a[j] >> i & 1)) ++ c;
        }
        if (c == 0 || c == x.second - x.first) tmp.push_back(x);
        else {
          tmp.push_back(PII(x.first, x.first + c));
          tmp.push_back(PII(x.first + c, x.second));
        }
      }
    }
    pt = tmp;
  }
  if (flag) printf("%u\n", ret);
  else puts("Impossible");
  return 0;
}