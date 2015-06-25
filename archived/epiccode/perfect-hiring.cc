#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
  int n; scanf("%d", &n);
  int p, x; scanf("%d%d", &p, &x);
  LL mx(0);
  int id(-1);
  for (int i = 0; i < n; ++ i) {
    int a; scanf("%d", &a);
    if ((LL)a * p > mx) mx = (LL)a * p, id = i;
    p -= x;
  }
  printf("%d\n", id + 1);
  return 0;
}
