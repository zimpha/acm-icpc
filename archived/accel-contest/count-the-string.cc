#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 100000 + 10;
char s[MAXN];
int c[26], n, k;

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    scanf("%d%d%s", &n, &k, s);
    memset(c, 0, sizeof(c));
    for (int i = 0; s[i]; ++ i) c[s[i] - 'a'] ++;
    vector<PII> v;
    for (int i = 0; i < 26; ++ i) {
      if (c[i] > k) v.push_back(PII(c[i], -i));
    }
    sort(v.begin(), v.end(), greater<PII>());
    for (auto &x: v) putchar('a' - x.second);
    if (v.empty()) printf("NONE");
    puts("");
  }
  return 0;
}

