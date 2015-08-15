#include <bits/stdc++.h>
using namespace std;

int main() {
  int T; cin >> T;
  for (int _ = 0; _ < T; ++ _) {
    string s; cin >> s;
    int c[2] = {0, 0};
    for (char x : s) c[x - '0'] ++;
    if (c[0] > c[1]) puts("LOSE");
    else puts("WIN");
  }
  return 0;
}
