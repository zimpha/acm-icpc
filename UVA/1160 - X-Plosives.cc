#include <cstdio>
#include <cstring>
#include <cstdlib>

const int MAXN = 100000 + 10;

int fa[MAXN];

int Find(int x) {
	if (x != fa[x]) fa[x] = Find(fa[x]);
	return fa[x];
}

int main() {
	int x, y;
	while (scanf("%d", &x) == 1) {
		for (int i = 0; i < MAXN; ++ i) fa[i] = i;
		int ret = 0;
		while (x != -1) {
			scanf("%d", &y);
			x = Find(x); y = Find(y);
			if (x == y) ret ++;
			else fa[x] = y;
			scanf("%d", &x);
		}
		printf("%d\n", ret);
	}
	return 0;
}
