#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN = 5000 + 10;

int a[MAXN], b[MAXN], N;

inline bool check(int lim) {
	int A = 0, B = 0, cnt = 0;
	for (int i = 0; i < N; ++ i) {
		A += a[i]; B += b[i];
		int na = max(0, A - lim), nb = max(0, B - lim);
		if (na + nb > cnt) return false;
		A -= na; B -= nb; cnt -= na + nb;
		if (A == 0 && B > 0) B --;
		else if (B == 0 && A > 0) A --;
		else if (A > 0 && B > 0 && A + B > cnt) cnt ++;
	}
	return true;
}

int main() {
	int T; scanf("%d", &T);
	while (T --) {
		scanf("%d", &N);
		for (int i = 0; i < N; ++ i) scanf("%d%d", a + i, b + i);
		int left = 0, right = N * 20;
		while (left < right) {
			int mid = (left + right - 1) >> 1;
			if (check(mid)) right = mid;
			else left = mid + 1;
		}
		printf("%d\n", max(0, left - 1));
	}
	return 0;
}
