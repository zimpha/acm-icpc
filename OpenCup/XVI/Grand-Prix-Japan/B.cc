#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 3000 + 10;

int nx[MAXN][4], st[MAXN][4];
int x[MAXN], y[MAXN], d[MAXN];
int id[MAXN], n;

bool cmpx(int a, int b) {
  return x[a] < x[b] || (x[a] == x[b] && y[a] < y[b]);
}
bool cmpy(int a, int b) {
  return y[a] < y[b] || (y[a] == y[b] && x[a] < x[b]);
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++ i) {
    char c; scanf("%d%d %c", x + i, y + i, &c);
    id[i] = i;
    if (c == '<') d[i] = 0;
    if (c == '>') d[i] = 1;
    if (c == '^') d[i] = 2;
    if (c == 'v') d[i] = 3;
  }
  memset(nx, -1, sizeof(nx));
  sort(id, id + n, cmpx);
  for (int i = 1; i < n; ++ i) {
    if (x[id[i]] == x[id[i - 1]]) {
      nx[id[i]][2] = id[i - 1];
      nx[id[i - 1]][3] = id[i];
    }
  }
  sort(id, id + n, cmpy);
  for (int i = 1; i < n; ++ i) {
    if (y[id[i]] == y[id[i - 1]]) {
      nx[id[i]][0] = id[i - 1];
      nx[id[i - 1]][1] = id[i];
    }
  }
  memcpy(st, nx, sizeof(nx));
  int ret(0);
  for (int i = 0; i < n; ++ i) {
    memcpy(nx, st, sizeof(st));
    int now(i), cnt(0);
    for (; ~now; ++ cnt) {
      int d = ::d[now];
      for (int j = 0; j <4; ++ j) {
        if (nx[now][j] != -1) {
          nx[nx[now][j]][j ^ 1] = nx[now][j ^ 1];
        }
      }
      now = nx[now][d];
    }
    ret = max(ret, cnt);
  }
  printf("%d\n", ret);
  return 0;
}

