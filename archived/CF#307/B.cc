#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
int ca[26], cb[26], cc[26];
string a, b, c;

int main() {
  cin >> a >> b >> c;
  for (char x: a) ca[x - 'a'] ++;
  for (char x: b) cb[x - 'a'] ++;
  for (char x: c) cc[x - 'a'] ++;
  int rb(0), rc(0);
  for (int sb = 0; ; ++ sb) {
    bool flag = true;
    for (int i = 0; i < 26; ++ i) {
      if (ca[i] < cb[i] * sb) flag = false;
    }
    if (!flag) break;
    int sc(1e9);
    for (int i = 0; i < 26; ++ i) if (cc[i]) {
      sc = min(sc, (ca[i] - cb[i] * sb) / cc[i]);
    }
    if (sc + sb > rb + rc) rb = sb, rc = sc;
  }
  for (int i = 0; i < rb; ++ i) cout << b;
  for (int i = 0; i < rc; ++ i) cout << c;
  for (int i = 0; i < 26; ++ i) {
    ca[i] -= rb * cb[i] + rc * cc[i];
    while (ca[i] --) cout << char('a' + i);
  }
  cout << endl;
  return 0;
}

