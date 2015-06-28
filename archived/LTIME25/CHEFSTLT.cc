#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int main() {
  int T; cin >> T;
  for (int _ = 0; _ < T; ++ _) {
    string s1, s2; cin >> s1 >> s2;
    int r1(0), r2(0);
    for (size_t i = 0; i < s1.size(); ++ i) {
      if (s1[i] != '?' && s2[i] != '?') {
        if (s1[i] != s2[i]) r1 ++, r2 ++;
      }
      else r2 ++;
    }
    cout << r1 << " " << r2 << endl;
  }
  return 0;
}

