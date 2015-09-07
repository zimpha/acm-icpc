#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN = 100000 + 10;

int A[MAXN], N;

int main() {
	while (scanf("%d", &N) == 1 && N) {
		for (int i = 0; i < N; ++ i) scanf("%d", &A[i]);
		long long ret = 0;
		for (int i = 1; i < N; ++ i) {
			if (A[i - 1] < 0) ret -= A[i - 1];
			else ret += A[i - 1];
			A[i] += A[i - 1];
		}
		printf("%lld\n", ret);
	}
	return 0;
}
