#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN = 100000 + 10;
const int inf = 1e9;

int a[MAXN], g[MAXN], n;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i) scanf("%d", &a[i]);
	g[0] = inf;
	int ret = 0;
	for (int i = 0; i < n; ++ i) {
		int left = 0, right = i + 1;
		while (left + 1 < right) {
			int mid = (left + right) >> 1;
			if (a[i] < g[mid]) left = mid;
			else right = mid;
		}
		g[left + 1] = max(g[left + 1], a[i]);
		ret = max(ret, left + 1);
	}
	printf("%d\n", ret);
	return 0;
}
