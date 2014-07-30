#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN = 30;

struct Point {
	int x, y;
	Point() {}
	Point(int x, int y) : x(x), y(y) {}
	Point operator - (const Point &rhs) {
		return Point(x - rhs.x, y - rhs.y);
	}
	int operator * (const Point &rhs) {
		return x * rhs.y - y * rhs.x;
	}
	int operator ^ (const Point &rhs) {
		return x * rhs.x + y * rhs.y;
	}
};

inline bool onSeg(Point &o, Point &a, Point &b) {
	return ((a - o) * (b - o)) == 0 && ((a - o) ^ (b - o)) <= 0;
}

bool inPoly(int n, Point p[], Point o) {
	int cnt = 0;
	for (int i = 0; i < n; ++ i) {
		if (onSeg(o, p[i], p[i + 1])) return true;
		int k = (p[i + 1] - o) * (p[i] - o);
		int d1 = p[i].y - o.y;
		int d2 = p[i + 1].y - o.y;
		if (k > 0 && d1 <= 0 && d2 > 0) cnt ++;
		if (k < 0 && d2 <= 0 && d1 > 0) cnt --;
	}
	return cnt & 1;
}

int main() {
	double P0, Q0, P1, Q1;
	int N, A, B;
	Point p[MAXN];
	while (scanf("%lf%lf%lf%lf", &P0, &Q0, &P1, &Q1) == 4) {
		scanf("%d%d%d", &N, &A, &B);
		for (int i = 0; i < N; ++ i) {
			scanf("%d%d", &p[i].x, &p[i].y);
		}
		p[N] = p[0];
		double ret = 0;
		for (int i = (int)P0; i <= (int)P1; ++ i) {
			for (int j = (int)Q0; j <= (int)Q1; ++ j) {
				if (inPoly(N, p, Point(i, j))) {
					double l = max(i - 0.5, P0), r = min(i + 0.5, P1);
					double u = max(j - 0.5, Q0), v = min(j + 0.5, Q1);
					ret += (r - l) * (v - u) * (A * i + B * j);
				}
			}
		}
		ret /= (P1 - P0) * (Q1 - Q0);
		printf("%.3f\n", ret);
	}
	return 0;
}
