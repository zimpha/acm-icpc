#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;

const int MAXN = 60 + 10, MAXK = 2000 + 10;

int mp[MAXN][MAXN], L[MAXK];
int vis[MAXK], N, K;
int is_border[MAXN][MAXN];
PII pos[MAXK];
set<PII> border;
priority_queue<PII, vector<PII>, greater<PII> > ds[MAXN][MAXN];

void calc(int x, int y) {
  for (int i = 0; i < K; ++ i) if (!vis[i]) {
    ds[x][y].push(PII(abs(x - pos[i].first) + abs(y - pos[i].second), i));
  }
}

void remove(int i) {
  vis[i] = 1;
}

bool ok(int x, int y) {
  return x >= 0 && x < N && y >=0 && y < N;
}

void expand(int x, int y) {
  const int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
  const int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};
  //int flag = 0;
  for (int i = 0; i < 4; ++ i) {
    int xx = x + dx[i], yy = y + dy[i];
    if (ok(xx, yy) && !is_border[xx][yy]) {
      border.insert(PII(xx, yy));
      is_border[xx][yy] = 1;
      calc(xx, yy);
      //flag ++;
    }
   // if (flag == 2) break;
  } 
}

int main() {
  srand(time(NULL));
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    memset(mp, 0, sizeof(mp));
    memset(is_border, 0, sizeof(is_border));
    scanf("%d%d", &N, &K);
    border.clear();
    int cx(0), cy(0);
    for (int i = 0; i < K; ++ i) vis[i] = 0;
    for (int i = 0; i < N; ++ i) {
      for (int j = 0; j < N; ++ j) {
        int x; scanf("%d", &x);
        if (x) {
          pos[x - 1] = PII(i, j);
          cx += i; cy += j;
        }
      }
    }
    for (int i = 0; i < K; ++ i) scanf("%d", L + i);
    //cx = pos[rand() % K].first, cy = pos[rand() % K].second;
      cx = cy = 0;
    border.insert(PII(cx, cy)); calc(cx, cy);
    is_border[cx][cy] = 1;
    for (int i = 0; i < K; ++ i) {
      PII ret(1e9, -1), bd;
      int cnt(0);
      for (auto &t: border) {
        priority_queue<PII, vector<PII>, greater<PII> > &s = ds[t.first][t.second];
        while (vis[s.top().second]) s.pop();
        PII nw = s.top(); ++ cnt;
        if (nw < ret) bd = t, ret = nw;
        //if (cnt > 50) break;
      }
      remove(ret.second);
      border.erase(bd);
      expand(bd.first, bd.second);
      mp[bd.first][bd.second] = ret.second + 1;
    }
    for (int i = 0; i < N; ++ i) {
      for (int j = 0; j < N; ++ j) {
        printf("%d%c", mp[i][j], " \n"[j == N - 1]);
      }
    }
  }
  return 0;
}