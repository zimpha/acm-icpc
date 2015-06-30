#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 100000 + 10;
LL A[MAXN], B[MAXN];

int u[MAXN], n;

void add(int x, int v) {
  for (; x <= n; x += ~x & x + 1) u[x] = min(u[x], v);
}
int get(int x) {
  int r(1e9);
  for (; x >= 0; x -= ~x & x + 1) r = min(r, u[x]);
  return r;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++ i) {
    scanf("%lld", A + i);
  }
  vector<LL> X;
  int ret(0);
  LL sum(0);
  for (int i = 0; i < n; ++ i) {
    scanf("%lld", B + i);
    A[i] -= B[i];
    if (A[i] >= 0) sum += A[i], ++ ret;
    else X.push_back(-A[i]);
  }
  sort(X.begin(), X.end());
  for (size_t i = 0; i < X.size(); ++ i) {
    if (sum - X[i] >= 0) sum -= X[i], ++ ret;
    else break;
  }
  printf("%d\n", ret);
  return 0;
}

