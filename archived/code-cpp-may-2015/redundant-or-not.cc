#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; scanf("%d", &n);
  set<int> S;
  for (int i = 0; i < n; ++ i) {
    int x; scanf("%d", &x);
    if (S.count(x)) puts("REDUNDANT");
    else puts("ADDED");
    S.insert(x);
  }
  return 0;
}
