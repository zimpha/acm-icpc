#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
typedef pair<PII, PII> PPP;
const int MAXN = 100 + 10, SZ = 1000 + 10;
int A[MAXN][MAXN], mp[MAXN][MAXN];
vector<PII> C[SZ];
int N, M;

int ex[MAXN][MAXN], cov[MAXN];
inline int dis(const PII &a, const PII &b) {
  return abs(a.first - b.first) + abs(a.second - b.second);
}

bool cmp_upper_left(const PII &a, const PII &b) {
  return dis(a, PII(1, 1)) < dis(b, PII(1, 1));
}
vector<PPP> upper_left(int mp[][MAXN], int n, int m) {
  for (int i = 1; i <= m; ++ i) cov[i] = ex[n + 1][i] = 0;
  for (int i = n; i >= 1; -- i) {
    for (int j = 1; j <= m; ++ j) {
      if (mp[i][j]) ex[i][j] = ex[i + 1][j] + 1;
      else ex[i][j] = 0;
    }
  }
  vector<PPP> ret;
  for (int i = 1; i <= n; ++ i) {
    for (int j = 1; j <= m; ++ j) cov[j] --;
    for (int j = 1; j <= m; ++ j) if (cov[j] <= 0 && mp[i][j]) {
      int l = ex[i][j], w = 1, mx = ex[i][j];
      for (int k = j + 1; k <= m && mp[i][k]; ++ k) {
        mx = min(mx, ex[i][k]);
        if (mx * (k - j + 1) > l * w) l = mx, w = k - j + 1;
      }
      ret.push_back(PPP(PII(i, j), PII(i + l - 1, j + w - 1)));
      for (int k = 0; k < w; ++ k) cov[j + k] = max(cov[j + k], l);
    }
  }
  return ret;
}

bool cmp_lower_left(const PII &a, const PII &b) {
  return dis(a, PII(N, 1)) < dis(b, PII(N, 1));
}
vector<PPP> lower_left(int mp[][MAXN], int n, int m) {
  for (int i = 1; i <= m; ++ i) cov[i] = ex[0][i] = 0;
  for (int i = 1; i <= n; ++ i) {
    for (int j = 1; j <= m; ++ j) {
      if (mp[i][j]) ex[i][j] = ex[i - 1][j] + 1;
      else ex[i][j] = 0;
    }
  }
  vector<PPP> ret;
  for (int i = n; i >= 1; -- i) {
    for (int j = 1; j <= m; ++ j) cov[j] --;
    for (int j = 1; j <= m; ++ j) if (cov[j] <= 0 && mp[i][j]) {
      int l = ex[i][j], w = 1, mx = ex[i][j];
      for (int k = j + 1; k <= m && mp[i][k]; ++ k) {
        mx = min(mx, ex[i][k]);
        if (mx * (k - j + 1) > l * w) l = mx, w = k - j + 1;
      }
      ret.push_back(PPP(PII(i - l + 1, j), PII(i, j + w - 1)));
      for (int k = 0; k < w; ++ k) cov[j + k] = max(cov[j + k], l);
    }
  }
  return ret;
}

bool cmp_upper_right(const PII &a, const PII &b) {
  return dis(a, PII(1, M)) < dis(b, PII(1, M));
}
vector<PPP> upper_right(int mp[][MAXN], int n, int m) {
  for (int i = 1; i <= m; ++ i) cov[i] = ex[n + 1][i] = 0;
  for (int i = n; i >= 1; -- i) {
    for (int j = 1; j <= m; ++ j) {
      if (mp[i][j]) ex[i][j] = ex[i + 1][j] + 1;
      else ex[i][j] = 0;
    }
  }
  vector<PPP> ret;
  for (int i = 1; i <= n; ++ i) {
    for (int j = 1; j <= m; ++ j) cov[j] --;
    for (int j = m; j >= 1; -- j) if (cov[j] <= 0 && mp[i][j]) {
      int l = ex[i][j], w = 1, mx = ex[i][j];
      for (int k = j - 1; k >= 1 && mp[i][k]; -- k) {
        mx = min(mx, ex[i][k]);
        if (mx * (j - k + 1) > l * w) l = mx, w = j - k + 1;
      }
      ret.push_back(PPP(PII(i, j - w + 1), PII(i + l - 1, j)));
      for (int k = 0; k < w; ++ k) cov[j - k] = max(cov[j - k], l);
    }
  }
  return ret;
}

