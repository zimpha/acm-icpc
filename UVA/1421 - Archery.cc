#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 5000 + 10;
const long double eps = 1e-8;

struct Archery {
	int D, L, R;
	void scan() {
		scanf("%d%d%d", &D, &L, &R);
	}
};

Archery S[MAXN];
int N, W;

bool check(int x, int y, int id) {
	long double a = 0, b = acos(-1);
	for (int i = 0; i < N; ++ i) {
		if (i == id) continue;
		long double ta, tb;
		if (S[i].D > y) {
			ta = atan2(S[i].D - y, S[i].R - x);
			tb = atan2(S[i].D - y, S[i].L - x);
		} else {
			ta = atan2(y - S[i].D, x - S[i].L);
			tb = atan2(y - S[i].D, x - S[i].R);
		}
		a = max(a, ta); b = min(b, tb);
		if (a > b + eps) return false;
	}
	return true;
}

int main() {
	int T; scanf("%d", &T);
	while (T --) {
		scanf("%d%d", &W, &N);
		for (int i = 0; i < N; ++ i) S[i].scan();
		S[N] = (Archery){0, 0, W}; N ++;
		bool flag = false;
		for (int i = 0; i < N - 1; ++ i) {
			flag = check(S[i].L, S[i].D, i) || check(S[i].R, S[i].D, i);
			if (flag) break;
		}
		if (flag) puts("YES");
		else puts("NO");
	}
	return 0;
}
