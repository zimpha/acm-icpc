#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN = 100 + 10;

struct House {
	int x, y, w, h, id;
	bool operator < (const House &rhs) const {
		if (x == rhs.x) return y < rhs.y;
		else return x < rhs.x;
	}
};

House A[MAXN], B[MAXN];
int N;

inline bool check(House &h) {
	int m = 0;
	for (int i = 0; i < N; ++ i) {
		House t = A[i];
		if (t.y >= h.y || t.x >= h.x + h.w || t.x + t.w <= h.x || t.h < h.h) continue;
		B[m ++] = t;
	}
	if (m == 0) return true;
	sort(B, B + m);
	int r = h.x;
	for (int i = 0; i < m; ++ i) {
		if (B[i].x > r) return true;
		r = max(r, B[i].x + B[i].w);
	}
	return (r < h.x + h.w);
}

inline void solve() {
	sort(A, A + N);
	for (int i = 0, flag = 1; i < N; ++ i) {
		if (check(A[i])) {
			if (!flag) putchar(' ');
			else flag = 0;
			printf("%d", A[i].id);
		}
	}
	puts("");
}

int main() {
	int cas = 0;
	while (scanf("%d", &N) == 1 && N) {
		 if (cas) puts("");
		 for (int i = 0; i < N; ++ i) {
		 	scanf("%d%d%d%*d%d", &A[i].x, &A[i].y, &A[i].w, &A[i].h);
			A[i].id = i + 1;
		 }
		 printf("For map #%d, the visible buildings are numbered as follows:\n", ++ cas);
		 solve();
	}
	return 0;
}
