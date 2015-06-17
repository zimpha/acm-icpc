#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
const int MAXN = 300000 + 10;
int cnt[MAXN], n, ret;

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++ i) {
    int l, h; scanf("%d%d", &l, &h);
    ++ l; ++ h; cnt[l] ++; cnt[h + 1] --;
  }
  for (int i = 1; i <= n; ++ i) cnt[i] += cnt[i - 1];
  for (int i = 0; i <= n; ++ i) {
    if (cnt[i] >= i) ret = i;
  }
  printf("%d\n", ret);
  return 0;
}