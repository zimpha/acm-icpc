#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int MAXN = 100000 + 10;

char s[MAXN];
int a[MAXN], b[MAXN];

int main() {
  int n; scanf("%d", &n); ++ n;
  scanf("%s", s + 1);
  a[0] = 0; b[n + 1] = 0;
  for (int i = 1; i <= n; ++ i) {
    a[i] = a[i - 1];
    if (i & 1) a[i] += s[i] - '0';
    else a[i] -= s[i] - '0';
  }
  for (int i = n; i >= 1; -- i) {
    b[i] = b[i + 1];
    if (i & 1) b[i] += s[i] - '0';
    else b[i] -= s[i] - '0';
  }
  int ret(0);
  for (int i = 1; i <= n; ++ i) {
    int t = a[i - 1] - b[i + 1];
    if (abs(t) % 11 == 0) ++ ret;
  }
  printf("%d\n", ret);
  return 0;
}
