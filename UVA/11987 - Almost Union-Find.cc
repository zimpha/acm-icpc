#include <cstdio>
#include <cstring>
#include <cstdlib>

const int MAXN = 200000 + 10;

int fa[MAXN], sum[MAXN], idx[MAXN], size[MAXN];
int N, M;

int Find(int x) {
	if (x != fa[x]) fa[x] = Find(fa[x]);
	return fa[x];
}

void Union(int x, int y) {
	int fx = Find(idx[x]), fy = Find(idx[y]);
	if (fx == fy) return;
	fa[fx] = fy;
	sum[fy] += sum[fx];
	size[fy] += size[fx];
}

void Move(int x, int y) {
	int fx = Find(idx[x]), fy = Find(idx[y]);
	if (fx == fy) return;
	size[fx] --; sum[fx] -= x;
	idx[x] = ++ N; fa[N] = N; size[N] = 1; sum[N] = x;
	Union(x, y);
}

int main() {
	while (scanf("%d%d", &N, &M) == 2) {
		for (int i = 1; i <= N; ++ i) {
			fa[i] = i; idx[i] = i;
			sum[i] = i; size[i] = 1;
		}
		while (M --) {
			int op, x, y;
			scanf("%d", &op);
			if (op == 1) {
				scanf("%d%d", &x, &y);
				Union(x, y);
			} else if (op == 2) {
				scanf("%d%d", &x, &y);
				Move(x, y);
			} else if (op == 3) {
				scanf("%d", &x);
				y = Find(idx[x]);
				printf("%d %d\n", size[y], sum[y]);
			}
		}
	}
	return 0;
}
