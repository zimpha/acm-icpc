#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 65, MAXC = 310;

struct Node {
	int l, r, w;
	bool operator < (const Node &rhs) const {
		if (l != rhs.l) return l < rhs.l;
		return r < rhs.r;
	}
};

bool dp[MAXN][MAXC], Can[MAXC];
int pre[MAXN][MAXC];
Node S[MAXN];

int main() {
	int T; scanf("%d", &T);
	for (int cas = 1; cas <= T; ++ cas) {
		int N, M, K, tot = 0;
		scanf("%d%d%d", &N, &M, &K);
		for (int i = 1; i <= M; ++ i) {
			scanf("%d%d%d", &S[i].l, &S[i].r, &S[i].w);
			tot += S[i].w;
		}
		S[0] = (Node){0, 0, 0};
		sort(S, S + M);
		memset(dp, 0, sizeof(dp));
		memset(pre, 0x3f, sizeof(pre));
		dp[0][0] = true; pre[0][0] = -1;
		for (int i = 1; i <= M; ++ i) {
			for (int j = 0; j < i; ++ j) {
				if (S[j].l < S[i].l && S[j].r + 1 >= S[i].l && S[j].r < S[i].r) {
					for (int c = 0; c <= tot; ++ c) {
						if (dp[j][c] && pre[j][c] + 1 < S[i].l) {
							int tmp = c + S[i].w;
							pre[i][tmp] = min(pre[i][tmp], S[j].r);
							dp[i][tmp] = true;
						}
					}
				}
			}
		}
		memset(Can, 0, sizeof(Can));
		for (int i = 0; i <= M; ++ i) {
			if (S[i].r == N) {
				for (int c = 0; c <= tot; ++ c) Can[c] |= dp[i][c];
			}
		}
		long long ret = 0;
		while (K --) {
			long long X, Y; 
			scanf("%lld%lld", &X, &Y);
			if (X > tot) {
				long long c;
				for (c = tot; c > 0; -- c) if (Can[c]) break;
				ret += c * (Y - X + 1);
			}
			else {
				long long c;
				for (int i = X; i <= tot && i <= Y; ++ i) {
					for (c = i; c > 0; -- c) if (Can[c]) break;
					ret += c;
				}
				if (Y > tot) {
					for (c = tot; c > 0; -- c) if (Can[c]) break;
					ret += c * (Y - tot);
				}
			}
		}
		printf("Case #%d: %lld\n", cas, ret);
	}
	return 0;
}
