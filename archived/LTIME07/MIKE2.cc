#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef long long LL;

const int MAXN = 1000000 + 10;

int A[MAXN], N;
LL X;

int solve(int K) {
	LL M = X;
	for (int i = 0; i < N - K; ++ i) {
		int half = (A[i] + 1) >> 1;
		M -= half;
		if (M < 0) return -1;
	}
	int ret = 0;
	for (int i = 0; i < N - K; ++ i) {
		int rest = A[i] - (A[i] + 1) / 2;
		if (M >= rest) {
			ret ++;
			M -= rest;
		}
	}
	return ret;
}

int main() {
	scanf("%d%lld", &N, &X);
	for (int i = 0; i < N; ++ i) {
		scanf("%d", &A[i]);
	}
	sort(A, A + N);
	int left = 0, right = N;
	while (left < right) {
		int mid = (left + right - 1) >> 1;
		if (solve(mid) != -1) right = mid;
		else left = mid + 1;
	}
	int ret = solve(left);
	if (ret == -1) ret = 0;
	printf("%d %d\n", left, ret);
	return 0;
}
