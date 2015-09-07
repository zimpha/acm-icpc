#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1000 + 10;

int A[MAXN], N;

int solve(int n) {
	if (n == 1) return A[0];
	if (n == 2) return A[1];
	if (n == 3) return A[0] + A[1] + A[2];
	if (2 * A[1] < A[0] + A[n - 2]) return A[0] + 2 * A[1] + A[N - 1] + solve(n - 2);
	else return 2 * A[0] + A[n - 2] + A[n - 1] + solve(n - 2);
}

void print(int n) {
	if (n == 1) printf("%d\n", A[0]);
	else if (n == 2) printf("%d %d\n", A[0], A[1]);
	else if (n == 3) printf("%d %d\n%d\n%d %d\n", A[0], A[2], A[0], A[0], A[1]);
	else {
		if (2 * A[1] < A[0] + A[n - 2]) {
			printf("%d %d\n", A[0], A[1]);
			printf("%d\n", A[0]);
			printf("%d %d\n", A[n - 2], A[n - 1]);
			printf("%d\n",A[1]);
		}
		else {
			printf("%d %d\n", A[0], A[n - 1]);
			printf("%d\n", A[0]);
			printf("%d %d\n", A[0], A[n - 2]);
			printf("%d\n",A[0]);
		}
		print(n - 2);
	}
}

int main() {
	int T; scanf("%d", &T);
	while (T --) {
		scanf("%d", &N);
		for (int i = 0; i < N; ++ i) scanf("%d", &A[i]);
		sort(A, A + N);
		printf("%d\n", solve(N));
		print(N);
		if (T) puts("");
	}
	return 0;
}
