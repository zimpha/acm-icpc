#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <queue>

using namespace std;

#define INF 0x3f3f3f3f
#define NN 220
int dist[NN][NN];
int val[NN], valvst[NN];

int cost[NN][NN], cap[NN][NN];
int flow[NN][NN], mind[NN], vst[NN];
int prev[NN], minf[NN];

int minCostFlow(int N, int src, int tar) {
  int i, j, u, v;
  memset(flow, 0, sizeof(flow));
  queue<int> q;
  int res = 0;
  while (true) {
    memset(mind, 0x3f, sizeof(mind));
    memset(prev, -1, sizeof(prev));
    memset(vst, 0, sizeof(vst));
    mind[src] = 0; q = queue<int>();
    q.push(src); vst[src] = 1; minf[src] = INF;
    while (q.size() > 0) {
      u = q.front(); q.pop(); vst[u] = 0;
      for (v = 0; v < N; v++) {
        if (cap[u][v] == 0) continue;
        if (mind[v] > mind[u] + cost[u][v]) {
          mind[v] = mind[u] + cost[u][v];
          minf[v] = min(minf[u], cap[u][v]);
          prev[v] = u;
          if (vst[v] == 1) continue;
          q.push(v); vst[v] = 1; 
        }
      }
    }
    if (prev[tar] == -1) return res;
    res += mind[tar] * minf[tar];
    for (i = tar; i != src; i = prev[i]) {
      j = prev[i];
      cap[j][i] -= minf[tar];
      flow[j][i] += minf[tar];
      cap[i][j] += minf[tar];
      flow[i][j] -= minf[tar];
    }
  }
}
int main() {
  int T, N, M, x, y, i, j, k, Lw, Sw, Tw, u;
  int n; scanf("%d", &T);
  for (int cas = 1; cas <= T; ++ cas) {
    printf("Case %d: ", cas);
    scanf("%d%d%d%d", &N, &M, &Sw, &Tw);
    n = N + M;
    memset(dist, 0x3f, sizeof(dist));
    memset(cost, 0, sizeof(cost));
    memset(cap, 0, sizeof(cap));
    int add = 0;
    for (int x = 0; x < N; ++ x) {
      for (int y = 0; y < M; ++ y) {
        char s[100]; scanf("%s", s);
        if (s[0] == 'X') continue;
        int Lw; sscanf(s, "%d", &Lw);
        dist[y+N][x] = Lw - Sw;// L + P - Q >= S
        dist[x][y+N] = Tw - Lw;// L + P - Q <= T
        cap[n][x]++; cap[y+N][n+1]++;
        add += Lw;
      }
    }
    for (k = 0; k < n; k++) {
      for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
          if (dist[i][j] > dist[i][k] + dist[k][j])
            dist[i][j] = dist[i][k] + dist[k][j]; 
        }
      }
    }
    for (k = 0; k < n; k++) if (dist[k][k] < 0) break;
    if (k < n) {
      puts("Impossible");
      continue;
    }
    
    for (i = 0; i < N; i++) for (j = 0; j < M; j++) {
      cost[i][j+N] = dist[i][j+N];
      cost[j+N][i] = -dist[i][j+N];
      cap[i][j+N] = INF;
    }

    int res = minCostFlow(n+2, n, n+1);

    for (i = 0; i < N; i++) for (j = 0; j < M; j++) {
      if (flow[i][j+N]) dist[j+N][i] = -dist[i][j+N];
    }
    for (k = 0; k < n; k++) {
      for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
          if (dist[i][j] > dist[i][k] + dist[k][j])
            dist[i][j] = dist[i][k] + dist[k][j]; 
        }
      }
    }
    
    memset(valvst, 0, sizeof(valvst));
    for (i = 0; i < n; i++) if (!valvst[i]){
      val[i] = 0; valvst[i] = 1; 
      for (j = i + 1; j < n; j++) if (!valvst[j]) {
        if (dist[j][i] < -INF/2 || dist[j][i] > INF/2) continue;
        val[j] = dist[j][i]; valvst[j] = 1;
      }
    }
    int minval = 0;
    for (i = 0; i < n; i++) if (val[i] < minval) minval = val[i];
    for (i = 0; i < n; i++) val[i] -= minval;
    printf("%d\n", res + add);
    for (i = 0; i < N; i++) {
      if (i) printf(" ");
      printf("%d", val[i]);
    } puts("");
    for (i = N; i < n; i++) {
      if (i>N) printf(" ");
      printf("%d", val[i]);
    } puts("");
  }
}