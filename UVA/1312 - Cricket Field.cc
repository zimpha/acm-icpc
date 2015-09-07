#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN = 100 + 10;

struct Point {
	int x, y;
	Point () {}
	Point (int x, int y) : x(x), y(y) {}
};

Point P[MAXN];
int N, W, H;

inline bool cmpx(const Point &a, const Point &b) {
	if (a.x == b.x) return a.y < b.y;
	else return a.x < b.x;
}

inline bool cmpy(const Point &a, const Point &b) {
	if (a.y == b.y) return a.x < b.x;
	else return a.y < b.y;
}

inline void Update(int &ret_x, int &ret_y, int &ret_len, int x, int y, int l) {
	if (l > ret_len) ret_x = x, ret_y = y, ret_len = l;
}

int main() {
	int T; scanf("%d", &T);
	while (T --) {
		scanf("%d%d%d", &N, &W, &H);
		for (int i = 0; i < N; ++ i) {
			scanf("%d%d", &P[i].x, &P[i].y);
		}
		P[N ++] = Point(0, 0); P[N ++] = Point(0, H);
		P[N ++] = Point(W, 0); P[N ++] = Point(W, H);
		sort(P, P + N, cmpx);
		int ret_x, ret_y, ret_len = 0;
		for (int i = 0; i < N; ++ i) {
			int high = H, low = 0;
			for (int j = i + 1; j < N; ++ j) {
				if (P[j].y > high || P[j].y < low) continue;
				Update(ret_x, ret_y, ret_len, P[i].x, low, min(P[j].x - P[i].x, high - low));
				if (P[i].y == P[j].y) break;
				else if (P[j].y > P[i].y) high = min(high, P[j].y);
				else if (P[j].y < P[i].y) low = max(low, P[j].y);
			}
			high = H, low = 0;
			for (int j = i - 1; j >= 0; -- j) {
				if (P[j].y > high || P[j].y < low) continue;
				Update(ret_x, ret_y, ret_len, P[j].x, low, min(P[i].x - P[j].x, high - low));
				if (P[i].y == P[j].y) break;
				else if (P[j].y > P[i].y) high = min(high, P[j].y);
				else if (P[j].y < P[i].y) low = max(low, P[j].y);
			}
		}
		sort(P, P + N, cmpy);
		for (int i = 1; i < N; ++ i) {
			Update(ret_x, ret_y, ret_len, 0, P[i - 1].y, min(W, P[i].y - P[i - 1].y));
		}
		printf("%d %d %d\n", ret_x, ret_y, ret_len);
		if (T) puts("");
	}
	return 0;
}
