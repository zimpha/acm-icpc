#include <cstdio>
#include <cstring>
#include <cstdlib>

const int MAXN = 20000 + 10;

int fa[MAXN], d[MAXN];

int Find(int x) {
	if (x != fa[x]) {
		int tmp = fa[x];
		fa[x] = Find(fa[x]);
		d[x] += d[tmp];
	}
	return fa[x];
}

int main() {
	int T; scanf("%d", &T);
	while (T --) {
		int n, u, v;
		char st[10];
		scanf("%d", &n);
		for (int i = 1; i <= n; ++ i) fa[i] = i, d[i] = 0;
		while (scanf("%s", st) == 1 && st[0] != 'O') {
			if (st[0] == 'E') {
				scanf("%d", &u);
				Find(u);
				printf("%d\n", d[u]);
			} else {
				scanf("%d%d", &u, &v);
				fa[u] = v;
				d[u] = abs(u - v) % 1000;
			}
		}
	}
	return 0;
}
