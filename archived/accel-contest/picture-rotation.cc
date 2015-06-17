#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 1000 + 10;

char A[MAXN][MAXN], B[MAXN][MAXN];
int mp[MAXN][MAXN], cov[MAXN], n;

void getmp() {
  for (int i = 0; i < n; ++ i) {
    for (int j = 0; j < n; ++ j) {
      mp[i][j] = (A[i][j] == B[i][j]);
    }
  }
}

void rotate() {
  static char C[MAXN][MAXN];
  for (int i = 0; i < n; ++ i) {
    for (int j = 0; j < n; ++ j) {
      C[i][j] = A[n - j - 1][i];
    }
  }
  for (int i = 0; i < n; ++ i) {
    for (int j = 0; j < n; ++ j) {
      A[i][j] = C[i][j];
    }
  }
}

void cover() {
  for (int i = 0; i < (n + 1) / 2; ++ i) if (!cov[i]) {
    int l = n - i * 2; cov[i] = 1;
    for (int j = 0; j < l; ++ j) {
      if (!mp[i][i + j] || !mp[i + l - 1][i + j]) cov[i] = 0;
    }
    for (int j = 0; j < l; ++ j) {
      if (!mp[i + j][i] || !mp[i + j][i + l - 1]) cov[i] = 0;
    }
  }
}

int main() {
  scanf("%d", &n); getchar();
  for (int i = 0; i < n; ++ i) gets(A[i]);
  for (int i = 0; i < n; ++ i) gets(B[i]);
  rotate(); getmp(); cover();
  rotate(); getmp(); cover();
  rotate(); getmp(); cover();
  rotate(); getmp(); cover();
  for (int i = 0; i < (n + 1) / 2; ++ i) {
    if (!cov[i]) {puts("NO"); return 0;}
  }
  puts("YES");
  return 0;
}

