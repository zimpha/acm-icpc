#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int A[100][100];

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; ++ i) {
      for (int j = 1; j <= n; ++ j) {
        scanf("%d", &A[i][j]);
        A[i][j] ^= A[i - 1][j] ^ A[i][j - 1] ^ A[i - 1][j - 1];
      }
    }
    int ret(0);
    for (int x1 = 1; x1 <= n; ++ x1) {
      for (int y1 = 1; y1 <= n; ++ y1) {
        for (int x2 = x1; x2 <= n; ++ x2) {
          for (int y2 = y1; y2 <= n; ++ y2) {
            int tmp = A[x2][y2] ^ A[x2][y1 - 1] ^ A[x1 - 1][y2] ^ A[x1 - 1][y1 - 1];
            if (tmp > ret) ret = tmp;
          }
        }
      }
    }
    printf("%d\n", ret);
  }
  return 0;
}

