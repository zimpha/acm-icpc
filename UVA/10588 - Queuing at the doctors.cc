#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

struct Node {
	int id, t;
	Node (int id, int t) : id(id), t(t) {}
	bool operator < (const Node &oth) const {
		return (t > oth.t || (t == oth.t && id > oth.id));
	}
};

const int MAXN = 1000 + 10;
const int MAXM = 1000 + 10;

int T[MAXN], K[MAXN];
int C, N, M;

int main() {
	scanf("%d", &C);
	while (C --) {
		scanf("%d%d", &N, &M);
		queue <int> G[MAXN];
		for (int i = 0; i < N; ++ i) {
			scanf("%d%d", &T[i], &K[i]);
			for (int j = 0, g; j < K[i]; ++ j) {
				scanf("%d", &g);
				G[i].push(g);
			}
		}
		priority_queue <Node> Q[MAXM];
		for (int i = 0; i < N; ++ i) {
			int g = G[i].front();
			G[i].pop();
			Q[g].push(Node(i, T[i]));
		}
		int num, ret;
		for (num = 0, ret = 0; num < N; ++ ret) {
			for (int i = 1; i <= M; ++ i) {
				if (Q[i].empty() || Q[i].top().t > ret) continue;
				int id = Q[i].top().id, t = Q[i].top().t;
				Q[i].pop();
				if (!G[id].empty()) {
					int x = G[id].front(); G[id].pop();
					Q[x].push(Node(id, ret + 1));
				} else {
					num ++;
				}
			}
		}
		printf("%d\n", ret);
	}
	return 0;
}
