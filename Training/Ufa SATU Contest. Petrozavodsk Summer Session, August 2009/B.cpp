#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200000 + 10;

struct Node {
    int id, a, b;
    Node() {}
    Node(int id, int a, int b) : id(id), a(a), b(b) {}
    bool operator < (const Node &rhs) const {
        return a < rhs.a || (a == rhs.a && b > rhs.b);
    }
};

bool vis[MAXN];
Node D[MAXN];
int ret[MAXN];
int N, cnt;

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; ++ i) {
        int a, b; scanf("%d%d", &a, &b);
        D[i << 1] = Node(i, a, b);
        D[i << 1 | 1] = Node(i, b, a);
    }
    sort(D, D + 2 * N);
    cnt = 0; ret[cnt ++] = 0; vis[D[0].id] = 1;
    for (int i = 1; i < 2 * N; ++ i) {
        if (!vis[D[i].id] && D[i].b <= D[ret[cnt - 1]].b) {
            vis[D[i].id] = 1;
            ret[cnt ++] = i;
        }
    }
    if (cnt == N) {
        puts("YES");
        for (int i = 0; i < cnt; ++ i) {
            printf("%d %d\n", D[ret[i]].a, D[ret[i]].b);
        }
    }
    else {
        puts("NO");
    }
    return 0;
}
