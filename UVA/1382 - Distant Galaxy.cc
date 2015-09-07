#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

struct Point {
	int x, y;
	Point () {}
	Point (int x, int y) : x(x), y(y) {}
	bool operator < (const Point &oth) const {
		return x < oth.x;
	}
};

const int MAXN = 110;

Point P[MAXN];
int Y[MAXN], on[MAXN], on2[MAXN], left[MAXN];
int N, M;

int solve() {
	sort(P, P + N); sort(Y, Y + N);
	M = unique(Y, Y + N) - Y;
	int ret = 0;
	if (M <= 2) return N;
	for (int a = 0; a < M; ++ a) {
		for (int b = a + 1; b < M; ++ b) {
			int y1 = Y[a], y2 = Y[b];
			memset(left, 0, sizeof(left));
			memset(on, 0, sizeof(on));
			memset(on2, 0, sizeof(on2));
			int cnt =  0;
			for (int i = 0; i < N; ++ i) {
				if (!i || P[i].x != P[i - 1].x) {
					cnt ++; on[cnt] = on2[cnt] = 0;
					left[cnt] = left[cnt - 1] + on2[cnt - 1] - on[cnt - 1];
				}
				if (P[i].y > y1 && P[i].y < y2) on[cnt] ++;
				if (P[i].y >= y1 && P[i].y <= y2) on2[cnt] ++;
			}
			if (cnt <= 2) return N;
			for (int i = 1, t = 0; i <= cnt; ++ i) {
				ret = max(ret, left[i] + on2[i] + t);
				t = max(t, on[i] - left[i]);
			}
		}
	}
	return ret;
}

int main() {
	int cas = 0;
	while (scanf("%d", &N) == 1 && N) {
		for (int i = 0; i < N; ++ i) {
			scanf("%d%d", &P[i].x, &P[i].y);
			Y[i] = P[i].y;
		}
		printf("Case %d: %d\n", ++cas, solve());
	}
	return 0;
}
