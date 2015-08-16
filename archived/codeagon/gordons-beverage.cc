#include <bits/stdc++.h>
using namespace std;
const int S = 210, D = 101;

int A[S][S][S];

int main() {
  int N; scanf("%d", &N);
  for (int i = 0; i < N; ++ i) {
    int x, y, z; scanf("%d%d%d", &x, &y, &z);
    x += D; y += D; z += D;
    A[x][y][z] ++;
  }
  for (int i = 1; i < S; ++ i) {
    for (int j = 1; j < S; ++ j) {
      for (int k = 1; k < S; ++ k) {
        A[i][j][k] += A[i - 1][j][k] + A[i][j - 1][k] + A[i][j][k - 1];
        A[i][j][k] -= A[i - 1][j - 1][k] + A[i - 1][j][k - 1] + A[i][j - 1][k - 1];
        A[i][j][k] += A[i - 1][j - 1][k - 1];
      }
    }
  }
  int M; scanf("%d", &M);
  for (int i = 0; i < M; ++ i) {
    int x1, y1, z1, x2, y2, z2;
    scanf("%d%d%d", &x1, &y1, &z1); x1 += D; y1 += D; z1 += D;
    scanf("%d%d%d", &x2, &y2, &z2); x2 += D; y2 += D; z2 += D;
    if (x2 - x1 < 3 || y2 - y1 < 3 || z2 - z1 < 3) {
      puts("0");
      continue;
    }
    x1 += 2; y1 += 2; z1 += 2;
    int ret = A[x2][y2][z2] - A[x1][y2][z2] - A[x2][y1][z2] - A[x2][y2][z1];
    ret += A[x1][y1][z2] + A[x1][y2][z1] + A[x2][y1][z1];
    ret -= A[x1][y1][z1];
    printf("%d\n", ret);
  }
  return 0;
}