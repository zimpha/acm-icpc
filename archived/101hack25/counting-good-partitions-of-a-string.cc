#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int main() {
  string s; cin >> s;
  int c[26]; memset(c, 0, sizeof(c));
  for (char x: s) if (x != s[0]) c[x - 'a'] ++;
  int r = 1;
  for (int i = 0; i < 26; ++ i) if (c[i]) r = r * c[i] % 1000;
  cout << r << endl;
  return 0;
}

