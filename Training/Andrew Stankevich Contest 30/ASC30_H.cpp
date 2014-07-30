#include <cstdio>
#include <bitset>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN = 200;

bool G[MAXN][MAXN];
bitset<200> S[200];

void solve(int n) {
	for (int i = 0; i < n; ++ i) S[i].reset();
	for (int i = 0; i < n; ++ i) {
		for (int j = i + 1; j < n; ++ j) {
			if (G[i][j]) {
				S[j] |= S[i];
				S[j].set(i, 1);
			}
		}
	}
	int ret = 0;
	for (int i = 0; i < n; ++ i) ret += S[i].count();;
	printf("%d\n", ret);
}

int main() {
	freopen("settling.in", "r", stdin);
	freopen("settling.out", "w", stdout);
	int n, m; scanf("%d%d", &n, &m);
	memset(G, 0, sizeof(G));
	for (int i = 0, u, v; i < m; ++ i) {
		scanf("%d%d", &u, &v);
		u --, v --; G[u][v] = true;
	}
	solve(n);
	scanf("%d", &m);
	while (m --) {
		char st[10];
		int u, v;
		scanf("%s%d%d", st, &u, &v); u --, v --;
		if (st[0] == '?') {
			if (S[v][u]) puts("YES");
			else puts("NO");
		}
		else {
			G[u][v] = (st[0] == '+');
			solve(n);
		}
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
