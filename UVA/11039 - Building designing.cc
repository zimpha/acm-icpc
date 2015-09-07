#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 500000 + 10;

int A[MAXN], F[MAXN], N;

bool cmp(const int &a, const int &b) {
	return (abs(a) < abs(b));
}

int main() {
	int T; scanf("%d", &T);
	while (T --) {
		scanf("%d", &N);
		for (int i = 0; i < N; ++ i) scanf("%d", &A[i]);
		sort(A, A + N, cmp);
		int ret = 0;
		for (int i = 0, l1 = -1, l2 = -1; i < N; ++ i) {
			if (A[i] < 0) l1 = i, F[i] = (l2 == -1) ? 1 : F[l2] + 1;
			else l2 = i, F[i] = (l1 == -1) ? 1 : F[l1] + 1;
			ret = max(ret, F[i]);
		}
		printf("%d\n", ret);
	}
	return 0;
}
