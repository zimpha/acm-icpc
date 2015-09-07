#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1000000 + 10;

int A[MAXN], B[MAXN];
int N, M;

int main() {
	int T; scanf("%d", &T);
	while (T --) {
		scanf("%d", &N);
		for (int i = 0; i < N; ++ i) scanf("%d", &A[i]);
		memcpy(B, A, sizeof(int) * N);
		sort(B, B + N);
		M = unique(B, B + N) - B;
		for (int i = 0; i < N; ++ i) A[i] = lower_bound(B, B + M, A[i]) - B;
		fill(B, B + M, 0);
		int ret = 0;
		for (int i = 0, j = 0; i < N; ++ i) {
			while (j < N && B[A[j]] == 0) {
				B[A[j]] = 1; ++ j;
			}
			if (j - i > ret) ret = j - i;
			B[A[i]] = 0;
		}
		printf("%d\n", ret);
	}
	return 0;
}
