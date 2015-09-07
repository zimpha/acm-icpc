#include <cstdio>
#include <cstring>
#include <cstdlib>
const int MAXN = 30000 + 10;

int fa[MAXN], size[MAXN], N, M;;

int Find(int x) {
	if (x - fa[x]) fa[x] = Find(fa[x]);
	return fa[x];
}

int main() {
	while (scanf("%d%d", &N, &M) == 2 && N) {
		for (int i = 0; i < N; ++ i) {
			fa[i] = i, size[i] = 1;
		}
		for (int i = 0, K; i < M; ++ i) {
			scanf("%d", &K);
			if (K) {
				int a, b; scanf("%d", &a);
				a = Find(a);
				for (int i = 1; i < K; ++ i) {
					scanf("%d", &b);
					b = Find(b);
					if (a != b) fa[b] = a, size[a] += size[b];
				}
			}
		}
		printf("%d\n", size[Find(0)]);
	}
	return 0;
}
