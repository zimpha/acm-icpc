#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

typedef long long LL;

const int MAXN = 1000010;

LL A[MAXN];

int main() {
	int N; 
	while (scanf("%d", &N) == 1) {
		LL ret = 0, ave = 0;
		for (int i = 1; i <= N; ++ i) {
			scanf("%lld", &A[i]);
			ave += A[i];
		}
		ave /= N; A[0] = 0;
		for (int i = 1; i < N; ++ i) {
			A[i] += A[i - 1] - ave;
		}
		nth_element(A, A + N / 2, A + N);
		LL tmp = A[N / 2];
		for (int i = 0; i < N; ++ i) {
			ret += abs(tmp - A[i]);
		}
		printf("%lld\n", ret);
	}
	return 0;
}
