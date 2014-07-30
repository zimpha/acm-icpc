#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 2000000;

int A[MAXN];

int main() {
	int T; scanf("%d", &T);
	while (T --) {
		int N, M; scanf("%d%d", &N, &M);
		N --; M --;
		memset(A, 0, sizeof(A));
		for (int i = 0; i <= N; ++ i) {
			A[i ^ (N - i)] ++;
		}
		long long ret = 0;
		for (int i = 0; i <= M; ++ i) {
			ret += N + 1 - A[i ^ (M - i)];
		}
		printf("%lld\n", ret);
	}
	return 0;
}
