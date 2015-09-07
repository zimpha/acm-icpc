#include <cmath>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const double eps = 1e-8;
const double cs = .5;
const double ss = sqrt(3) * .5;

struct Point {
	double x, y;
	Point () {}
	Point (double _x, double _y) : x(_x), y(_y) {}
};

vector<Point> ret;
Point A, B;
double T;

inline int sgn(double x) {
	if (fabs(x) <= eps) return 0;
	else if (x > 0) return 1;
	else return -1;
}

inline bool cmp(const Point &a, const Point &b) {
	if (sgn(a.x - b.x) == 0) return sgn(a.y - b.y) < 0;
	else return sgn(a.x - b.x) < 0;
}

inline double dis(Point &a, Point &b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

void get_point(Point A, Point B) {
	Point V(B.x - A.x, B.y - A.y);
	Point C(A.x + V.x * .25, A.y + V.y * .25);
	Point D(A.x + V.x * .75, A.y + V.y * .75);
	Point E(C.x + .5 * (V.x * cs - V.y * ss), C.y + .5 * (V.x * ss + V.y * cs));
	double l = dis(A, B);
	if (sgn(l - 2.0 * T) >= 0) {
		ret.push_back(C);
		ret.push_back(D);
		ret.push_back(E);
		if (sgn(l - 4.0 * T) >= 0) {
			get_point(C, E);
			get_point(E, D);
		}
	}
}

int main() {
	int cas = 0;
	while (scanf("%lf%lf%lf%lf%lf", &A.x, &A.y, &B.x, &B.y, &T) == 5 && sgn(T - 1) > 0) {
		ret.clear();
		if (sgn(dis(A, B) - T) >= 0) {
			ret.push_back(A);
			ret.push_back(B);
			get_point(A, B);
		}
		sort(ret.begin(), ret.end(), cmp);
		printf("Case %d:\n%d\n", ++ cas, (int)ret.size());
		for (int i = 0; i < (int)ret.size(); ++ i)
			printf("%.5f %.5f\n", ret[i].x, ret[i].y);
	}
	return 0;
}
