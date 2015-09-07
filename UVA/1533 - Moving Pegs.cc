#include <stdio.h>
#include <string.h>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;
const int N = 20;
const int MAXN = 66666;

const int next[N][6] = {
	{-1, -1, -1, -1, 2, 3}, {-1, 1, -1, 3, 4, 5}, {1, -1, 2, -1, 5, 6}, 
	{-1, 2, -1, 5, 7, 8}, {2, 3, 4, 6, 8, 9}, {3, -1, 5, -1, 9, 10}, 
	{-1, 4, -1, 8, 11, 12}, {4, 5, 7, 9, 12, 13}, {5, 6, 8, 10, 13, 14}, 
	{6, -1, 9, -1, 14, 15}, {-1, 7, -1, 12, -1, -1}, {7, 8, 11, 13, -1, -1}, 
	{8, 9, 12, 14, -1, -1}, {9, 10, 13, 15, -1, -1}, {10, -1, 14, -1, -1, -1}
};

int T, n, vis[MAXN];
struct State {
	int s[N];
	int way[N][2];
	int wayn;
	int num;
}p;

void init() {
	scanf("%d", &n);
	memset(vis, INF, sizeof(vis));
	p.wayn = 0; p.num = 14;
	memset(p.way, 0, sizeof(p.way));
}

int hash(int *s) {
	int sum = 0;
	for (int i = 1; i <= 15; i ++) {
		if (s[i]) sum = sum * 2 + 1;
		else sum = sum * 2;
	}
	return sum;
}

void tra(State p, queue<State> &Q) {
	for (int i = 1; i <= 15; i ++) {
		if (p.s[i] == 1) {
			for (int j = 0; j < 6; j ++) {
				if (next[i - 1][j] != -1 && p.s[next[i - 1][j]] == 1) {
					int t = next[i - 1][j];
					State q = p; q.s[i] = 0; q.s[t] = 0;
					while (next[t - 1][j] != -1 && p.s[next[t - 1][j]] == 1) {
						q.num--; q.s[next[t - 1][j]] = 0;
						t = next[t - 1][j];
					}
					if (next[t - 1][j] == -1) continue;
					q.s[next[t - 1][j]] = 1; q.num--;
					q.way[q.wayn][0] = i; q.way[q.wayn++][1] = next[t - 1][j];
					int num = hash(q.s);
					if (vis[num] > q.wayn) {
						vis[num] = q.wayn;
						Q.push(q);
					}
				}
			}
		}
	}
}

bool bfs() {
	for (int i = 1; i <= 15; ++ i) {
		if (i == n) p.s[i] = 0;
		else p.s[i] = 1;
	}
	queue<State>Q;
	Q.push(p);
	while (!Q.empty()) {
		p = Q.front(); Q.pop();
		if (p.num == 1 && p.s[n] == 1) return true;
		tra(p, Q);
	}
	return false;
}

void solve() {
	if (!bfs()) {
		printf("IMPOSSIBLE\n");
		return;
	}
	printf("%d\n%d %d", p.wayn, p.way[0][0], p.way[0][1]);
	for (int i = 1; i < p.wayn; ++ i)
		printf(" %d %d", p.way[i][0], p.way[i][1]);
	printf("\n");
}

int main() {
	scanf("%d", &T);
	while (T--) {
		init();
		solve();
	}
	return 0;
}
