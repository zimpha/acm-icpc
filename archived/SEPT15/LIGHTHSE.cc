#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 100000 + 10;
int x[MAXN], y[MAXN], n;

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++ i) {
      scanf("%d%d", x + i, y + i);
    }
    // NE
    int r(0), cnt(0);
    for (int i = 0; i < n; ++ i) {
      if (x[i] < x[r] || (x[i] == x[r] && y[i] < y[r])) r = i;
    }
    for (int i = cnt = 0; i < n; ++ i) cnt += x[i] >= x[r] && y[i] >= y[r];
    if (cnt == n) {
      puts("1");
      printf("%d NE\n", r + 1);
      continue;
    }
    // SE
    for (int i = 0; i < n; ++ i) {
      if (x[i] < x[r] || (x[i] == x[r] && y[i] > y[r])) r = i;
    }
    for (int i = cnt = 0; i < n; ++ i) cnt += x[i] >= x[r] && y[i] <= y[r];
    if (cnt == n) {
      puts("1");
      printf("%d SE\n", r + 1);
      continue;
    }
    // NW
    for (int i = 0; i < n; ++ i) {
      if (x[i] > x[r] || (x[i] == x[r] && y[i] < y[r])) r = i;
    }
    for (int i = cnt = 0; i < n; ++ i) cnt += x[i] <= x[r] && y[i] >= y[r];
    if (cnt == n) {
      puts("1");
      printf("%d NW\n", r + 1);
      continue;
    }
    // SW
    for (int i = 0; i < n; ++ i) {
      if (x[i] > x[r] || (x[i] == x[r] && y[i] > y[r])) r = i;
    }
    for (int i = cnt = 0; i < n; ++ i) cnt += x[i] <= x[r] && y[i] <= y[r];
    if (cnt == n) {
      puts("1");
      printf("%d SW\n", r + 1);
      continue;
    }
    int a(0), b(0);
    for (int i = 0; i < n; ++ i) {
      if (y[i] > y[a] || (y[i] == y[a] && x[i] < x[a])) a = i;
      if (y[i] < y[b] || (y[i] == y[b] && x[i] > x[b])) b = i;
    }
    puts("2");
    if (x[a] > x[b]) {
      printf("%d SW\n", a + 1);
      printf("%d NE\n", b + 1);
    }
    else {
      printf("%d SE\n", a + 1);
      printf("%d NW\n", b + 1);
    }
  }
  return 0;
}

