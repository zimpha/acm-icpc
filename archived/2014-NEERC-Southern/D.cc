#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL, int> PII;

vector<PII> low, upp;
int n;
LL m;

int main() {
  scanf("%d%lld", &n, &m);
  for (int i = 0, l; i < n; ++ i) {
    LL x; scanf("%lld%d", &x, &l);
    if (l) low.push_back(PII(x, i + 1));
    else upp.push_back(PII(x, i + 1));
  }
  upp.push_back(PII(1ll<<60, -1));
  sort(low.begin(), low.end(), greater<PII>());
  sort(upp.begin(), upp.end(), greater<PII>());
  upp[0].first = 0;
  for (size_t i = 1; i < upp.size(); ++ i) {
    upp[i].first += upp[i - 1].first;
  }
  int rm(1e9), rl(1e9);
  LL sum(0);
  for (size_t i = 0; i <= low.size(); ++ i) {
    LL need = m - sum;
    size_t j = lower_bound(upp.begin(), upp.end(), PII(need, -1)) - upp.begin();
    if (j != upp.size()) {
      if (i + j <= rm) rm = i + j, rl = i;
    }
    if (i < low.size()) sum += low[i].first;
  }
  printf("%d %d\n", rm, rl);
  for (int i = 0; i < rl; ++ i) printf("%d ", low[i].second);
  for (int i = 0; i < rm - rl; ++ i) {
    printf("%d ", upp[i + 1].second);
  }
  puts("");
  return 0;
}

