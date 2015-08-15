#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
const int MAXN = 100000 + 10;
const int SIZE = 400;

typedef char Num[20];

int B[MAXN][SIZE];
Num A[MAXN];
int len[MAXN];

int main() {
	int N, M, L;
	scanf("%d", &N);
	for (int i = 0; i < N; ++ i) {
		scanf("%s", A[i]);
		len[i] = strlen(A[i]);
	}
	scanf("%d", &M); L = (int)sqrt(M);
	for (int q = 1; q <= L; ++ q) {
		for (int i = 0; i < N; ++ i) {
			B[i][q] = len[i];
			if (i >= q) B[i][q] += B[i - q][q];
		}
	}
	while (M --) {
		int l, v, k; scanf("%d%d%d", &l, &v, &k); l --;
		if (v > L) {
			bool flag = false;
			while (l < N) {
				if (k > len[l]) k -= len[l];
				else {
					flag = true;
					printf("%c\n", A[l][k - 1]);
					break;
				}
				l += v;
			}
			if (!flag) puts("So sad");
		}
		else {
			int st = 0, flag = false;
			if (l >= v) st = B[l - v][v];
			if (k <= len[l]) {
				printf("%c\n", A[l][k - 1]);
				continue;
			}
			for (int j = 18; j >= 0; -- j) {
				if (l + (1 << j) * v >= N) continue;
				if (k > B[l + (1 << j) * v][v] - st) {
					l += (1 << j) * v;
				}
			}
			l += v;
			if (l < N) {
				flag = true;
				printf("%c\n", A[l][k - (B[l - v][v] - st) - 1]);
			}
			if (!flag) puts("So sad");
		}
	}
	return 0;
}
