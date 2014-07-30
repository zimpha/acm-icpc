#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;
const int MAXN = 35;
const int SIZE = 1 << 10;

LL f[MAXN][SIZE], g[MAXN][SIZE];
bool ok[MAXN][MAXN];
int N, M, P, Q;

int main() {
	while (scanf("%d%d%d", &N, &M, &P) == 3) {
		scanf("%d", &Q);
		memset(ok, 1, sizeof(ok));
		while (Q --) {
			int x, y; scanf("%d%d", &x, &y);
			ok[x][y] = ok[y][x] = false;
		}
		memset(g, 0, sizeof(g)); g[0][0] = 1;
		memset(f, 0, sizeof(f)); f[0][0] = 1;
		for (int i = 0; i < N; ++ i) {
			for (int j = 0; j < (1 << M); ++ j) {
				if (!f[i][j]) continue;
				for (int k = 1; k <= M; ++ k) {
					if (!(j & (1 << (k - 1))) && ok[i + 1][k + N]) {
						f[i + 1][j | (1 << (k - 1))] += f[i][j];
					}
				}
			}
		}
		for (int i = 0; i < P; ++ i) {
			for (int j = 0; j < (1 << M); ++ j) {
				if (!g[i][j]) continue;
				g[i + 1][j] += g[i][j];
				for (int k = 1; k <= M; ++ k) {
					if (!(j & (1 << (k - 1))) && ok[i + 1 + N + M][k + N]) {
						g[i + 1][j | (1 << (k - 1))] += g[i][j];
					}
				}
			}
		}
		LL ret = 0;
		for (int i = 0; i < (1 << M); ++ i) {
			ret += f[N][i] * g[P][i];
		}
		printf("%lld\n", ret);
	}
	return 0;
}
