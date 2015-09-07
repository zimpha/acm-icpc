#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN = 10000 + 10;

double LA[MAXN];
int A[MAXN], SA[MAXN];
int N, K;

bool cmp(const int &a, const int &b) {
	return (abs(a) > abs(b) || (abs(a) == abs(b) && a > b));
}

inline int get_sum(int K) {
	int ret = 0; sort(A, A + N);
	for (int i = 1; i <= K; ++ i) ret += A[N - i];
	return ret;
}

int main() {
	while (scanf("%d%d", &N, &K) == 2 && N) {
		for (int i = 0; i < N; ++ i) scanf("%d", &A[i]);
		sort(A, A + N, cmp);
		int zero = 0, pos = 0, neg = 0, ret = 0;
		int p = 0, q = 0;
		for (int i = 0; i < K; ++ i) {
			if (A[i] == 0) zero ++;
			else if (A[i] < 0) neg ++, q = A[i];
			else pos ++, p = A[i];
			ret += A[i];
		}
		if (zero) ret = get_sum(K);
		else if ((neg % 2) && K < N) {
			int x = 0, y = 0;
			for (int i = K; i < N; ++ i) 
				if (A[i] > 0) {x = A[i]; break;}
			for (int i = K; i < N; ++ i)
				if (A[i] < 0) {y = A[i]; break;}
			if (!pos) {
				if (x) ret = ret - q + x;
				else ret = get_sum(K);
			} else {
				if (x == 0 && y == 0) ret = get_sum(K - 1);
				else if (x == 0) ret = ret - p + y;
				else if (y == 0) ret = ret - q + x;
				else if (x * p >= y * q) ret = ret - q + x;
				else ret = ret - p + y;
			}
		}
		printf("%d\n", ret);
	}
	return 0;
}
