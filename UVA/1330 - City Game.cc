#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int SIZE = 1010;

char A[SIZE][SIZE];
int up[SIZE][SIZE], left[SIZE][SIZE], right[SIZE][SIZE];

int main() {
	int T; scanf("%d", &T);
	while (T --) {
		int n, m; scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++ i) {
			for (int j = 0; j < m; ++ j) {
				for (A[i][j] = getchar(); A[i][j] != 'F' && A[i][j] != 'R'; A[i][j] = getchar());
			}
		}
		int ret = 0;
		for (int i = 0; i < n; ++ i) {
			int lo = -1, ro = m;
			for (int j = 0; j < m; ++ j) {
				if (A[i][j] == 'R') up[i][j] = 0, left[i][j] = 0, lo = j;
				else {
					up[i][j] = i ? up[i - 1][j] + 1 : 1;
					left[i][j] = i ? max(left[i - 1][j], lo + 1) : lo + 1;
				}
			}
			for (int j = m - 1; j >= 0; -- j) {
				if (A[i][j] == 'R') right[i][j] = m, ro = j;
				else {
					right[i][j] = i ? min(right[i - 1][j], ro - 1) : ro - 1;
					ret = max(ret, up[i][j] * (right[i][j] - left[i][j] + 1));
				}
			}
		}
		printf("%d\n", ret * 3);
	}
	return 0;
}
