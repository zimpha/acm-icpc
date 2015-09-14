#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 10000 + 10;
char s[100][100];
vector<int> vs[MAXN];
stack<PII> stk[26];
int top;

void add(int x, int r, int c) {
  vs[top].push_back(x);
  if (!stk[x].empty()) {
    int r1 = stk[x].top().first;
    int c1 = stk[x].top().second;
    printf("%d:%d: warning: shadowed declaration of %c, the shadowed position is %d:%d\n", r, c, x + 'a', r1, c1);
  }
  stk[x].push(PII(r, c));
}

int main() {
  int n; scanf("%d%*c", &n);
  for (int i = 0; i < n; ++ i) gets(s[i]);
  top = 0; vs[0].clear();
  for (int i = 0; i < n; ++ i) {
    for (int j = 0; s[i][j]; ++ j) {
      char c = s[i][j];
      if (c == '{') vs[++ top].clear();
      else if (c == '}') {
        for (auto &x: vs[top]) stk[x].pop();
        -- top;
      }
      else if (c != ' ') add(c - 'a', i + 1, j + 1);
    }
  }
  return 0;
}
