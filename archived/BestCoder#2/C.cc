#include <set>
#include <map>
#include <queue>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;;
typedef pair<int, int> PII;

const int MAXN = 1000 + 10;

struct Point {
    int x, y, idx;
    bool operator < (const Point &rhs) const {
        return x < rhs.x;
    }
    void read(int i) {
        scanf("%d%d", &x, &y);
        idx = i;
    }
};

vector<int> G[MAXN];
Point P[MAXN];
int dis[MAXN];
int N, L;

inline LL sqr(LL x) {return x * x;}
inline LL dist(LL x, LL y) {return sqr(x) + sqr(y);}

int bfs() {
    queue<int> Q;
    for (int i = 0; i < N; ++ i) dis[i] = -1;
    Q.push(0); dis[0] = 0;
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        if (u == 1) return dis[u] - 1;
        for (int i = 0, v; i < (int)G[u].size(); ++ i) {
            if (dis[v = G[u][i]] == -1) {
                dis[v] = dis[u] + 1;
                Q.push(v);
            }
        }
    }
    return -1;
}

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

void add(int u, int v) {
    G[u].push_back(v);
    G[v].push_back(u);
}

set<PII> hash;

bool find(int x, int y) {
    int g = gcd(x, abs(y));
    x /= g; y /= g;
    if (hash.count(PII(x, y))) return true;
    hash.insert(PII(x, y));
    return false;
}

int main() {
    int T; scanf("%d", &T);
    while (T --) {
        scanf("%d%d", &N, &L); N += 2;
        P[0].read(0); P[1].read(1);
        for (int i = 2; i < N; ++ i) {
            P[i].read(i);
        }
        sort(P, P + N);
        for (int i = 0; i < N; ++ i) G[i].clear();
        for (int i = 0; i < N; ++ i) {
            hash.clear();
            for (int j = i + 1; j < N; ++ j) {
                int xx = P[j].x - P[i].x, yy = P[j].y - P[i].y;
                if (dist(xx, yy) <= sqr(L) && !find(xx, yy)) add(P[i].idx, P[j].idx);
            }
        }
        int d = bfs();
        if (d != -1) printf("%d\n", d);
        else puts("impossible");
    }
    return 0;
}
