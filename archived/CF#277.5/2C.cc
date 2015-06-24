#include <bits/stdc++.h>
using namespace std;

bool ok(int l, int s) {
  return s >= 0 && s <= l * 9;
}

string large(int l, int s) {
  string r;
  for (int i = 0; i < l; ++ i) {
    if (!ok(l - i, s)) return "-1";
    for (int d = 9; d >= 0; -- d) {
      if ((i > 0 || d > 0 || (l == 1 && d == 0)) && ok(l - i - 1, s - d)) {
        r += char('0' + d); s -= d;
        break;
      }
    }
    if (r.size() != i + 1) return "-1";
  }
  return r;
}

string small(int l, int s) {
  string r;
  for (int i = 0; i < l; ++ i) {
    if (!ok(l - i, s)) return "-1";
    for (int d = 0; d <= 9; ++ d) {
      if ((i > 0 || d > 0 || (l == 1 && d == 0)) && ok(l - i - 1, s - d)) {
        r += char('0' + d); s -= d;
        break;
      }
    }
    if (r.size() != i + 1) return "-1";
  }
  return r;
}

int main() {
  int n, s;
  scanf("%d%d", &n, &s);
  cout << small(n, s) << " " << large(n, s) << endl;
  return 0;
}