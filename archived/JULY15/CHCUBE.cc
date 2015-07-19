#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

char c[6][10];

bool eq(int a, int b) {
  return strcmp(c[a], c[b]) == 0;
}

bool solve() {
  if (eq(0, 3) && eq(0, 4) && eq(4, 3)) return true;
  if (eq(0, 3) && eq(0, 5) && eq(5, 3)) return true;
  if (eq(1, 3) && eq(1, 4) && eq(4, 3)) return true;
  if (eq(1, 3) && eq(1, 5) && eq(5, 3)) return true;
  if (eq(0, 2) && eq(0, 4) && eq(4, 2)) return true;
  if (eq(0, 2) && eq(0, 5) && eq(2, 5)) return true;
  if (eq(1, 2) && eq(1, 4) && eq(4, 2)) return true;
  if (eq(1, 2) && eq(1, 5) && eq(2, 5)) return true;
  return false;
}

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    for (int i = 0; i < 6; ++ i) scanf("%s", c[i]);
    if (solve()) puts("YES");
    else puts("NO");
  }
  return 0;
}

