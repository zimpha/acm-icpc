#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define lson (rt<<1)
#define rson (rt<<1|1)
#define mid ((l+r)>>1)
const int MAXN = 500000 + 10;

int T[MAXN << 2];
int a[MAXN], n;

struct Node {
  int x, y, z;
  Node() {}
  Node(int _x, int _y, int _z): x(_x), y(_y), z(_z) {
    if (a[x] > a[y]) swap(x, y);
    if (a[x] > a[z]) swap(x, z);
    if (a[y] > a[z]) swap(y, z);
  }
  bool operator < (const Node &rhs) const {
    if (a[x] != a[rhs.x]) return a[x] < a[rhs.x];
    if (a[y] != a[rhs.y]) return a[y] < a[rhs.y];
    return a[z] < a[rhs.z];
  }
};

vector<Node> ret;

int take(int x, int y) {
  if (x > y) swap(x, y);
  if (x == -1) return y;
  else return a[x] <= a[y] ? x : y;
}

void build(int rt, int l, int r) {
  if (l + 1 == r) {T[rt] = l; return;}
  build(lson, l, mid); build(rson, mid, r);
  T[rt] = take(T[lson], T[rson]);
}

int ask(int rt, int l, int r, int L, int R) {
  if (L <= l && R >= r) return T[rt];
  int ret(-1);
  if (L < mid) ret = take(ret, ask(lson, l, mid, L, R));
  if (R > mid) ret = take(ret, ask(rson, mid, r, L, R));
  return ret;
}

void solve(int l, int r) {
  if (l > r) swap(l, r);
  if (r - l + 1 <= 2) return;
  vector<int> m;
  int best = a[ask(1, 0, n + 1, l + 1, r)];
  for (int i(l + 1), j; i < r; i = j + 1) {
    j = ask(1, 0, n + 1, i, r);
    assert(i <= j);
    if (a[j] == best) m.push_back(j);
    else break;
  }
  int last = l;
  for (auto &x: m) {
    solve(last, x);
    last = x;
  }
  solve(last, r);
  if (l == 0 && r == n) {
    last = -1;
    for (auto &x: m) {
      if (~last) ret.push_back(Node(0, last, x));
      last = x;
    }
  }
  else if (a[l] < a[r]) {
    m.push_back(r);
    for (size_t i = 1; i < m.size(); ++ i) {
      ret.push_back(Node(l, m[i], m[i - 1]));
    }
  }
  else {
    for (size_t i = 0; i < m.size(); ++ i) {
      if (i) ret.push_back(Node(m[i], m[i - 1], r));
      else ret.push_back(Node(l, r, m[i]));
    }
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++ i) scanf("%d", a + i);
  int rot = min_element(a, a + n) - a;
  rotate(a, a + rot, a + n); a[n] = a[0];
  build(1, 0, n + 1);
  int last(0);
  for (int i = 1; i < n; ++ i) if (a[i] == a[0]) {
    if (last) ret.push_back(Node(0, last, i));
    solve(last, i); last = i;
  }
  solve(last, n);
  sort(ret.begin(), ret.end());
  for (auto &p: ret) {
    p.x = (p.x + rot) % n;
    p.y = (p.y + rot) % n;
    p.z = (p.z + rot) % n;
    printf("%d %d %d\n", p.x + 1, p.y + 1, p.z + 1);
  }
  return 0;
}