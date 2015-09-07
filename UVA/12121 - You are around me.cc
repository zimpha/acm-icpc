#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 150000 + 10;
const double eps = 1e-8;
const double inf = 1e10;
const double Pi = acos(-1.0);

struct Point {
	double x, y;
	Point () {}
	Point (double x, double y) : x(x), y(y) {}
};

inline double dist(Point a, Point b) {
	return hypot(a.x - b.x, a.y - b.y);
}

inline bool cmpx(const Point &a, const Point &b) {
	if (a.x == b.x) return a.y < b.y;
	else return a.x < b.x;
}

inline bool cmpy(const Point &a, const Point &b) {
	if (a.y == b.y) return a.x < b.x;
	else return a.y < b.y;
}

double closest_pair(Point P[], int N) {
	int M = N >> 1;
	if (N == 1) return inf;
	if (N == 2) return dist(P[0], P[1]);
	double ret = min(closest_pair(P, M), closest_pair(P + M, N - M));
	vector <Point> v; v.clear();
	for (int i = 0; i < N; ++ i) {
		if (fabs(P[i].x - P[M].x) < ret + eps) v.push_back(P[i]);
	}
	sort(v.begin(), v.end(), cmpy);
	for (size_t i = 0; i < v.size(); ++ i) {
		for (size_t j = 1; j < 6 && i + j < v.size(); ++ j)
			ret = min(ret, dist(v[i], v[i + j]));
	}
	return ret;
}

int main() {
	static Point P[MAXN];
	int N, cas = 0;
	double e, theta;
	while (scanf("%d%lf%lf", &N, &e, &theta) == 3 && N) {
		theta = theta * Pi / 180.0;
		double ratio = sqrt(1 - e * e);
		for (int i = 0; i < N; ++ i) {
			double x, y; scanf("%lf%lf", &x, &y);
			P[i].x = (x * cos(theta) + y * sin(theta)) * ratio;
			P[i].y = y * cos(theta) - x * sin(theta);
		}
		sort(P, P + N, cmpx);
		double ret = closest_pair(P, N) / 2.0;
		if (e == 1) ret = 0;
		else ret = Pi * ret * ret / ratio;
		printf("Case %d:\n%.6f\n", ++ cas, ret);
	}
	return 0;
}
