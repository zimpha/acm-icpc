#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 20010;

int A[MAXN], B[MAXN];

int main() {
	int n, m;
	while (scanf("%d%d", &m, &n) == 2 && n) {
		for (int i = 0; i < m; ++ i) scanf("%d", &B[i]);
		for (int i = 0; i < n; ++ i) scanf("%d", &A[i]);
		sort(A, A + n); sort(B, B + m);
		int ret = 0, now = 0;
		for (int i = 0; i < n && now < m; ++ i) {
			if (A[i] >= B[now]) {
				ret += A[i];
				now ++;
			}
		}
		if (now < m) puts("Loowater is doomed!");
		else printf("%d\n", ret);
	}
	return 0;
}
