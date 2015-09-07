#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1000005;

vector <int> A[MAXN];

int main() {
	int n, m;
	while (scanf("%d%d", &n, &m) == 2) {
		for (int i = 1; i < MAXN; ++ i) {
			A[i].clear();
		}
		for (int i = 0; i < n; ++ i) {
			int x; scanf("%d", &x);
			A[x].push_back(i + 1);
		}
		for (int i = 0; i < m; ++ i) {
			int k, v;
			scanf("%d%d", &k, &v);
			if ((int)A[v].size() < k) puts("0");
			else printf("%d\n", A[v][k - 1]);
		}
	}
	return 0;
}
