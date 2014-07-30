#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 30;

vector<int> S[MAXN];
bool g[MAXN][MAXN], found;
int mc[MAXN], ans, N, M;

void dfs(int num, int U[], int size) {
	if (num == 0) {
		if (size > ans) ans = size, found = 1;
		return;
	}
	for (int i = 0, k, j; i < num && !found; ++ i) {
		if (size + num - i < ans) break;
		if (size + mc[U[i]] <= ans) break;
		int tmp[MAXN];
		for (k = 0, j = i + 1; j < num; ++ j)
			if (g[U[i]][U[j]]) tmp[k ++] = U[j];
		dfs(k, tmp, size + 1);
	}
}

void max_clique() {
	int U[MAXN];
	ans = 0;
	for (int i = N - 1, j, k; i >= 0; -- i) {
		found = false;
		for (j = i + 1, k = 0; j < N; ++ j)
			if (g[i][j]) U[k ++] = j;
		dfs(k, U, 1);
		mc[i] = ans;
	}
}

bool check(vector<int> &A, vector<int> &B) {
	int n = A.size(), m = B.size();
	for (int i = 0, j = 0; i < n && j < m; ) {
		if (A[i] == B[j]) return false;
		if (A[i] < B[j]) i ++;
		else j ++;
	}
	return true;
}

int main() {
	scanf("%d%d", &M, &N);
	for (int i = 0, K, x; i < N; ++ i) {
		scanf("%d", &K); S[i].clear();
		for (int j = 0; j < K; ++ j) {
			scanf("%d", &x);
			S[i].push_back(x);
		}
	}
	memset(g, 0, sizeof(g));
	for (int i = 0; i < N; ++ i)
		for (int j = i + 1; j < N; ++ j)
			if (check(S[i], S[j])) g[i][j] = g[j][i] = 1;
	max_clique();
	printf("%d\n", mc[0]);
	return 0;
}
