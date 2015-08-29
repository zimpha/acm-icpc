#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int main() {
  int T; scanf("%d", &T);
  for (int cas = 1; cas <= T; ++ cas) {
    int M; scanf("%d", &M);
    vector<int> Rx(M), Ry(M);
    for (int i = 0; i < M; ++ i) {
      scanf("%d%d", &Rx[i], &Ry[i]);
    }
    printf("Case %d:\n", cas);
    int N; scanf("%d", &N);
    for (int _ = 0; _ < N; ++ _) {
      int X, Y; scanf("%d%d", &X, &Y);
      int W(20000), H(20000), K;
      for (int i = 0; i < M; ++ i) {
        swap(Rx[i], Ry[i]);
        int tk = 1, tw, th, c;
        for (c = 1; ; ++ c) {
          if (c * Rx[i] >= X && c * Ry[i] >= Y) break;
        }
        tk += (c * Rx[i] != X || c * Ry[i] != Y);
        th = c * Rx[i], tw = c * Ry[i];
        if (tw * th < W * H) W = tw, H = th, K = tk;
        else if (tw * th == W * H) {
          if (tw < W) W = tw, H = th, K = tk;
          else if (tw == W && tk < K) K = tk;
        }
        swap(Rx[i], Ry[i]);
        for (c = 1; ; ++ c) {
          if (c * Rx[i] >= X && c * Ry[i] >= Y) break;
        }
        tw = c * Rx[i], th = c * Ry[i];
        tk = (tw != X || th != Y);
        if (tw * th < W * H) W = tw, H = th, K = tk;
        else if (tw * th == W * H) {
          if (tw < W) W = tw, H = th, K = tk;
          else if (tw == W && tk < K) K = tk;
        }
      }
      printf("%d %d %d\n", W, H, K);
    }
  }
  return 0;
}

