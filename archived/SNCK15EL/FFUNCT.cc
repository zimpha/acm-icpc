#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int MAXN = 100000 + 10, MOD = 1e9 + 7;
const int K = 5, KK = 1 << K;

int lg[20], pw[MAXN], fun[MAXN];
int n, q;

struct Node {
  int t[1 << K];
  void clr() {memset(t, 0, sizeof(t));}
  Node operator + (const Node &rhs) const {
    Node x; x.clr();
    for (int i = 0; i < KK; ++ i) x.t[i] = t[i] + rhs.t[i];
    return x;
  }
  Node& operator += (const Node &rhs) {
    for (int i = 0; i < KK; ++ i) t[i] += rhs.t[i];
    return *this;
  }
} T[MAXN << 2];

void upd(Node &r, const Node &a, const Node &b) {
  for (int i = 0; i < KK; ++ i) {
    r.t[i] = a.t[i] + b.t[i];
  }
}

int mono(char *s) {
  int l = strlen(s), k = lg[l];
  for (int i = 0; i < l; ++ i) if (s[i] == '1') {
    for (int j = 0; j < k; ++ j) {
      if ((~i >> j & 1) && s[i ^ (1 << j)] == '0') return 0;
    }
  }
  return 1;
}

int affine(char *s) {
  int l = strlen(s), k = lg[l], ret(1);
  for (int i = 0; i < k; ++ i) {
    bool always(1), never(1);
    for (int j = 0; j < l; ++ j) {
      if (s[j] == s[j ^ 1 << i]) always = 0;
      else never = 0;
    }
    ret &= always | never;
  }
  return ret;
}

int dual(char *s) {
  int l = strlen(s), k = lg[l];
  for (int i = 0; i < l; ++ i) {
    if (s[i] == s[l - i - 1]) return 0;
  }
  return 1;
}

int truth(char *s) {
  return s[strlen(s) - 1] == '1';
}

int falsity(char *s) {
  return s[0] == '0';
}

int getFun(char *s) {
  return (mono(s) << 4) | (affine(s) << 3) | (dual(s) << 2) | (truth(s) << 1) | falsity(s);
}

#define lson (rt<<1)
#define rson (rt<<1|1)
#define mid ((l+r)>>1)

void build(int rt, int l, int r) {
  if (l + 1 == r) {
    T[rt].clr();
    T[rt].t[fun[l]] ++;
    return;
  }
  build(lson, l, mid);
  build(rson, mid, r);
  upd(T[rt], T[lson], T[rson]);
}

void modify(int rt, int l, int r, int p, char *s) {
  if (l + 1 == r) {
    T[rt].t[fun[l]] --;
    fun[l] = getFun(s);
    T[rt].t[fun[l]] ++;
    return;
  }
  if (p < mid) modify(lson, l, mid, p, s);
  else modify(rson, mid, r, p, s);
  upd(T[rt], T[lson], T[rson]);
}

Node ret;
void ask(int rt, int l, int r, int L, int R) {
  if (L <= l && R >= r) {ret += T[rt]; return;}
  if (L < mid) ask(lson, l, mid, L, R);
  if (R > mid) ask(rson, mid, r, L, R);
}

int main() {
  lg[1] = 0; lg[2] = 1; lg[4] = 2; lg[8] = 3; lg[16] = 4;
  pw[0] = 1;
  for (int i = 1; i < MAXN; ++ i) pw[i] = (LL)pw[i - 1] * 2 % MOD;
  scanf("%d", &n);
  for (int i = 0; i < n; ++ i) {
    char s[100]; scanf("%s", s);
    fun[i] = getFun(s);
  }
  build(1, 0, n);
  scanf("%d", &q);
  for (int _ = 0; _ < q; ++ _) {
    char op[2], s[100];
    scanf("%s", op);
    if (op[0] == 'u') {
      int p; scanf("%d%s", &p, s);
      modify(1, 0, n, p - 1, s);
    }
    else {
      int l, r; scanf("%d%d", &l, &r);
      ret.clr(); ask(1, 0, n, l - 1, r);
      for (int i = 0; i < K; ++ i) {
        for (int j = 0; j < KK; ++ j) {
          if (j >> i & 1) ret.t[j ^ (1 << i)] += ret.t[j];
        }
      }
      int ans(0);
      for (int i = 0; i < KK; ++ i) {
        ans += (__builtin_parity(i) ? -1 : 1) * pw[ret.t[i]];
        ans %= MOD;
      }
      if (ans < 0) ans += MOD;
      printf("%d\n", ans);
    }
  }
  return 0;
}