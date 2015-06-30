#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int main() {
  string s; cin >> s;
  static int cnt[26];
  for (char c: s) cnt[c - 'a'] ++;
  int c(0);
  for (int i = 1; i < 26; ++ i) {
    if (cnt[i] > cnt[c]) c = i;
  }
  putchar('a' + c); puts("");
  return 0;
}

