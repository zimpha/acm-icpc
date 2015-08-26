#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long LL;
typedef pair<int, int> PII;
const int MAXN = 2000 + 10, SIZE = 1024;
LL A[MAXN];
int N, M, Q;

char s[MAXN], t[MAXN];

char change(int x) {
  if (x < 10) return x + '0';
  else return 'A' + x - 10;
}

int main() {
  while (scanf("%d%d%d", &N, &M, &Q) == 3 && N) {
    for (int i = 0; i < M; ++ i) A[i] = LL(1ll << N) - 1;
    LL sw = 0;
    for (int _ = 0; _ < Q; ++ _) {
      scanf("%s%s", s, t);
      for (int i = 0; i < N; ++ i) sw ^= LL(s[i] - '0') << i;
      for (int i = 0; i < M; ++ i) {
        A[i] &= t[i] == '1' ? sw : ~sw;
      }
    }
    for (int i = 0; i < M; ++ i) s[i] = '?'; s[M] = 0;
    for (int i = 0; i < M; ++ i) {
      if (__builtin_popcountll(A[i]) != 1) continue;
      int x = __builtin_ctzll(A[i]);
      s[i] = change(x);
    }
    puts(s);
  }
  return 0;
}