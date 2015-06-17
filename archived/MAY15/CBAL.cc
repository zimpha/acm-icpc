#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 100000 + 10, MAXL = 500 + 10;

map<int, int> mp;
char s[MAXN];
int A[MAXN], pt[MAXN], N, M, Q, B, P;
struct Node {
  vector<int> v;
  vector<LL> s1, s2;
  void clr() {v.clear();}
  int add(int x) {
    v.push_back(x);
    return v.size() - 1;
  }
  void build() {
    s1.assign(v.size() + 1, 0); s2.assign(v.size() + 1, 0);
    for (int i = v.size() - 1; i >= 0; -- i) {
      s1[i] = s1[i + 1] + v[i];
      s2[i] = s2[i + 1] + (LL)v[i] * v[i];
    }
  }
  LL ask0(int i, int l, int r) {
    return r - l;
  }
  LL ask1(int i, int l, int r) {
    return s1[l] - s1[r] - (LL)v[i] * (r - l);
  }
  LL ask2(int i, int l, int r) {
    return s2[l] - s2[r] + ((LL)v[i] * (r - l) - ((s1[l] - s1[r]) << 1ll)) * v[i];
  }
  int low(int x) {
    return lower_bound(v.begin(), v.end(), x) - v.begin();
  }
  int upp(int x) {
    return upper_bound(v.begin(), v.end(), x) - v.begin();
  }
} ST[MAXN];

LL sum[MAXL][MAXL][3];

void precalc() {
  for (int i = 0; i <= B; ++ i) {
    for (int j = 0; j <= B; ++ j) {
      sum[i][j][0] = sum[i][j][1] = sum[i][j][2] = 0;
    }
  }
  static LL s[MAXN][3];
  for (int i = 0; i < B; ++ i) {
    for (int x = 0; x < M; ++ x) s[x][0] = s[x][1] = s[x][2] = 0;
    for (int j = i; j >= 0; -- j) {
      int l = j * P, r = min(l + P, N) - 1;
      sum[j][i][0] = sum[j + 1][i][0];
      sum[j][i][1] = sum[j + 1][i][1];
      sum[j][i][2] = sum[j + 1][i][2];
      for (int k = r; k >= l; -- k) {
        sum[j][i][0] += s[A[k]][0];
        sum[j][i][1] += s[A[k]][1] - s[A[k]][0] * k;
        sum[j][i][2] += s[A[k]][2] + s[A[k]][0] * k * k - s[A[k]][1] * k * 2;
        s[A[k]][0] ++; s[A[k]][1] += k; s[A[k]][2] += (LL)k * k;
      }
    }
  }
}

LL solve0(int L, int R) {
  int pl = L / P, pr = R / P;
  LL ret = 0;
  if (pl == pr) {
    for (int i = L; i < R; ++ i) {
      int x = pt[i], y = x + 1, z = ST[A[i]].upp(R);
      ret += ST[A[i]].ask0(x, y, z);
    }
  }
  else {
    ret = sum[pl + 1][pr - 1][0];
    int lim = pl * P + P;
    for (int i = L; i < lim; ++ i) {
      int x = pt[i], y = x + 1, z = ST[A[i]].upp(R);
      ret += ST[A[i]].ask0(x, y, z);
    }
    for (int i = pr * P; i <= R; ++ i) {
      int x = pt[i], y = ST[A[i]].low(lim), z = x;
      ret += ST[A[i]].ask0(x, y, z);
    }
  }
  return ret;
}

LL solve1(int L, int R) {
  int pl = L / P, pr = R / P;
  LL ret = 0;
  if (pl == pr) {
    for (int i = L; i < R; ++ i) {
      int x = pt[i], y = x + 1, z = ST[A[i]].upp(R);
      ret += ST[A[i]].ask1(x, y, z);
    }
  }
  else {
    ret = sum[pl + 1][pr - 1][1];
    int lim = pl * P + P;
    for (int i = L; i < lim; ++ i) {
      int x = pt[i], y = x + 1, z = ST[A[i]].upp(R);
      ret += ST[A[i]].ask1(x, y, z);
    }
    for (int i = pr * P; i <= R; ++ i) {
      int x = pt[i], y = ST[A[i]].low(lim), z = x;
      ret -= ST[A[i]].ask1(x, y, z);
    }
  }
  return ret;
}

