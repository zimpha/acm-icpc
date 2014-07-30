#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXK = 8;
const int MAXN = 110;

struct Skill {
	int b, c, d;
	void scan() {
		scanf("%d%d%d", &b, &c, &d);
	}
	bool operator < (const Skill &rhs) const {
		return c > rhs.c;
	}
} skill[MAXK];

struct Amulet {
	int c, mask;
	void scan() {
		int n; mask = 0;
		scanf("%d%d", &c, &n);
		while (n --) {
			int x; scanf("%d", &x);
			mask |= 1 << (x - 1);
		}
	}
} amulet[MAXN];

int dp[1 << MAXK][MAXN];
int level[MAXK], sid[MAXK];
int N, K, X, Y, M;

void dfs(int dep, int ret, int X, int &ans) {
	if (dep == K) {
		for (int i = 0; i < K; ++ i) {
			int idx = sid[i];
			if (level[idx] == skill[idx].b) ret += skill[idx].d + skill[idx].b * skill[idx].c;
			else if (X >= skill[idx].b - level[idx]) {
				ret += skill[idx].d + level[idx] * skill[idx].c;
				X -= skill[idx].b - level[idx];
			}
			else {
				ret += (X + level[idx]) * skill[idx].c;
				X = 0;
			}
		}
		ans = max(ans, ret);
		return;
	}
	dfs(dep + 1, ret, X, ans);
	if (X >= skill[dep].b - level[dep]) {
		int tmp = level[dep];
		level[dep] = skill[dep].b;
		dfs(dep + 1, ret, X - skill[dep].b + tmp, ans);
		level[dep] = tmp;
	}
}

int solve(int mask, int now, int X) {
	memset(level, 0, sizeof(level));
	for (int i = 0; i < K; ++ i) level[i] = (mask >> i) & 1;
	int ret = 0;
	dfs(0, now, X, ret);
	return ret;
}

bool cmp(int a, int b) {
	return skill[a].c > skill[b].c;
}

int main() {
	while (scanf("%d%d", &K, &N) == 2) {
		for (int i = 0; i < K; ++ i) skill[i].scan();
		for (int i = 0; i < N; ++ i) amulet[i].scan();
		for (int i = 0; i < K; ++ i) sid[i] = i;
		sort(sid, sid + K, cmp);
		scanf("%d%d", &X, &Y);
		memset(dp, -1, sizeof(dp));
		dp[0][0] = 0; M = 1 << K; Y = min(Y, N);
		for (int i = 0; i < N; ++ i) {
			for (int j = Y - 1; j >= 0; -- j) {
				for (int now = 0; now < M; ++ now) {
					if (dp[now][j] == -1) continue;
					int next = now | amulet[i].mask;
					dp[next][j + 1] = max(dp[next][j + 1], dp[now][j] + amulet[i].c);
				}
			}
		}
		int ret = 0;
		for (int mask = 0; mask < M; ++ mask) {
			if (dp[mask][Y] != -1) {
				ret = max(ret, solve(mask, dp[mask][Y], X));
			}
		}
		printf("%d\n", ret);
	}
	return 0;
}
