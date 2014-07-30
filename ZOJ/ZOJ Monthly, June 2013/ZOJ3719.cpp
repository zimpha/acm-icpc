#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN = 50000 + 10;
const int MAXH = 1000 + 10;
const int inf = 1e9;

struct Node {
	int items, potions;
	Node() {}
	Node(int i, int p) : items(i), potions(p) {}
	Node operator + (const Node &rhs) {
		return Node(items + rhs.items, potions + rhs.potions);
	}
	bool operator > (const Node &rhs) const {
		if (items != rhs.items) return items > rhs.items;
		return potions < rhs.potions;
	}
};

struct Monster {
	int type, h, d;
	void read() {
		scanf("%d", &type);
		if (type) scanf("%d%d", &h, &d);
	}
};

Monster A[MAXN];
Node dp[MAXN][6];
int need[MAXH][MAXH][11];
int N, H, D, P;

int solve(int i, int j, int k) {
	if (j <= 0) return inf;
	if (D >= i) return 0;
	if (need[i][j][k] != -1) return need[i][j][k];
	int &ret = need[i][j][k];
	ret = solve(i - D, min(H, j + P) - k, k) + 1;
	if (j > k) {
		ret = min(ret, solve(i - D, min(H, j - k + P), k) + 1);
		ret = min(ret, solve(i - D, j - k, k));
	}
	return ret;
}

int main() {
	while (scanf("%d", &N) == 1) {
		memset(need, -1, sizeof(need));
		for (int i = 1; i <= N; ++ i) A[i].read();
		scanf("%d%d%d", &H, &D, &P);
		for (int i = 0; i <= N; ++ i)
			for (int j = 0; j < 6; ++ j)
				dp[i][j] = Node(-1, inf);
		dp[0][0] = Node(0, 0);
		for (int i = 1; i <= N; ++ i) {
			for (int j = 0; j < 6; ++ j) {
				if (dp[i - 1][j].items == -1) continue;
				if (A[i].type) {
					if (dp[i - 1][j] > dp[i][j]) dp[i][j] = dp[i - 1][j];
					int po = solve(A[i].h, H, A[i].d);
					if (j == 5 && po < inf) {
						if (dp[i - 1][j] + Node(1, po) > dp[i][0]) {
							dp[i][0] = dp[i - 1][j] + Node(1, po);
						}
					}
				}
				else {
					int t = j + 1; if (t > 5) t = 5;
					if (dp[i - 1][j] > dp[i][t]) dp[i][t] = dp[i - 1][j];
				}
			}
		}
		Node ret = Node(-1, inf);
		for (int i = 0; i <= 5; ++ i) {
			if (dp[N][i].items != -1 && dp[N][i] > ret) {
				ret = dp[N][i];
			}
		}
		printf("%d %d\n", ret.items, ret.potions);
	}
	return 0;
}