bool cmp_lower_right(const PII &a, const PII &b) {
  return dis(a, PII(N, M)) < dis(b, PII(N, M));
}
vector<PPP> lower_right(int mp[][MAXN], int n, int m) {
  for (int j = 1; j <= m; ++ j) cov[j] = ex[0][j] = 0;
  for (int i = 1; i <= n; ++ i) {
    for (int j = 1; j <= m; ++ j) {
      if (mp[i][j]) ex[i][j] = ex[i - 1][j] + 1;
      else ex[i][j] = 0;
    }
  }
  vector<PPP> ret;
  for (int i = n; i >= 1; -- i) {
    for (int j = 1; j <= m; ++ j) cov[j] --;
    for (int j = m; j >= 1; -- j) if (cov[j] <= 0 && mp[i][j]) {
      int l = ex[i][j], w = 1, mx = l;
      for (int k = j - 1; k >= 1 && mp[i][k]; -- k) {
        mx = min(mx, ex[i][k]);
        if (mx * (j - k + 1) > l * w) l = mx, w = j - k + 1;
      }
      ret.push_back(PPP(PII(i - l + 1, j - w + 1), PII(i, j)));
      for (int k = 0; k < w; ++ k) cov[j - k] = max(cov[j - k], l);
    }
  }
  return ret;
}

vector<PPP> solve1() {
  for (int i = 1; i <= N; ++ i) {
    for (int j = 1; j <= M; ++ j) {
      mp[i][j] = 0;
    }
  }
  for (int i = 0; i < SZ; ++ i) {
    sort(C[i].begin(), C[i].end());
    for (size_t j = 0; j < C[i].size() / 2; ++ j) {
      mp[C[i][j].first][C[i][j].second] = 1;
    }
  }
  vector<PPP> ret = upper_right(mp, N, M), tmp = upper_left(mp, N, M);
  if (tmp.size() < ret.size()) ret = tmp;
  //tmp = lower_right(mp, N, M); if (tmp.size() < ret.size()) ret = tmp;
  //tmp = lower_left(mp, N, M); if (tmp.size() < ret.size()) ret = tmp;
  return ret;
}

vector<PPP> solve2() {
  for (int i = 1; i <= N; ++ i) {
    for (int j = 1; j <= M; ++ j) {
      mp[i][j] = 0;
    }
  }
  for (int i = 0; i < SZ; ++ i) {
    sort(C[i].begin(), C[i].end());
    for (size_t j = 0; j < C[i].size() / 2; ++ j) {
      mp[C[i][j].first][C[i][j].second] = 1;
    }
  }
  vector<PPP> ret = upper_right(mp, N, M), tmp = upper_left(mp, N, M);
  if (tmp.size() < ret.size()) ret = tmp;
  //tmp = lower_right(mp, N, M); if (tmp.size() < ret.size()) ret = tmp;
  //tmp = lower_left(mp, N, M); if (tmp.size() < ret.size()) ret = tmp;
  return ret;
}

vector<PPP> solve3() {
  for (int i = 1; i <= N; ++ i) {
    for (int j = 1; j <= M; ++ j) {
      mp[i][j] = 0;
    }
  }
  for (int i = 0; i < SZ; ++ i) {
    sort(C[i].begin(), C[i].end());
    for (size_t j = 0; j < C[i].size() / 2; ++ j) {
      mp[C[i][j].first][C[i][j].second] = 1;
    }
  }
  vector<PPP> ret = upper_right(mp, N, M), tmp = upper_left(mp, N, M);
  if (tmp.size() < ret.size()) ret = tmp;
  //tmp = lower_right(mp, N, M); if (tmp.size() < ret.size()) ret = tmp;
  //tmp = lower_left(mp, N, M); if (tmp.size() < ret.size()) ret = tmp;
  return ret;
}

vector<PPP> solve4() {
  for (int i = 1; i <= N; ++ i) {
    for (int j = 1; j <= M; ++ j) {
      mp[i][j] = 0;
    }
  }
  for (int i = 0; i < SZ; ++ i) {
    sort(C[i].begin(), C[i].end());
    for (size_t j = 0; j < C[i].size() / 2; ++ j) {
      mp[C[i][j].first][C[i][j].second] = 1;
    }
  }
  vector<PPP> ret = upper_right(mp, N, M), tmp = upper_left(mp, N, M);
  if (tmp.size() < ret.size()) ret = tmp;
  //tmp = lower_right(mp, N, M); if (tmp.size() < ret.size()) ret = tmp;
  //tmp = lower_left(mp, N, M); if (tmp.size() < ret.size()) ret = tmp;
  return ret;
}

