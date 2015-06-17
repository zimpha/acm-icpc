#include <bits/stdc++.h>
using namespace std;

int a[9][9];

bool ok() {
  static int cnt[9];
  for (int i = 0; i < 9; ++ i) {
    for (int j = 0; j < 9; ++ j) cnt[j] = 0;
    for (int j = 0; j < 9; ++ j) cnt[a[i][j]] ++;
    for (int j = 0; j < 9; ++ j) if (cnt[j] != 1) return false;
  }
  for (int i = 0; i < 9; ++ i) {
    for (int j = 0; j < 9; ++ j) cnt[j] = 0;
    for (int j = 0; j < 9; ++ j) cnt[a[j][i]] ++;
    for (int j = 0; j < 9; ++ j) if (cnt[j] != 1) return false;
  }
  for (int i = 0; i < 3; ++ i) {
    for (int j = 0; j < 3; ++ j) {
      for (int k = 0; k < 9; ++ k) cnt[k] = 0;
      for (int x = 0; x < 3; ++ x) {
        for (int y = 0; y < 3; ++ y) {
          cnt[a[i * 3 + x][j * 3 + y]] ++;
        }
      }
      for (int k = 0; k < 9; ++ k) if (cnt[k] != 1) return false;
    }
  }
  return true;
}

int main() {
  int T; scanf("%d", &T);
  for (int cas = 1; cas <= T; ++ cas) {
    for (int i = 0; i < 9; ++ i) {
      for (int j = 0; j < 9; ++ j) {
        scanf("%d", &a[i][j]); a[i][j] --;
      }
    }
    printf("Case #%d:\n", cas);
    if (ok()) {puts("Serendipity"); continue;}
    for (int x1 = 0; x1 < 9; ++ x1) {
      for (int y1 = 0; y1 < 9; ++ y1) {
        for (int x2 = x1; x2 < 9; ++ x2) {
          for (int y2 = (x1 == x2) ? y1 : 0; y2 < 9; ++ y2) {
            swap(a[x1][y1], a[x2][y2]);
            if (ok()) {
              printf("(%d,%d) <-> (%d,%d)\n", x1 + 1, y1 + 1, x2 + 1, y2 + 1);
            }
            swap(a[x1][y1], a[x2][y2]);
          }
        }
      }
    }
  }
  return 0;
}