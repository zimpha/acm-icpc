#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 100000 + 10;

int main() {
  string s; cin >> s;
  int n = s.size() + 1, c(1);
  vector<int> ret, v;
  for (size_t i(0); i < s.size(); ++ i) {
    if (s[i] == 'I') ++ c;
    else v.push_back(c), c = 1;
  }
  v.push_back(c); ret.clear();
  for (size_t i = 0; i < v.size(); ++ i) {
    n -= v[i];
    for (int d = 1; d <= v[i]; ++ d) ret.push_back(n + d);
  }
  for (size_t i = 0; i < ret.size(); ++ i) printf("%d ", ret[i]);
  puts("");
  return 0;
}