LL solve2(int L, int R) {
  int pl = L / P, pr = R / P;
  LL ret = 0;
  if (pl == pr) {
    for (int i = L; i < R; ++ i) {
      int x = pt[i], y = x + 1, z = ST[A[i]].upp(R);
      ret += ST[A[i]].ask2(x, y, z);
    }
  }
  else {
    ret = sum[pl + 1][pr - 1][2];
    int lim = pl * P + P;
    for (int i = L; i < lim; ++ i) {
      int x = pt[i], y = x + 1, z = ST[A[i]].upp(R);
      ret += ST[A[i]].ask2(x, y, z);
    }
    for (int i = pr * P; i <= R; ++ i) {
      int x = pt[i], y = ST[A[i]].low(lim), z = x;
      ret += ST[A[i]].ask2(x, y, z);
    }
  }
  return ret;
}

struct FastIO {
  static const int S = 131072;
  int wpos; char wbuf[S];
  FastIO() : wpos(0) {}
  inline int xchar() {
    static char buf[S];
    static int len = 0, pos = 0;
    if (pos == len)
      pos = 0, len = fread(buf, 1, S, stdin);
    if (pos == len) return -1;
    return buf[pos ++];
  }
  inline int xint() {
    int c = xchar(), x = 0;
    while (c <= 32) c = xchar();
    for (;'0' <= c && c <= '9'; c = xchar()) x = x * 10 + c - '0';
    return x;
  }
  inline void xstring(char *s) { 
    int c = xchar();
    while (c <= 32) c = xchar();
    for(; c > 32; c = xchar()) *s++ = c;
    *s = 0;
  }
  inline void wchar(int x) {
    if (wpos == S) fwrite(wbuf, 1, S, stdout), wpos = 0;
    wbuf[wpos ++] = x;
  }
  inline void wint(int x) {
    if (x < 0) wchar('-'), x = -x;

    char s[24];
    int n = 0;
    while (x || !n) s[n ++] = '0' + x % 10, x /= 10;
    while (n--) wchar(s[n]);
  }
  inline void wll(LL x) {
    static char s[30];
    int n = 0;
    while (x || !n) s[n ++] = '0' + x % 10, x /= 10;
    while (n--) wchar(s[n]);
  }
  inline void wstring(const char *s) {
    while (*s) wchar(*s++);
  }
  ~FastIO() {
    if (wpos) fwrite(wbuf, 1, wpos, stdout), wpos = 0;
  }
} io;

int main() {
  int T = io.xint(); 
  for (int _ = 0; _ < T; ++ _) {
    io.xstring(s + 1); Q = io.xint();
    N = strlen(s + 1) + 1;
    P = 200; mp.clear();
    B = N / P + (N % P != 0);
    A[0] = 0; mp[0] = 0;
    for (int i = 1; i < N; ++ i) {
      int o = s[i] - 'a';
      A[i] = A[i - 1] ^ (1 << o);
      mp[A[i]] = 0;
    }
    M = 0;
    for (auto &x: mp) x.second = M ++;
    for (int i = 0; i < M; ++ i) ST[i].clr();
    for (int i = 0;  i < N; ++ i) {
      A[i] = mp[A[i]];
      pt[i] = ST[A[i]].add(i);
    }
    for (int i = 0; i < M; ++ i) ST[i].build();
    precalc();
    LL A = 0, B = 0;
    while (Q --) {
      int X = io.xint(), Y = io.xint(), ty = io.xint();
      int L = (X + A) % (N - 1) + 1;
      int R = (Y + B) % (N - 1) + 1;
      if (L > R) swap(L, R); -- L;
      A = B;
      if (ty == 0) B = solve0(L, R);
      else if (ty == 1) B = solve1(L, R);
      else B = solve2(L, R);
      io.wll(B); io.wchar('\n');
    }
  }
  return 0;
} 
