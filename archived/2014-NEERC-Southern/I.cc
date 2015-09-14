#include <bits/stdc++.h>
using namespace std;
const int MAXN =  2000 + 10;

int p[MAXN], n;

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++ i) scanf("%d", p + i);
  sort(p, p + n);
  int c = 1;
  for (int i = 0, s = 0; i + 1 < n; ++ i) {
    if (s + p[i] <= p[n - 1]) s += p[i], ++ c;
  }
  printf("%d\n", c);
}
