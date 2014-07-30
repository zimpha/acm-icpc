#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXN = 100000 + 10;

int mx[MAXN][20], L[MAXN];
int a[MAXN], b[MAXN], n, m;

void init(int n, int a[]) {
	L[0] = -1;
	for (int i = 1; i <= n; ++ i) L[i] = L[i >> 1] + 1;
	for (int i = 0; i < n; ++ i) mx[i][0] = a[i];
	for (int j = 1; (1 << j) < n; ++ j) {
		for (int i = 0; i + (1 << j) <= n; ++ i) {
			mx[i][j] = max(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);
		}
	}
}

int rmq(int a, int b) {
	if (a > b) swap(a, b);
	int k = L[b - a + 1];
	return max(mx[a][k], mx[b - (1 << k) + 1][k]);
}

int main() {
	while (scanf("%d", &n) == 1) {
		for (int i = 0; i < n; ++ i) scanf("%d", &a[i]);
		for (int i = 1; i < n; ++ i) b[i] = a[i] - a[i - 1];
		init(n, b);
		scanf("%d", &m);
		while (m --) {
			int t, d; scanf("%d%d", &t, &d);
			int k = upper_bound(a, a + n, t) - a;
			int left = 0, right = k - 1;
			while (left < right) {
				int mid = (left + right - 1) >> 1;
				int tmp = rmq(mid + 1, k - 1);
				if (tmp <= d) right = mid;
				else left = mid + 1;
			}
			printf("%d\n", left + 1);
		}
	}
	return 0;
}
