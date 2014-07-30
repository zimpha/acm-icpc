#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const double eps = 1e-8, PI = acos(-1.0), PI2 = PI * 2.0;
const double inf = 1e9;

struct Point {
	double x, y;
	Point() {}
	Point(double _x, double _y) : x(_x), y(_y) {}
	void read() {
		scanf("%lf%lf", &x, &y);
	}
	Point operator - (const Point &rhs) const {
		return Point(x - rhs.x, y - rhs.y);
	}
	Point operator + (const Point &rhs) const {
		return Point(x + rhs.x, y + rhs.y);
	}
	double operator * (const Point &rhs) const {
		return x * rhs.x + y * rhs.y;
	}
	double operator ^ (const Point &rhs) const {
		return x * rhs.y - y * rhs.x;
	}
	double len() {
		return hypot(x, y);
	}
	double len2() {
		return x * x + y * y;
	}
};

Point A, B, O;
double lenA, lenB, lenAB;
double aA, aB, aAOB, R, T, aT;

inline int sgn(double x) {
	return fabs(x) <= eps ? 0 : (x > 0 ? 1 : -1);
}

inline double Length(double a, double b, double theta) {
	return sqrt(a * a + b * b - 2 * a * b * cos(theta));
}

inline double Angle(double a, double b, double c) {
	return acos((a * a + b * b - c * c) / (2.0 * a * b));
}

double calc(double x, double y) {
	double ret = Length(lenA, R, x) + Length(lenB, R, y);
	double total = aAOB - x - y;
	if (sgn(T) == 0) ret += R * total;
	else {
		double times = floor(total / aT + eps);
		ret += times * T + Length(R, R, total - times * aT);
	}
	return ret;
}

double minimize(double x, double left, double right) {
	for (int _ = 0; _ < 50; ++ _) {
		double mid1 = (left * 2 + right) / 3.0;
		double mid2 = (right * 2 + left) / 3.0;
		if (calc(x, mid1) < calc(x, mid2)) right = mid2;
		else left = mid1;
	}
	return calc(x, left);
}

int main() {
	while (true) {
		A.read(); B.read(); O.read();
		scanf("%lf%lf", &R, &T);
		if (R == 0) break;
		A = A - O; B = B - O;
		aA = atan2(A.y, A.x), aB = atan2(B.y, B.x);
		lenA = A.len(), lenB = B.len(), lenAB = (A - B).len();
		// let A on OX-axis, B on I or II Quadrant
		if (sgn(aA) < 0) aA += PI2;
		if (sgn(aB) < 0) aB += PI2;
		aB = fabs(aA - aB); aA = 0;
		if (sgn(aB - PI) > 0) aB = PI2 - aB;
		
		double best = -inf;
		// deal with A can go straightly to B
		if (sgn(aB - aA) == 0) best = lenAB;
		else if (sgn((B - A) * B) <= 0 || sgn((A - B) * A) <= 0) best = lenAB;
		else {
			double h = fabs(A ^ B) / lenAB;
			double len = 2 * sqrt(max(R * R - h * h, 0.0));
			if (sgn(len - T) <= 0) best = lenAB;
		}
		if (best < -1) {
			double left = 0, right = acos(R / lenA);
			double loB = 0, hiB = acos(R / lenB);
			aAOB = Angle(lenA, lenB, lenAB); aT = Angle(R, R, T);
			for (int _ = 0; _ < 50; ++ _) {
				double mid1 = left + (right - left) / 3.0;
				double mid2 = right - (right - left) / 3.0;
				double f1 = minimize(mid1, loB, hiB);
				double f2 = minimize(mid2, loB, hiB);
				if (f1 < f2) right = mid2;
				else left = mid1;
			}
			best = minimize(left, loB, hiB);
		}
		printf("%.10f\n", best);
	}
	return 0;
}
