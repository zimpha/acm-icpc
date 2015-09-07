#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN = 200000 + 10;

int C[MAXN], pos[MAXN];

void add(int idx, int v) {
	for (int i = idx; i < MAXN; i += i & -i) {
		C[i] += v;
	}
}

int sum(int idx) {
	int ret = 0;
	for (int i = idx; i; i -= i & -i) {
		ret += C[i];
	}
	return ret;
}

int main() {
	int T; scanf("%d", &T);
	while (T --) {
		int N, M; scanf("%d%d", &N, &M);
		fill(C + 1, C + 1 + N + M, 0);
		for (int i = 1; i <= N; ++ i) {
			pos[i] = N - i + 1;
			add(i, 1);
		}
		int cnt = N;
		for (int i = 0; i < M; ++ i) {
			if (i) putchar(' ');
			int x; scanf("%d", &x);
			int ret = sum(pos[x]);
			printf("%d", N - ret);
			add(pos[x], -1);
			pos[x] = ++ cnt;
			add(pos[x], 1);
		}
		puts("");
	}
	return 0;
}
