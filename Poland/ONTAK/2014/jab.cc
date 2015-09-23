#include <bits/stdc++.h>
using namespace std;
const int MAXN = 800 + 10, MAXM = 100000 + 10, inf = 1e9;
typedef pair<int, int> PII;
struct Edge {
    int x, y, w, nx;
    Edge() {}
    Edge(int a, int b, int c, int d) :
        x(a), y(b), w(c), nx(d) {}
} E[MAXM];

int dis[MAXN][MAXN], w, s;
int G[MAXN][MAXN], sz, k;
bool vis[MAXN][MAXN];
PII Q[MAXM];

void link(int a, int b, int x, int y, int d) {
    if (x < 0 || x > s || y < 0 || y > w) return;
    E[sz] = Edge(x, y, d, G[a][b]); G[a][b] = sz ++;
}

inline PII getH(int &h) {
    PII ret = Q[h];
    h = (h + 1) % MAXM;
    return ret;
}

inline PII getT(int &t) {
    t = (t - 1 + MAXM) % MAXM;
    return Q[t];
}

inline void addT(const PII &now, int &t) {
    Q[t] = now; t = (t + 1) % MAXM;
}

int main() {
    //srand(time(NULL));
    scanf("%d%d%d", &w, &s, &k); sz = 0;
    for (int i = 1; i <= s; ++ i) {
        for (int j = 1; j <= w; ++ j) {
            G[i][j] = -1;
            dis[i][j] = inf;
        }
    }
    while (k --) {
        int a, b, d, x, y; char s[10];
        scanf("%d%d%s%d", &a, &b, s, &d);
        x = a; y = b;
        if (s[0] == 'E') ++ x;
        if (s[0] == 'W') -- x;
        if (s[0] == 'N') ++ y;
        if (s[0] == 'S') -- y;
        link(a, b, x, y, d);
    }
    if (rand() % 2) {
        dis[1][1] = 0; vis[1][1] = true;
        Q[0] = PII(1, 1);
        for (int h = 0, t = 1; h != t; ) {
            PII now;
            if (rand() % 10) now = getT(t);
            else now = getH(h);
            int a = now.first, b = now.second;
            vis[a][b] = false;
            for (int it = G[a][b]; ~it; it = E[it].nx) {
                int x = E[it].x, y = E[it].y, w = E[it].w;
                if (dis[x][y] > dis[a][b] + w) {
                    dis[x][y] = dis[a][b] + w;
                    if (!vis[x][y]) vis[x][y] = true, addT(PII(x, y), t);
                }
            }
        }
    }
    else {
        stack<PII> Q; Q.push(PII(1, 1));
        dis[1][1] = 0; vis[1][1] = true;
        while (!Q.empty()) {
            int a = Q.top().first, b = Q.top().second; Q.pop();
            vis[a][b] = false;
            for (int it = G[a][b]; ~it; it = E[it].nx) {
                int x = E[it].x, y = E[it].y, w = E[it].w;
                if (dis[x][y] > dis[a][b] + w) {
                    dis[x][y] = dis[a][b] + w;
                    if (!vis[x][y]) vis[x][y] = true, Q.push(PII(x, y));
                }
            }
        }
    }
    for (int j = 1; j <= w; ++ j) {
        for (int i = 1; i <= s; ++ i) {
            if (i > 1) putchar(' ');
            if (dis[i][j] < inf) printf("%d", dis[i][j]);
            else putchar('N');
        }
        puts("");
    }
    return 0;
}
