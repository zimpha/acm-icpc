#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1000000 + 10;
char s[MAXN];
int cnt[3], n;

int main() {
  while (scanf("%s", s) == 1) {
    n = strlen(s);
    LL ret = 0;
    memset(cnt, 0, sizeof(cnt)); cnt[0] = 1;
    for (int i = 0, sum = 0; i < n; ++ i) {
      if (isdigit(s[i])) {
        sum = (sum + s[i] - '0') % 3;
        ret += cnt[sum]; cnt[sum] ++;
      }
      else {
        memset(cnt, 0, sizeof(cnt)); 
        cnt[0] = 1; sum = 0;
      }
    }
    printf("%lld\n", ret);
  }
  return 0;
}
