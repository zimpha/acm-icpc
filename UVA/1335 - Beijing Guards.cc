#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXN = 100000 + 10;

int A[MAXN], N;

bool check(int lim) {
	static int left[MAXN], right[MAXN];
	int x = A[0], y = lim - x;
	left[0] = x, right[0] = 0;
	for (int i = 1; i < N; ++ i) {
		if (i & 1) {
			left[i] = min(x - left[i - 1], A[i]);
			right[i] = A[i] - left[i];
		} else {
			right[i] = min(y - right[i - 1], A[i]);
			left[i] = A[i] - right[i];
		}
	}
	return left[N - 1] == 0;
}

int main() {
	while (scanf("%d", &N) == 1 && N) {
		for (int i = 0; i < N; ++ i) scanf("%d", &A[i]);
		if (N == 1) {
			printf("%d\n", A[0]);
			continue;
		}
		A[N] = A[0];
		int left = 0, right = 0;
		for (int i = 0; i < N; ++ i) left = max(left, A[i] + A[i + 1]);
		if (N & 1) {
			for (int i = 0; i < N; ++ i) right = max(right, A[i] * 3);
			while (left < right) {
				int mid = (left + right - 1) >> 1;
				if (check(mid)) right = mid;
				else left = mid + 1;
			}
		}
		printf("%d\n", left);
	}
	return 0;
}
