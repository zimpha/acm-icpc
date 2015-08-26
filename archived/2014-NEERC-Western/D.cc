#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
typedef long long LL;
const int MAXN = 100000 + 10;
int c[MAXN], n;

int main() {
  scanf("%d", &n);
  vector<PII> p, ret;
  for (int i = 0; i < n; ++ i) {
    int x; scanf("%d", &x);
    p.push_back(PII(x, i));
  } 
  memset(c, -1, sizeof(c));
  sort(p.begin(), p.end(), greater<PII>());
  int len = p[0].first, flag = true;
  for (auto &v : p) {
    int d = v.first, u = v.second;
    if (c[d] == -1) {
      c[d] = u; v.first = -1;
      if (len - d > d) flag = false;
    }
    else if (c[len - d] == -1) {
      c[len - d] = u; v.first = -1;
      if (len - d > d) flag = false;
    }
  }
  for (int i = 0; i <= len; ++ i) {
    if (c[i] == -1) flag = false;
  }
  for (int i = 0; i < len; ++ i) ret.push_back(PII(c[i], c[i + 1]));
  for (auto &v : p) if (v.first != -1) {
    int d = v.first, u = v.second;
    -- d; ret.push_back(PII(c[d], u));
    if (len - d > d) flag = false;
  }
  if (flag) {
    puts("I got it");
    for (auto &v : ret) {
      printf("%d %d\n", v.first + 1, v.second + 1);
    }
  }
  else puts("Epic fail");
  return 0;
}