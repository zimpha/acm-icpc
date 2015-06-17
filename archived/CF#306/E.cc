#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000 + 10;
int a[MAXN], n;

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++ i) scanf("%d", a + i);
  if (a[n - 1] == 1) {puts("NO"); return 0;}
  if (n == 1 && a[0] == 0) {puts("YES\n0"); return 0;}
  int cnt(0), c1(0);
  for (int i = 0; i < n && a[i]; ++ i) ++ c1;
  for (int i = n - 1; i >= 0 && !a[i]; -- i) ++ cnt;
  if (c1 + cnt == n && cnt == 2) {puts("NO"); return 0;}
  puts("YES");
  if (cnt == 1) {
    printf("%d", a[0]);
    for (int i = 1; i < n; ++ i) printf("->%d", a[i]);
    puts("");
    return 0;
  }
  if (cnt >= 3) {
    for (int i = 0; i < n - 3; ++ i) {
      printf("%d->", a[i]);
    }
    printf("(0->0)->0\n");
    return 0;
  }
  int x;
  for (x = n - 3; x >= 0 && a[x]; -- x);
  for (int i = 0; i < x; ++ i) printf("%d->", a[i]);
  printf("(0->(");
  for (int i = x + 1; i < n - 2; ++ i) printf("1->");
  printf("0))->0\n");
  return 0;
}
