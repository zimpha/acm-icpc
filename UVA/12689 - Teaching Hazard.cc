#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000 + 10;

int p[MAXN], cnt[MAXN];
bool vis[MAXN];
int N, M, X;

void sieve() {
    for (int i = 0; i < MAXN; ++ i) vis[i] = 0; M = 0;
    for (int i = 2; i < MAXN; ++ i) {
        if (vis[i]) continue; p[M ++] = i;
        for (int j = i + i; j < MAXN; j += i) vis[j] = true;
    }
}

struct Node {
    int p, t, c;
    Node() {}
    Node(int _p, int _t, int _c) : p(_p), t(_t), c(_c) {}
    bool operator < (const Node &rhs) const {
        return c > rhs.c;
    }
};

vector<Node> V;

int main() {
    sieve();
    while (scanf("%d%d", &N, &X) == 2 && N) {
        V.clear();
        for (int i = 0; i < M; ++ i) {
            if (p[i] > N) break;
            int c = 0;
            for (long long j = p[i]; j <= N; j *= p[i]) c += N / j;
            for (int k = 1; c / k >= X; ++ k) V.push_back(Node(p[i], k == 1, c / k));
        }
        sort(V.begin(), V.end());
        for (int i = 0; i <= N; ++ i) cnt[i] = 1;
        long long ret = 0, tot = 0, mul = 1;
        for (int i = 0; i < (int)V.size(); ++ i) {
            if (i == 0 || V[i].c != V[i - 1].c) {
                ret += tot * (tot - 1) / 2;
                tot = 0;
            }
            if (V[i].c < X) break;
            if (V[i].t == 1) tot += mul;
            else tot += mul / cnt[V[i].p];
            mul /= cnt[V[i].p];
            ++ cnt[V[i].p];
            mul *= cnt[V[i].p];
        }
        ret += tot * (tot - 1) / 2;
        printf("%lld\n", ret);
    }
    return 0;
}