bool cmp5(const PII &a, const PII &b) {
  return dis(a, PII(50, 50)) < dis(b, PII(50, 50));
}
vector<PPP> solve5() {
  for (int i = 1; i <= N; ++ i) {
    for (int j = 1; j <= M; ++ j) {
      mp[i][j] = 0;
    }
  }
  for (int i = 0; i < SZ; ++ i) {
    sort(C[i].begin(), C[i].end());
    for (size_t j = 0; j < C[i].size() / 2; ++ j) {
      mp[C[i][j].first][C[i][j].second] = 1;
    }
  }
  vector<PPP> ret = upper_right(mp, N, M), tmp = upper_left(mp, N, M);
  if (tmp.size() < ret.size()) ret = tmp;
  //tmp = lower_right(mp, N, M); if (tmp.size() < ret.size()) ret = tmp;
  //tmp = lower_left(mp, N, M); if (tmp.size() < ret.size()) ret = tmp;
  return ret;
}

vector<PPP> solve6() {
  for (int i = 1; i <= N; ++ i) {
    for (int j = 1; j <= M; ++ j) {
      mp[i][j] = 0;
    }
  }
  for (int i = 0; i < SZ; ++ i) {
    sort(C[i].begin(), C[i].end());
    for (size_t j = 0; j < C[i].size() / 2; ++ j) {
      mp[C[i][j].first][C[i][j].second] = 1;
    }
  }
  vector<PPP> ret = upper_right(mp, N, M), tmp = upper_left(mp, N, M);
  if (tmp.size() < ret.size()) ret = tmp;
  //tmp = lower_right(mp, N, M); if (tmp.size() < ret.size()) ret = tmp;
  //tmp = lower_left(mp, N, M); if (tmp.size() < ret.size()) ret = tmp;
  //return upper_left(mp, N, M);
  return ret;
}

bool cmp7(const PII &a, const PII &b) {
  if (a.second == b.second) return a.second < b.second;
  else return a.first < b.first;
}
vector<PPP> solve7() {
  for (int i = 1; i <= N; ++ i) {
    for (int j = 1; j <= M; ++ j) {
      mp[i][j] = 0;
    }
  }
  for (int i = 0; i < SZ; ++ i) {
    sort(C[i].begin(), C[i].end(), cmp7);
    for (size_t j = 0; j < C[i].size() / 2; ++ j) {
      mp[C[i][j].first][C[i][j].second] = 1;
    }
  }
  vector<PPP> ret = upper_right(mp, N, M), tmp = upper_left(mp, N, M);
  if (tmp.size() < ret.size()) ret = tmp;
  //tmp = lower_right(mp, N, M); if (tmp.size() < ret.size()) ret = tmp;
  //tmp = lower_left(mp, N, M); if (tmp.size() < ret.size()) ret = tmp;
  //return upper_left(mp, N, M);
  return ret;
}

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    for (int i = 0; i < SZ; ++ i) C[i].clear();
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; ++ i) {
      for (int j = 1; j <= M; ++ j) {
        scanf("%d", &A[i][j]); mp[i][j] = 0;
        C[A[i][j]].push_back(PII(i, j));
      }
    }
    vector<PPP> ret(N * M), tmp;

    tmp = solve1();
    if (tmp.size() < ret.size()) ret = tmp;
    tmp = solve2();
    if (tmp.size() < ret.size()) ret = tmp;
    tmp = solve3();
    if (tmp.size() < ret.size()) ret = tmp;
    tmp = solve4();
    if (tmp.size() < ret.size()) ret = tmp;
    tmp = solve5();
    if (tmp.size() < ret.size()) ret = tmp;
    tmp = solve6();
    if (tmp.size() < ret.size()) ret = tmp;
    tmp = solve7();
    if (tmp.size() < ret.size()) ret = tmp;
    

    printf("%d\n", (int)ret.size());
    for (auto &t: ret) {
      PII a = t.first, b = t.second;
      printf("%d %d %d %d\n", a.first, a.second, b.first, b.second);
    }
  }
  return 0;
}
