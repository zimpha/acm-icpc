#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

// (st, len), (-1, -1) means not find
PII getVer(int sx, int sy, int w, int x, int y1, int y2) {
  PII ret(-1, -1);
  if (x < sx || x > sx + w) return PII(-1, -1);
  if (y1 < y2) {
    if (y2 < sy || y1 > sy + w) return PII(-1, -1);
    ret.first = max(0, sy - y1);
    ret.second = min(y2, sy + w) - max(sy, y1);
  }
  else {
    if (y1 < sy || y2 > sy + w) return PII(-1, -1);
    ret.first = max(0, y1 - (sy + w));
    ret.second = min(y1, sy + w) - max(y2, sy);
  }
  return ret;
}

PII getHor(int sx, int sy, int w, int y, int x1, int x2) {
  PII ret(-1, -1);
  if (y < sy || y > sy + w) return PII(-1, -1);
  if (x1 < x2) {
    if (x2 < sx || x1 > sx + w) return PII(-1, -1);
    ret.first = max(0, sx - x1);
    ret.second = min(x2, sx + w) - max(sx, x1);
  }
  else {
    if (x1 < sx || x2 > sx + w) return PII(-1, -1);
    ret.first = max(0, x1 - (sx + w));
    ret.second = min(x1, sx + w) - max(x2, sx);
  }
  return ret;
}

const int MAXN = 1000 + 10;
int sx[MAXN], sy[MAXN], w[MAXN];
int x[MAXN], y[MAXN];
int n, m;

int main() {
  while (scanf("%d%d", &n, &m) == 2 && (n + m)) {
    for (int i = 0; i < n; ++ i) scanf("%d%d%d", sx + i, sy + i, w + i);
    for (int i = 0; i < m; ++ i) scanf("%d%d", x + i, y + i);
    vector<PII> seg;
    for (int i = 0; i < n; ++ i) {
      int s(0);
      int l(-1), r(-1);
      for (int j = 0; j + 1 < m; ++ j) {
        PII rt;
        if (x[j] == x[j + 1]) {
          rt = getVer(sx[i], sy[i], w[i], x[j], y[j], y[j + 1]);
        }
        else {
          rt = getHor(sx[i], sy[i], w[i], y[j], x[j], x[j + 1]);
        }
        if (rt.first != -1) {
          if (l == -1) l = s + rt.first, r = l + rt.second;
          else if (r == s + rt.first) r = s + rt.first + rt.second;
          else {
            //cout << i << ": " << l << " " << r << endl;
            seg.push_back(PII(l, r)); l = r = -1;
          }
        }
        else if (l != -1) {
          //cout << i << ": " << l << " " << r << endl;
          seg.push_back(PII(l, r)); l = r = -1;
        }
        s += abs(x[j] - x[j + 1]) + abs(y[j] - y[j + 1]);
      }
      if (l != -1) {
        seg.push_back(PII(l, r));
        //cout << i << ": " << l << " " << r << endl;
      }
    }
    sort(seg.begin(), seg.end());
    int ret(0), r(0);
    for (size_t i = 0, j; i < seg.size(); i = j) {
      int lim = max(r, seg[i].first);
      for (j = i + 1; j < seg.size() && seg[j].first <= lim; ++ j) {
        if (seg[j].second > seg[i].second) i = j;
      }
      if (seg[i].second > r) {
        ++ ret; r = seg[i].second;
      }
    }
    printf("%d\n", ret);
  }
  return 0;
}

