#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    int cnt[26]; memset(cnt, 0, sizeof(cnt));
    char s[200]; scanf("%s", s);
    for (int i = 0; s[i]; ++ i) cnt[s[i] - 'a'] ++;
    scanf("%s", s);
    for (int i = 0; s[i]; ++ i) cnt[s[i] - 'a'] --;
    int D; scanf("%d", &D);
    for (int i = 0; i < 26; ++ i) D -= abs(cnt[i]);
    if (D >= 0) puts("YES");
    else puts("NO");
  }
  return 0;
}

