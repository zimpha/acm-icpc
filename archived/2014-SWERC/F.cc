#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

struct Event {
  int p, l, r, id;
  Event() {}
  Event(int _p, int _l, int _r, int _id):
    p(_p), l(_l), r(_r), id(_id) {}
  bool operator < (const Event &rhs) const {
    return p < rhs.p;
  }
};

vector<Event> ev;

const int MAXN = 50000 + 10;
int dsu[MAXN], sz[MAXN], n;
int X[MAXN], Y[MAXN];
int W[MAXN], H[MAXN];

int get(int x) {
  if (x != dsu[x]) dsu[x] = get(dsu[x]);
  return dsu[x];
}

void merge(int x, int y) {
  x = get(x); y = get(y);
  if (x != y) sz[y] += sz[x], dsu[x] = y;
}

bool cmp(const Event &a, const Event &b) {
  return a.l < b.l;
}

void solve(vector<Event> &ev) {
  sort(ev.begin(), ev.end());
  for (size_t i = 0, j; i < ev.size(); i = j) {
    vector<Event> A, B;
    for (j = i; j < ev.size() && ev[j].p == ev[i].p; ++ j) {
      if (ev[j].id > 0) A.push_back(ev[j]);
      else B.push_back(ev[j]);
    }
    for (auto &e: B) e.id = -e.id;
    sort(A.begin(), A.end(), cmp);
    sort(B.begin(), B.end(), cmp);
    for (size_t x(0), y(0); x < A.size() && y < B.size(); ) {
      if (A[x].l == B[y].l) {
        merge(A[x].id, B[y].id);
        if (A[x].r <= B[y].r) ++ x;
        if (A[x].r >= B[y].r) ++ y;
      }
      else if (A[x].l < B[y].l) {
        if (A[x].r < B[y].l) ++ x;
        else {
          merge(A[x].id, B[y].id);
          if (A[x].r <= B[y].r) ++ x;
          else ++ y;
        }
      }
      else {
        if (B[y].r < A[x].l) ++ y;
        else {
          merge(A[x].id, B[y].id);
          if (B[y].r <= A[x].r) ++ y;
          else ++ x;
        }
      }
    }
  }
}

int main() {
  while (scanf("%d", &n) == 1) {
    for (int i = 1; i <= n; ++ i) {
      scanf("%d%d%d%d", X + i, Y + i, W + i, H + i);
      dsu[i] = i; sz[i] = W[i] * H[i];
    }
    ev.clear();
    for (int i = 1; i <= n; ++ i) {
      ev.push_back(Event(X[i], Y[i], Y[i] + H[i], i));
      ev.push_back(Event(X[i] + W[i], Y[i], Y[i] + H[i], -i));
    }
    solve(ev);
    ev.clear();
    for (int i = 1; i <= n; ++ i) {
      ev.push_back(Event(Y[i], X[i], X[i] + W[i], i));
      ev.push_back(Event(Y[i] + H[i], X[i], X[i] + W[i], -i));
    }
    solve(ev);
    int ret(0);
    for (int i = 1; i <= n; ++ i) {
      if (get(i) == i) ret = max(ret, sz[i]);
    }
    printf("%d\n", ret);
  }
  return 0;
}

