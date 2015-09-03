#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1 << 16, SZ = 200000 + 10;

int t[SZ], x[SZ];
int ret[MAXN];
int s1, s2, Q;

void solve1() {
  for (int i = 0; i < Q; ++ i) {
    if (t[i] == 'a') {
      ret[x[i]] ++;
    }
    else if (t[i] == 'd') {
      ret[x[i]] --;
    }
    else {
      int cnt(ret[0]), x = ::x[i];
      for (int s = x; s; s = (s - 1) & x) {
        cnt += ret[s];
      }
      printf("%d\n", cnt);
    }
  }
}

void solve2() {
  for (int i = 0; i < Q; ++ i) {
    if (t[i] == 'a') {
      int x = ::x[i];
      int t = ~x & (MAXN - 1);
      for (int s = t; s; s = (s - 1) & t) {
        ret[x ^ s] ++;
      }
      ret[x] ++;
    }
    else if (t[i] == 'd') {
      int x = ::x[i];
      int t = ~x & (MAXN - 1);
      for (int s = t; s; s = (s - 1) & t) {
        ret[x ^ s] --;
      }
      ret[x] --;
    }
    else {
      /*int cnt(ret[0]);
      for (int s = x; s; s = (s - 1) & x) {
        cnt += ret[s];
      }*/
      printf("%d\n", ret[x[i]]);
    }
  }
}

int main() {
  scanf("%d", &Q);
  for (int i = 0, x; i < Q; ++ i) {
    char op[10]; scanf("%s%d", op, &x);
    ::t[i] = op[0]; ::x[i] = x;
    int c(0);
    for (int i = 0; i < 16; ++ i) {
      if (x >> i & 1) ++ c;
    }
    s1 += 1 << c; s2 += 1 << (16 - c);
  }
  if (s1 < s2) solve1();
  else solve2();
  return 0;
}