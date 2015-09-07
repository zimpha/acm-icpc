#include <cstdio>
#include <cstring>
#include <cstdlib>
const int MAXN = 10000 + 10;

int P[MAXN];
int N, K;

int main() {
	int T; scanf("%d", &T);
	while (T --) {
		scanf("%d%d", &N, &K);
		for (int i = 1; i <= N; ++ i) P[i] = 0;
		for (int i = 0, m, x; K --; ) {
			scanf("%d", &m);
			while (m --) {
				scanf("%d", &x);
				P[x] = ++ i;
			}
		}
		int ret = 0;
		while (1) {
			int i, j;
			for (i = 1, j = 0; i <= N; ++ i) {
				if (P[i] == 0 || P[i] == i) continue;
				if (P[P[i]] == 0) {
					printf("%d %d\n", i, P[i]);
					P[P[i]] = P[i]; P[i] = 0;
					ret ++; j = -1;
				}
				if (j == 0) j = i;
			}
			if (i > N && j == 0) break;
			if (j < 0) continue;
			for (i = N; i > 0 && P[i]; -- i);
			printf("%d %d\n", j, i);
			P[i] = P[j]; P[j] = 0; ret ++;
		}
		if (!ret) puts("No optimization needed");
		if (T) puts("");
	}
	return 0;
}
