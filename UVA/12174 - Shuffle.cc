#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN = 100000 + 10;

bool L[MAXN], R[MAXN];
int A[MAXN], C[MAXN];

inline bool check(int st, int d, int n) {
	for (int i = st; i < n; i += d) {
		if (!(L[i] && (i == 0 || R[i - 1]))) return false;
	}
	return true;
}

int main() {
	int T, s, n; scanf("%d", &T);
	while (T --) {
		scanf("%d%d", &s, &n);
		for (int i = 0; i < n; ++ i) {
			scanf("%d", A + i);
			L[i] = R[i] = 0;
		}

		fill(C + 1, C + s + 1, 0);
		for (int i = 0, j = 0, cnt = 0; i < n; ++ i) {
			while (j < n && j < i + s) {
				C[A[j]] ++;
				if (C[A[j]] == 1) cnt ++;
				j ++;
			}
			if (j - i == cnt) L[i] = 1;
			C[A[i]] --;
			if (C[A[i]] == 0) cnt --;
		}

		fill(C + 1, C + s + 1, 0);
		for (int i = n - 1, j = n - 1, cnt = 0; i >= 0; -- i) {
			while (j >= 0 && j > i - s) {
				C[A[j]] ++;
				if (C[A[j]] == 1) cnt ++;
				j --;
			}
			if (i - j == cnt) R[i] = 1;
			C[A[i]] --;
			if (C[A[i]] == 0) cnt --;
		}

		for (int i = n; i < s; ++ i) L[i] = 1, R[i] = R[i - 1];
		int ret = 0;
		for (int i = 0; i < s; ++ i) {
			if (check(i, s, max(s, n))) ret ++;
		}
		printf("%d\n", ret);
	}
	return 0;
}
