#include <bits/stdc++.h>
using namespace std;

int main() {
  int T; cin >> T;
  for (int _ = 0; _ < T; ++ _) {
    set<int> S;
    int n; cin >> n;
    for (int i = 0; i < n; ++ i) {
      int x; cin >> x;
      S.insert(x);
    }
    cout << S.size() << endl;
  }
  return 0;
}