#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 1000000 + 10;

char s[MAXN];
char t[10000];
int nx[10000], sum[1000];

int main() {
  for (int i = 0; i < 1000; ++ i) {
    sum[i] = (i % 10) + (i / 10 % 10) + i / 100;
  }
  for (int i = 0; i < 1000000; ++ i) {
    int l = i % 1000, r = i / 1000;
    if (sum[l] == sum[r]) s[i] = 'L';
    else s[i] = 'U';
  }
  int n; scanf("%d", &n);
  scanf("%s", t);
  nx[0] = -1;
  for (int i=1,j=-1; i < n; ++ i) {
    while (j >= 0 && t[j + 1] != t[i]) j = nx[j];
    nx[i] = (t[j + 1] == t[i]) ? ++ j : j;
  }
  int ret(-1);
  for (int i = 0,j=-1; i < 1000000; ++ i) {
    while (j >= 0 && t[j + 1] != s[i]) j = nx[j];
    if (t[j + 1] == s[i]) ++ j;
    if (j + 1 == n) {
      ret = i - n + 1;
      break;
    }
  }
  if (ret == -1) puts("No solution");
  else printf("%06d\n", ret);
  return 0;
}

