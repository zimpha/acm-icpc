#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 2000;

int X[MAXN], Y[MAXN], N;
double K[MAXN];

int main() {
	int T; scanf("%d", &T);
	while (T --) {
		scanf("%d", &N);
		for (int i = 0; i < N; ++ i) scanf("%d%d", X + i, Y + i);
		int ret = 0;
		for (int i = 0; i < N; ++ i) {
			int M = 0, cnt;
			for (int j = 0; j < N; ++ j) {
				if (i != j) {
					double dx = X[j] - X[i], dy = Y[j] - Y[i];
					if (dx == 0) K[M ++] = 1e9;
					else K[M ++] = dy / dx;
				}
			}
			sort(K, K + M); cnt = 1;
			for (int i = 1; i < M; ++ i) {
				if (K[i] == K[i - 1]) cnt ++;
				else ret += cnt * (cnt - 1) / 2, cnt = 1;
			}
			ret += cnt * (cnt - 1) / 2;
		}
		printf("%d\n", ret / 3);
	}
	return 0;
}
