#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN = 200000 + 10;

int A[MAXN], N, K;

long long solve(int L, int R) {
	if (L >= R) return 0;
	int mx = A[L], mid = (L + R) >> 1, M;
	for (int i = L; i <= R; ++ i)
		if (A[i] < mx) mx = A[i];
	for (int i = mid, j = mid; i >= L || j <= R; -- i, ++ j) {
		if (i >= L && A[i] == mx) {
			M = i; break;
		}
		if (j <= R && A[j] == mx) {
			M = j; break;
		}
	}
	vector<int> V(1, 0);
	int sum = 0;
	for (int i = L; i < M; ++ i) {
		sum = (sum + A[i]) % K;
		V.push_back(sum);
	}
	long long ret = 0;
	sort(V.begin(), V.end());
	ret += upper_bound(V.begin(), V.end(), sum) - lower_bound(V.begin(), V.end(), sum) - 1;
	for (int i = M + 1; i <= R; ++ i) {
		sum = (sum + A[i]) % K;
		ret += upper_bound(V.begin(), V.end(), sum) - lower_bound(V.begin(), V.end(), sum);
	}
	return ret + solve(L, M - 1) + solve(M + 1, R);
}

int main() {
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; ++ i) {
		scanf("%d", &A[i]);
	}
	printf("%lld\n", solve(0, N - 1));
	return 0;
}
