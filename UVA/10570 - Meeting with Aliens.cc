#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN = 500 + 10;
const int INF = 1e9;

int A[MAXN], B[MAXN], C[MAXN], N;

inline void trans1(int p) {
	for (int i = 1; i <= N; ++ i) 
		if (p + i - 1 <= N) B[i] = A[p + i - 1], C[B[i]] = i;
		else B[i] = A[p + i - 1 - N], C[B[i]] = i;
}

inline void trans2(int p) {
	for (int i = 1; i <= N; ++ i)
		if (p - i + 1 >= 1) B[i] = A[p - i + 1], C[B[i]] = i;
		else B[i] = A[p - i + 1 + N], C[B[i]] = i;
}

inline int calc() {
	int ret = 0;
	for (int i = 1; i <= N; ++ i)
		if (B[i] != i) {
			B[C[i]] = B[i];
			C[B[i]] = C[i];
			ret ++;
		}
	return ret;
}

int main() {
	while (scanf("%d", &N) == 1 && N) {
		for (int i = 1; i <= N; ++ i) scanf("%d", A + i);
		int ret = INF;
		for (int i = 1; i <= N; ++ i) {
			trans1(i);
			ret = min(ret, calc());
			trans2(i);
			ret = min(ret, calc());
		}
		printf("%d\n", ret);
	}
	return 0;
}
