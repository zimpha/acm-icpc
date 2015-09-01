#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int D[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

void solve(int n) {
  for (int h = 0; h < 24; ++ h) {
    for (int m = 0; m < 60; ++ m) {
      int x = D[h % 10] + D[h / 10] + D[m % 10] + D[m / 10];
      if (x == n) {
        printf("%02d:%02d\n", h, m);
        return;
      }
    }
  }
  puts("Impossible");
}
int main() {
  freopen("alarm.in", "r", stdin);
  freopen("alarm.out", "w", stdout);
  int n; scanf("%d", &n);
  solve(n);
  return 0;
}