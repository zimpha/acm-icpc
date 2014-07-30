#include <cstdio>
#include <cstring>
#include <cstdlib>
const int MAXN = 100000 + 10;

double C[MAXN];
int A[MAXN], B[MAXN];

void add(int x) {
	for (int i = x; i < MAXN; i += (i & -i)) C[i] ++;
}

double get_sum(int x) {
	double ret = 0;
	for (int i = x; i; i -= (i & -i)) ret += C[i];
	return ret;
}

int main() {
	int T; scanf("%d", &T);
	while (T --) {
		int n, m; scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; ++ i) scanf("%d", &A[i]);
		for (int i = 1; i <= m; ++ i) scanf("%d", &B[i]);
		double AA = 0, BB = 0, AB = 0;
		memset(C, 0, sizeof(C));
		for (int i = n; i >= 1; -- i) {
			AA += get_sum(A[i] - 1);
			add(A[i]);
		}

		memset(C, 0, sizeof(C));
		BB = (double)m * (m - 1) / 2.0;
		for (int i = 1; i <= m; ++ i) {
			BB -= C[B[i]];
			C[B[i]] ++;
		}
		BB /= 2.0;

		for (int i = 2; i < MAXN; ++ i) C[i] += C[i - 1];
		for (int i = 1; i <= n; ++ i) {
			AB += (double)i * (m - C[A[i]]);
			AB += (double)(n - i + 1) * C[A[i] - 1];
		}
		AB /= (double)(n + 1);
		printf("%.10f\n", AA + AB + BB);
	}
	return 0;
}
