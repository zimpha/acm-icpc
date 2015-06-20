#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXN = 5000 + 10;

int LCP[MAXN][MAXN];
char A[MAXN], B[MAXN];
int UA[MAXN], UB[MAXN];
int N, M;

void getLCP(char A[], char B[]) {
	int N = strlen(A), M = strlen(B);
	for (int i = 0; i <= N; ++ i) LCP[i][M] = 0;
	for (int j = 0; j <= M; ++ j) LCP[N][j] = 0;
	for (int i = N - 1; i >= 0; -- i)
		for (int j = M - 1; j >= 0; -- j) {
			if (A[i] == B[j]) LCP[i][j] = LCP[i + 1][j + 1] + 1;
			else LCP[i][j] = 0;
		}
}

int main() {
	scanf("%s%s", A, B);
	N = strlen(A), M = strlen(B);
	getLCP(A, A);
	for (int i = 0; i < N; ++ i) {
		int ret = 0;
		for (int j = 0; j < N; ++ j) {
			if (i == j) continue;
			ret = max(ret, LCP[i][j]);
		}
		UA[i] = ret + 1;
	}
	getLCP(B, B);
	for (int i = 0; i < M; ++ i) {
		int ret = 0;
		for (int j = 0; j < M; ++ j) {
			if (i == j) continue;
			ret = max(ret, LCP[i][j]);
		}
		UB[i] = ret + 1;
	}
	getLCP(A, B);
	int ret = -1;
	for (int i = 0; i < N; ++ i) {
		for (int j = 0; j < M; ++ j) {
			if (LCP[i][j] >= max(UA[i], UB[j])) {
				if (ret == -1) ret = max(UA[i], UB[j]);
				ret = min(ret, max(UA[i], UB[j]));
			}
		}
	}
	printf("%d\n", ret);
	return 0;
}
