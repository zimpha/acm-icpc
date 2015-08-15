#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int prefix[10], cnt;
unordered_map<int, LL> dp[1 << 10][15];
LL N, M;

int get(int v) {
  if (prefix[v] == -1) {
    if (cnt == 0) return 1;
    else if (cnt == 1) return 0;
    else return cnt;
  }
  else return prefix[v];
}

LL calc(int msk, int len, int s) {
  if (dp[msk][len].count(s)) return dp[msk][len][s];
  s %= M;
  if (len == 0) return s;
  -- len;
  if (!msk) return 9 * calc(2, len, 1);
  if (msk == 2) return 9 * calc(3, len, s * 10) + calc(2, len, s * 10 + 1);
  LL ret(0);
  for (int i = 0; i < 10; ++ i) {
    if (msk >> i & 1) {
      ret += calc(msk, len, s * 10 + i);
    }
    else {
      ret += (10 - i) * calc(msk | (1 << i), len, s * 10 + i);
      break;
    }
  }
  return dp[msk][len][s] = ret;
}

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    memset(prefix, -1, sizeof(prefix)); cnt = 0;
    scanf("%lld%lld", &N, &M); ++ N;
    int len(0), msk(0), s(0);
    LL pw(1), ret(0), pr(1);
    while (pw * 10 < N) pw *= 10, ++ len;
    for (int i = 1; i <= len; ++ i) ret += calc(0, i, 0);
    while (len >= 0) {
      int add;
      while ((pr + 1) * pw <= N) {
        add =get(pr % 10); ++ pr; 
        ret += calc(msk | (1 << add), len, s + add);
      }
      add = get(pr % 10);
      msk |= 1 << add;
      s = (s + add) * 10 % M;
      if (prefix[pr % 10] == -1) {
        prefix[pr % 10] = add;
        ++ cnt;
      }
      pr *= 10; -- len; pw /= 10;
    }
    cout << ret << endl;
  }
  return 0;
}

