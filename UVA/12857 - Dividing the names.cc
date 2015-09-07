#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200 + 10, SIZE = MAXN * 20;

struct Node {
  Node *ch[26];
  int sz, dp[26][110][2][2];
}pool[SIZE], *rt, *cnt;

Node *newNode() {
  memset(cnt->dp, -1, sizeof(cnt->dp));
  memset(cnt->ch, 0, sizeof(cnt->ch));
  cnt->sz = 0; return cnt ++;
}

void ins(char *s) {
  Node *p = rt; p->sz ++;
  for (int i = 0; s[i]; ++ i) {
    int o = s[i] - 'A';
    if (p->ch[o] == NULL) p->ch[o] = newNode();
    p = p->ch[o]; p->sz ++;
  }
}

int solve(Node *p, int c, int st, int av, int fs, int fa) {
  if (!fs && !fa) return 0;
  int &ret = p->dp[c][st][fs][fa];
  if (ret != -1) return ret;
  if (p->ch[c] == NULL) return ret = solve(p, c + 1, st, av, fs, fa);
  Node *q = p->ch[c]; ret = 1e9;
  int cnt = fs * st + fa * av;
  if (c == 25) return ret = cnt + solve(q, 0, st, av, st > 1, av > 1);
  for (int i = max(0, q->sz - av); i <= min(q->sz, st); ++ i) {
    int j = q->sz - i, tmp = fs * i + fa * j;
    tmp += solve(q, 0, i, j, fs & (i > 1), fa & (j > 1));
    tmp += solve(p, c + 1, st - i, av - j, fs & (st > i), fa & (av > j));
    ret = min(ret, tmp);
  }
  return ret;
}

char s[MAXN];
int n;

int main() {
  while (scanf("%d", &n) == 1) {
    cnt = pool; rt = newNode();
    for (int i = 0; i < 2 * n; ++ i) {
      scanf("%s", s);
      ins(s);
    }
    int ret = solve(rt, 0, n, n, 1, 1) * n;
    printf("%d\n", ret);
  }
  return 0;
}
