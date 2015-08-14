#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int main() {
  int T; cin >> T;
  for (int _ = 0; _ < T; ++ _) {
    int n, m; cin >> n >> m;
    string buf; getline(cin, buf);
    vector<int> clause[200];
    for (int i = 0; i < m; ++ i) {
      getline(cin, buf);
      stringstream sin(buf);
      while (sin >> buf) {
        int x;
        if (buf[0] == '~') {
          sscanf(buf.c_str() + 2, "%d", &x);
          x = -x;
        }
        else {
          sscanf(buf.c_str() + 1, "%d", &x);
        }
        clause[i].push_back(x);
        if (!(sin >> buf)) break;
      }
    }
    bool flag = true;
    for (int msk = 0; msk < (1 << n); ++ msk) {
      flag = true;
      for (int i = 0; i < m; ++ i) {
        int r(0);
        for (int x: clause[i]) {
          int t = abs(x) - 1;
          if (x > 0) r |= msk >> t & 1;
          else r |= !(msk >> t & 1);
        }
        if (!r) {flag = false; break;}
      }
      if (flag) break;
    }
    if (flag) puts("satisfiable");
    else puts("unsatisfiable");
  }
  return 0;
}

