#include <cstdio>
#include <cstring>
#include <cstdlib>
const int MAXN = 50000 + 10;

int fa[MAXN], sum[MAXN];
int N, M;

int Find(int x) {
	if (x - fa[x]) fa[x] = Find(fa[x]);
	return fa[x];
}

int main() {
	int T; scanf("%d", &T);
	while (T --) {
		scanf("%d%d", &N, &M);
		for (int i = 0; i < N; ++ i) {
			scanf("%d", &sum[i]);
			fa[i] = i;
		}
		for (int i = 0; i < M; ++ i) {
			int a, b; scanf("%d%d", &a, &b);
			a = Find(a), b = Find(b);
			if (a != b) fa[a] = b, sum[b] += sum[a];
		}
		bool flag = true;
		for (int i = 0; i < N; ++ i) 
			if (i == Find(i) && sum[i]) flag = false;
		if (flag) puts("POSSIBLE");
		else puts("IMPOSSIBLE");
	}
	return 0;
}
