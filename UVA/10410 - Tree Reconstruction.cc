#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int MAXN = 1000 + 10;

vector <int> L[MAXN], S[MAXN];
int BFS[MAXN], DFS[MAXN];
int level[MAXN];
int N, M;

void get_level() {
	for (int i = 0; i < N; ++ i) {
		L[i].clear();
		level[i] = -1;
	}
	L[0].push_back(BFS[0]); level[BFS[0]] = 0;
	M = 1;
	for (int u = 1; u < N; ++ M) {
		int i, k;
		for (k = 0; u < N; ++ u) {
			bool flag = false;
			for (i = k + 1; i < N; ++ i) {
				if (DFS[i] == BFS[u]) {
					flag = true;
					k = i;
					break;
				}
			}
			if (!flag) break;
			level[BFS[u]] = M; L[M].push_back(BFS[u]);
		}
	}
}

int get_id(int x) {
	for (int i = 0; i < N; ++ i) 
		if (x == DFS[i]) return i;
	return -1;
}

void get_sons() {
	for (int i = 1; i <= N; ++ i) S[i].clear();
	for (int i = 0; i < M; ++ i) {
		for (int j = 0; j + 1 < (int)L[i].size(); ++ j) {
			int a = get_id(L[i][j]);
			int b = get_id(L[i][j + 1]);
			for (int k = a; k <= b; ++ k) {
				if (level[DFS[k]] == i + 1) {
					S[L[i][j]].push_back(DFS[k]);
				}
			}
		}
		int a = get_id(L[i].back());
		for (int k = a; k < N; ++ k) {
			if (level[DFS[k]] == i + 1) {
				S[L[i].back()].push_back(DFS[k]);
			}
		}
	}
}

void output() {
	for (int i = 1; i <= N; ++ i) {
		printf("%d:", i);
		sort(S[i].begin(), S[i].end());
		for (int j = 0; j < (int)S[i].size(); ++ j) {
			printf(" %d", S[i][j]);
		}
		puts("");
	}
}

int main() {
	while (scanf("%d", &N) == 1) {
		for (int i = 0; i < N; ++ i) {
			scanf("%d", &BFS[i]);
		}
		for (int i = 0; i < N; ++ i) {
			scanf("%d", &DFS[i]);
		}
		get_level();
		get_sons();
		output();
	}
	return 0;
}
