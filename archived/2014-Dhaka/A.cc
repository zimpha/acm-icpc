#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 1000000 + 10;
char s[MAXN], a[256];
set<int> mp[26];

void change(int a, int b) {
  for (auto &x: mp[a]) mp[b].insert(x);
  mp[a].clear();
}

int main() {
  int T; scanf("%d", &T);
  for (int cas = 1; cas <= T; ++ cas) {
    for (int i = 0; i < 26; ++ i) mp[i].clear();
    scanf("%s", s);
    for (int i = 0; s[i]; ++ i) {
      if (s[i] == '_') continue;
      int x = s[i] - 'A';
      mp[x].insert(x);
    }
    int m; scanf("%d", &m);
    for (int i = 0; i < m; ++ i) {
      char a[10], b[10]; scanf("%s%s", a, b);
      change(b[0] - 'A', a[0] - 'A');
    }
    a['_'] = '_';
    for (int i = 0; i < 26; ++ i) {
      for (auto &x: mp[i]) a[x + 'A'] = i + 'A';
    }
    for (int i = 0; s[i]; ++ i) s[i] = a[s[i]];
    puts(s);
  }
  return 0;
}
