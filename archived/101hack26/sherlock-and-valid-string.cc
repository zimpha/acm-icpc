#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int main() {
  string s; cin >> s;
  static int cnt[26];
  for (size_t i = 0; i < s.size(); ++ i) {
    cnt[s[i] - 'a'] ++;
  }
  bool flag = false;
  for (int i = -1; i < 26; ++ i) if (i == -1 || cnt[i]) {
    int c[26]; memcpy(c, cnt, sizeof(cnt));
    if (i >= 0) c[i] --; bool ok(1);
    sort(c, c + 26, greater<int>());
    for (int j = 0; j < 26; ++ j) {
      if (c[j]) ok &= c[j] == c[0];
    }
    if (ok) flag = true;
  }
  puts(flag ? "YES" : "NO");
  return 0;
}

