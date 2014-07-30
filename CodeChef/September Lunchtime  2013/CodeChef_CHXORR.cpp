#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN = 2000 + 10;
const int SIZE = 80000 + 10;

int go[SIZE][2], A[MAXN], sz[SIZE];

int main() {
	int T; scanf("%d", &T);
	while (T --) {
		int n, cnt = 0; scanf("%d", &n);
		memset(go, -1, sizeof(go));
		memset(sz, 0, sizeof(sz));
		for (int i = 0; i < n; ++ i) {
			scanf("%d", &A[i]);
			for (int j = 30, root = 0; j >= 0; -- j) {
				int o = (A[i] >> j) & 1;
				if (go[root][o] == -1) go[root][o] = ++ cnt;
				root = go[root][o]; sz[root] ++;
			}
		}
		int ret = 0;
		for (int i = 0; i < n; ++ i) {
			for (int j = i + 1; j < n; ++ j) {
				int x = A[i] ^ A[j];
				for (int k = 30, r1 = 0, r2 = 0; k >= 0; -- k) {
					int o1 = (A[i] >> k) & 1;
					r1 = go[r1][o1]; sz[r1] --;
					int o2 = (A[j] >> k) & 1;
					r2 = go[r2][o2]; sz[r2] --;
				}
				int tmp = 0;
				for (int k = 30, root = 0; k >= 0; -- k) {
					int o = (x >> k) & 1;
					if (go[root][1 - o] != -1 && sz[go[root][1 - o]] > 0) {
						tmp |= (1 << k);
						root = go[root][1 - o];
					}
					else root = go[root][o];
				}
				ret = max(ret, tmp);
				for (int k = 30, r1 = 0, r2 = 0; k >= 0; -- k) {
					int o1 = (A[i] >> k) & 1;
					r1 = go[r1][o1]; sz[r1] ++;
					int o2 = (A[j] >> k) & 1;
					r2 = go[r2][o2]; sz[r2] ++;
				}
			}
		}
		printf("%d\n", ret);
	}
	return 0;
}
