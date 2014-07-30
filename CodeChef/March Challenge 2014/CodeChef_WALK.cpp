#include <cstdio>
#include <cstring>
#include <cstdlib>
const int MAXN = 100000 + 10;

int a[MAXN], N;

bool check(int lim) {
	for (int i = 0; i < N; ++ i, lim --) 
		if (lim < a[i]) return false;
	return true;
}

int main() {
	int T; scanf("%d", &T);
	while (T --) {
		scanf("%d", &N);
		for (int i = 0; i < N; ++ i) scanf("%d", &a[i]);
		int left = 1, right = 2000000;
		while (left < right) {
			int mid = (left + right - 1) >> 1;
			if (check(mid)) right = mid;
			else left = mid + 1;
		}
		printf("%d\n", left);
	}
	return 0;
}
