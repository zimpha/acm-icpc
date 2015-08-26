#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 60, inf = 1e9;

char mp[MAXN][MAXN];
bool isroom[MAXN][MAXN];
int dis[MAXN][MAXN][MAXN][MAXN];
int H, W, K, S, T, Tc, Tm;

bool fit(int x, int y) {
  return x >= 0 && x < H && y >= 0 && y < W && mp[x][y] != '.';
}

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
void bfs(int sx, int sy, int dis[MAXN][MAXN]) {
  for (int i = 0; i < H; ++ i) {
    for (int j = 0; j < W; ++ j) {
      dis[i][j] = -1;
    }
  }
  if (mp[sx][sy] == '.') return;
  queue<PII> Q; Q.push(PII(sx, sy)); dis[sx][sy] = 0;
  while (!Q.empty()) {
    int x = Q.front().first, y = Q.front().second; Q.pop();
    for (int i = 0; i < 4; ++ i) {
      int xx = x + dx[i], yy = y + dy[i];
      if (fit(xx, yy) && dis[xx][yy] == -1) {
        dis[xx][yy] = dis[x][y] + Tm;
        Q.push(PII(xx, yy));
      }
    }
  }
}

bool checkroom(int x, int y) {
  if (mp[x][y] == '.') return false;
  int ret = 0;
  for (int i = 0; i < 4; ++ i) {
    int xx = x + dx[i], yy = y + dy[i];
    ret += fit(xx, yy) && mp[xx][yy] != '.';
  }
  return ret == 1;
}

int dp[1<<12][12][12];
int getdis(PII a, PII b) {return dis[a.x][a.y][b.x][b.y];}
void upd(int &x, int y) {if (x == -1 || x > y) x = y;}

struct Unit {
  vector<PII> room;
  int f[20][20], g[20][20][20], h[20];
  int n;
  //f[i][j]: room[i] in, room[j] out
  //g[i][j][k]: room[i] -> unit[j].room[k]
  Unit(): n(0) {
    memset(f, -1, sizeof(f));
    memset(h, -1, sizeof(h));
    memset(g, -1, sizeof(g));
  }
  void add(int x, int y) {room.push_back(PII(x,y));}
  int get(int i, int j) {return getdis(room[i], room[j]);}
  void build() {
    n = room.size(); int s = 1 << n;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; ++ i) dp[1 << i][i][i] = Tc;
    for (int msk = 0; msk < s; ++ msk) {
      for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < n; ++ j) if (dp[msk][i][j] != -1) {
          for (int k = 0; k < n; ++ k) if (~msk >> k & 1) {
            upd(dp[msk | 1 << k][i][k], dp[msk][i][j] + get(j, k) + Tc);
          }
        }
      }
    }
    for (int i = 0; i < n; ++ i) {
      for (int j = 0; j < n; ++ j) if (i != j) {
        assert(dp[s - 1][i][j] != -1);
        upd(f[i][j], dp[s - 1][i][j]);
        upd(f[i][i], dp[s - 1][i][j] + get(i, j));
      }
    }
    if (n == 1) f[0][0] = Tc;
    for (int i = 0; i < n; ++ i) {
      for (int j = 0; j < n; ++ j) {
        upd(h[j], f[i][j] + getdis(PII(S, T), room[i]));
      }
    }
  }
  void getG(int id, const Unit &u) {
    for (int i = 0; i < n; ++ i) {
      for (int j = 0; j < u.n; ++ j) {
        for (int k = 0; k < u.n; ++ k) {
          upd(g[i][id][k], getdis(room[i], u.room[j]) + u.f[j][k]);
        }
      }
    }
  }
};

vector<Unit> A;
map<char, int> unitID;
int cost[1 << 12], f[13][1 << 12];

int main() {
  scanf("%d%d%d%d%d", &H, &W, &K, &S, &T);
  scanf("%d%d", &Tm, &Tc); -- S; -- T;
  for (int i = 0; i < H; ++ i) scanf("%s", mp[i]);
  for (int i = 0; i < H; ++ i) {
    for (int j = 0; j < W; ++ j) {
      bfs(i, j, dis[i][j]);
      isroom[i][j] = checkroom(i, j);
    }
  }
  for (int i = 0; i < H; ++ i) {
    for (int j = 0; j < W; ++ j) {
      if (isroom[i][j]) {
        if (!unitID.count(mp[i][j])) {
          unitID[mp[i][j]] = A.size();
          A.push_back(Unit());
        }
        A[unitID[mp[i][j]]].add(i, j);
      }
    }
  }
  int n = A.size(), s = 1 << n;
  for (int i = 0; i < n; ++ i) A[i].build();
  for (int i = 0; i < n; ++ i) {
    for (int j = 0; j < n; ++ j) {
      if (i != j) A[i].getG(j, A[j]);
    }
  }
  memset(dp, -1, sizeof(dp));
  for (int i = 0; i < n; ++ i) {
    for (int j = 0; j < A[i].n; ++ j) {
      dp[1 << i][i][j] = A[i].h[j];
    }
  }
  memset(cost, -1, sizeof(cost));
  for (int msk = 0; msk < s; ++ msk) {
    for (int i = 0; i < n; ++ i) {
      for (int j = 0; j < A[i].n; ++ j) if (dp[msk][i][j] != -1) {
        upd(cost[msk], dp[msk][i][j] + getdis(PII(S, T), A[i].room[j]));
        for (int k = 0; k < n; ++ k) if (~msk >> k & 1) {
          for (int l = 0; l < A[k].n; ++ l) {
            upd(dp[msk | (1 << k)][k][l], dp[msk][i][j] + A[i].g[j][k][l]);
          }
        }
      }
    }
  }
  memset(f, 1, sizeof(f)); f[0][0] = 0;
  for (int i = 0; i < K; ++ i) {
    for (int msk = 0; msk < s; ++ msk) {
      int T = (s - 1) ^ msk, sub = T;
      do {
        f[i + 1][msk | sub] = min(f[i + 1][msk | sub], max(f[i][msk], cost[sub]));
        sub = (sub - 1) & T;
      } while (sub != T);
    }
  }
  printf("%d\n", f[K][s - 1]);
  return 0;
}