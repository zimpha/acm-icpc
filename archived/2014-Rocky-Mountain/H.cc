#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 100;
LL C[MAXN][MAXN];
int a[MAXN], n;

int main() {
  for (int i = 0; i <= 60; ++ i) {
    C[i][0] = C[i][i] = 1;
    for (int j = 0; j < i; ++ j) {
      C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
    }
  }
  while (scanf("%d", &n) == 1 && n) {
    int s(0);
    for (int i = 0; i < n; ++ i) {
      scanf("%d", a + i); 
      s += a[i];
    }
    LL ret(0);
    for (int i = 0; i < s; ++ i) {
      ret += C[i + n - 1][n - 1];
    }
    for (int i = 0, x(0); i < n; ++ i) {
      for (int j = 0; j < a[i]; ++ j) {
        int t = s - x, r = n - i - 1;
        if (r) ret += C[t + r - 1][r - 1];
        x ++;
      }
    }
    ++ ret; cout << ret << endl;
  }
  return 0;
}

