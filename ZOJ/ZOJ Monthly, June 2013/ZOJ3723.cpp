#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXN = 1000 + 10;
const int SIZE = 200;

vector<int> state[MAXN];
int popcount[1<<12];
int dp[2][SIZE][SIZE];
int grid[MAXN];
int N, M, cnt;

inline bool check(int line, int s1, int s2, int now, int p) {
	if (((grid[line] | s2) & (1 << p))) return false;
	if (!(grid[line - 1] & (1 << p)) && (s1 & (1 << p))) return false;
	if (p > 0 && ((now | s2) & (1 << (p - 1)))) return false;
	if (p > 1 && !(grid[line] & ( 1 << (p - 1))) && (now & (1 << (p - 2)))) return false;
	if (p > 1 && !(grid[line - 1] & ( 1 << (p - 1))) && (s1 & (1 << (p - 2)))) return false;
	if (s2 & (1 << (p + 1))) return false;
	if (!(grid[line - 1] & (1 << (p + 1))) && (s1 & (1 << (p + 2)))) return false;
	return true;
}

inline int getid(vector<int> &S, int t) {
	return lower_bound(S.begin(), S.end(), t) - S.begin();
}

void extand(int line, int s1, int s2, int now, int p) {
	if (p == M) {
		int t = line & 1, w = popcount[now];
		s1 = getid(state[line - 2], s1);
		s2 = getid(state[line - 1], s2);
		now = getid(state[line], now);
		dp[t ^ 1][s2][now] = max(dp[t ^ 1][s2][now], dp[t][s1][s2] + w);
		return;
	}
	extand(line, s1, s2, now, p + 1);
	if (check(line, s1, s2, now, p)) {
		extand(line, s1, s2, now | (1 << p), p + 1);
	}
}

void getstate(vector<int> &S, int g) {
	S.clear();
	for (int mask = 0; mask < (1 << M); ++ mask) {
		if ((mask & g) || (mask & (mask << 1)) || (mask & (mask >> 1))) continue;
		bool flag = true;
		for (int i = 1; i + 1 < M; ++ i) {
			if (!(g & (1 << i)) &&
				(mask & (1 << (i - 1))) && 
				(mask & (1 << (i + 1)))) flag = false;	
		}
		if (flag) S.push_back(mask);
	}
}

inline bool checkadj(int s1, int s2) {
	if (s1 & s2) return false;
	if (s1 & (s2 >> 1)) return false;
	if (s1 & (s2 << 1)) return false;
	return true;
}

int main() {
	for (int i = 0; i < (1 << 12); ++ i) popcount[i] = __builtin_popcount(i);
	while (scanf("%d%d", &N, &M) == 2 && N) {
		for (int i = 0; i <= N; ++ i) {
			char st[20]; grid[i] = 0;
			if (i != N) {
				scanf("%s", st);
				for (int j = 0; st[j]; ++ j)
					if (st[j] == 'X') grid[i] |= (1 << j);
			}
			getstate(state[i], grid[i]);
		}
		int ret = 0;
		if (N == 1) {
			for (int i = 0; i < (int)state[0].size(); ++ i)
				ret = max(ret, popcount[state[0][i]]);
			printf("%d\n", ret);
			continue;
		}
		memset(dp, 0, sizeof(dp));
		for (int j = 0; j < (int)state[0].size(); ++ j) {
			for (int k = 0; k < (int)state[1].size(); ++ k) {
				int s1 = state[0][j], s2 = state[1][k];
				if (!checkadj(s1, s2)) continue;
				dp[0][j][k] = popcount[s1] + popcount[s2];
			}
		}
		for (int i = 1, t = 0; i < N; ++ i) {
			t ^= 1; memset(dp[t], 0, sizeof(dp[t]));
			for (int j = 0; j < (int)state[i - 1].size(); ++ j) {
				for (int k = 0; k < (int)state[i].size(); ++ k) {
					if (!checkadj(state[i - 1][j], state[i][k])) continue;
					extand(i + 1, state[i - 1][j], state[i][k], 0, 0);
				}
			}
		}
		int t = (N & 1) ^ 1;
		for (int i = 0; i < (int)state[N - 1].size(); ++ i) {
			ret = max(ret, dp[t][i][0]);
		}
		printf("%d\n", ret);
	}
	return 0;
}
