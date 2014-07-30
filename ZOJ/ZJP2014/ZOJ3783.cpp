#include <cmath>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN = 1000 + 10;
const double eps = 1e-8;
const double PI = acos(-1);

inline int cmp(double a, double b) {
	if (fabs(a - b) < eps) return 0;
	else if (a > b) return 1;
	else return -1;
}

struct Point {
	double x, y;
	Point() {}
	Point(double x, double y) : x(x), y(y) {}
	Point operator + (const Point &rhs) const {
		return Point(x + rhs.x, y + rhs.y);
	}
	Point operator - (const Point &rhs) const {
		return Point(x - rhs.x, y - rhs.y);
	}
	double abs() {
		return hypot(x, y);
	}
	double angle() {
		return atan2(y, x);
	}
	void read() {
		scanf("%lf%lf", &x, &y);
	}
};

struct Line {
	Point a, b;
	Line() {}
	Line(Point a, Point b) : a(a), b(b) {}
};

struct Circle {
	Point o;
	double r;
	Circle() {}
	Circle(Point o, double r) : o(o), r(r) {}
	void read() {
		o.read();
		scanf("%lf", &r);
	}
};

Circle C[MAXN], O;
int N;

inline double sqr(double x) {return x * x;}

bool intersect(Circle A, Circle B, double &Da, double &Db) {
	double len = (A.o - B.o).abs();
	if (cmp(len, A.r + B.r) > 0) return false;
	double deg = (B.o - A.o).angle();
	Da = deg + acos((sqr(A.r) + sqr(len) - sqr(B.r)) / (2 * A.r * len));
	Db = deg + PI - acos((sqr(B.r) + sqr(len) - sqr(A.r)) / (2 * len * B.r));
	return true;
}

int get_start() {
	for (int i = 0; i < N; ++ i) {
		if (cmp((O.o - C[i].o).abs(), O.r + C[i].r) == 0) return i;
	}
	return -1;
}

int get_next(const int &now, const double &nowd, double &nxtd, double &ret) {
	Circle A(C[now].o, C[now].r + O.r);
	int nxt = now;
	ret = PI * 4;
	for (int i = 0; i < N; ++ i) {
		if (i == now) continue;
		Circle B(C[i].o, C[i].r + O.r);
		double Da, Db;
		if (intersect(A, B, Da, Db)) {
			double delta = nowd - Da;
			if (cmp(delta, 0) <= 0) delta += PI * 2;
			if (cmp(delta, PI * 2) > 0) delta -= PI * 2;
			if (cmp(delta, ret) < 0) {
				ret = delta;
				nxtd = Db;
				nxt = i;
			}
		}
	}
	return nxt;
}

int main() {
	int T; scanf("%d", &T);
	while (T --) {
		scanf("%d", &N);
		for (int i = 0; i < N; ++ i) C[i].read();
		O.read();
		double ret = 0, nxtd, nowd, ang;
		int now, nxt, cnt, fid, fnid;
		for (int i = 0; i < N; ++ i) {
			if (cmp((O.o - C[i].o).abs(), O.r + C[i].r) == 0) {
				now = i;
				nowd = (O.o - C[i].o).angle();
			}
		}
		for (cnt = 0; ; ++ cnt) {
			nxt = get_next(now, nowd, nxtd, ang);
			if (nxt == now) {
				ret = PI * 2 * (O.r + C[now].r) / O.r;
				break;
			}
			if (cnt > 0) ret += ang * (O.r + C[now].r) / O.r;
			else fid = now, fnid = nxt;
			if (cnt && now == fid && nxt == fnid) break;
			nowd = nxtd; now = nxt;
			if (cmp(nowd, PI * 2) > 0) nowd -= PI * 2;
			if (cmp(nowd, 0) <= 0) nowd += PI * 2;
		}
		ret = ret / PI * 180;
		printf("%.10f\n", ret);
	}
	return 0;
}
