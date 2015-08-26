#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 1000 + 10;
int cnt[MAXN], n;

int main() {
  //freopen("election.in", "r", stdin);
  //freopen("election.out", "w", stdout);
  scanf("%d", &n);
  int l = 0, r = 0;
  for (int i = 0; i < n; ++ i) {
    int x; scanf("%d", &x);
    l += max(x * 2 - 1, 0), r += x * 2 + 1;
  }
  bool flag = 200 >= l && 200 < r;
  puts(flag ? "Yes" : "No");
  return 0;
}