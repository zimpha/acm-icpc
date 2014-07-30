#include <cmath>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef double real;
const real eps = 1e-8, inf = 1e18, Pi = acos(-1.0);

inline real sqr(real x) {return x * x;}
inline int cmp(real a, real b) {
	if (fabs(a - b) <= eps) return 0;
	else return (a < b) ? -1 : 1;
}

struct Point {
	real x, y;
	Point() {}
	Point(real a, real b) : x(a), y(b) {}
	friend bool operator < (const Point &a, const Point &b) {
		if (cmp(a.x, b.x) != 0) return cmp(a.x, b.x) < 0;
		else return cmp(a.y, b.y) < 0;
	}
	friend bool operator == (const Point &a, const Point &b) {
		return cmp(a.x, b.x) == 0 && cmp(a.y, b.y) == 0;
	}
	friend Point operator * (const real &k, const Point &u) {
		return Point(u.x * k, u.y * k);
	}
	friend Point operator * (const Point &u, const real &k) {
		return Point(u.x * k, u.y * k);
	}
	friend Point operator / (const Point &u, const real &k) {
		return Point(u.x / k, u.y / k);
	}
	friend Point operator - (const Point &a, const Point &b) {
		return Point(a.x - b.x, a.y - b.y);
	}
	friend Point operator + (const Point &a, const Point &b) {
		return Point(a.x + b.x, a.y + b.y);
	}
	real operator % (const Point &rhs) { //dmult
		return x * rhs.x + y * rhs.y;
	}
	real operator * (const Point &rhs) { //xmutl
		return x * rhs.y - y * rhs.x;
	}
	real sqr() {
		return x * x + y * y;
	}
	real abs() { //sqrt(x^2+y^2)
		return sqrt(this->sqr());
	}
	Point rotate(real A) { //逆时针旋转A弧度
		return Point(x * cos(A) - y * sin(A), x * sin(A) + y * cos(A));
	}
	Point rotate() {
		return Point(-y, x);
	}
	Point resize(real a) {
		return (*this) * (a / this->abs());
	}
};

struct Line {
	Point u, v;
	Line() {}
	Line(Point a, Point b) : u(a), v(b) {}
};

struct Circle {
	Point u; real r;
	Circle() {}
	Circle(Point a, real b) : u(a), r(b) {}
};

Point NoPoint = Point(inf, inf);
Line NoLine = Line(NoPoint, NoPoint);
Circle NoCircle = Circle(NoPoint, inf);

Point project(const Point &p, const Line &l) {
	Point o = l.v - l.u;
	return ((p - l.u) % o) / o.abs() * o + l.u;
}

Point intersect(const Line &a, const Line &b) {
	Point t = a.u - a.v, s = b.u - b.v;
	real o = s * t;
	if (cmp(o, 0) == 0) return NoPoint;
	return a.u + (a.u - b.u) * s / o * t;
}

Line intersect(const Line &l, const Circle &c) {
	Point s = project(c.u, l);
	real o = sqr(c.r) - (s - c.u).sqr();
	if (cmp(o, 0) < 0) return NoLine;
	Point t = (l.v - l.u).resize(sqrt(o));
	return Line(s - t, s + t);
}

Line intersect(const Circle &a, const Circle &b) {
	real l = (a.u - b.u).sqr();
	real w = (1 + (sqr(a.r) - sqr(b.r)) / l) * 0.5;
	real o = sqr(a.r) / l - sqr(w);
	if (cmp(o, 0) < 0) return NoLine;
	Point t = (a.u - b.u).rotate() * sqrt(o);
	Point s = a.u - w * (a.u - b.u);
	return Line(s - t, s + t);
}

Line tangent(const Point &p, const Circle &c) {
	real l = (p - c.u).sqr(), e = l - sqr(c.r);
	if (cmp(e, 0) < 0) return NoLine;
	real x = c.r / l, y = sqrt(e) / l;
	Point s = p - c.u, t = s.rotate();
	return Line(c.u + c.r * (x * s - y * t), c.u + c.r * (x * s + y * t));
}

pair<Line, Line> tangent(const Circle &a, const Circle &b) {
	real o = a.r - b.r, l = (a.u - b.u).sqr(), e = l - sqr(o);
	if (cmp(e, 0) < 0) return make_pair(NoLine, NoLine);
	real x = o / l, y = sqrt(e) / l;
	Point s = b.u - a.u, t = s.rotate();
	Line ll = Line(a.u + a.r * (x * s + y * t), b.u + b.r * (x * s + y *t));
	Line rr = Line(a.u + a.r * (x * s - y * t), b.u + b.r * (x * s - y *t));
	return make_pair(ll, rr);
}

struct Node {
	real l, r;
	Node() {};
	Node(real a, real b) : l(a), r(b) {}
};

bool intersect(Node &a, Node &b) {
	real t = Pi * 2;
	if (a.l < -Pi || a.r < -Pi) a.l += t, a.r += t;
	if (b.l < -Pi || b.r < -Pi) b.l += t, b.r += t;
	if (a.l > a.r) a.r += t;
	if (b.l > b.r) b.r += t;
	for (int i = 0; i < 2; ++ i) 
		for (int j = 0; j < 2; ++ j) {
			real l1 = a.l + i * t, r1 = a.r + i * t;
			real l2 = b.l + j * t, r2 = b.r + j * t;
			if ((l1 < l2 && l2 < r1) ||
				(l1 < r2 && r2 < r1) ||
				(l2 < l1 && l1 < r2) ||
				(l2 < r1 && r1 < r2))
				return true;
			if (cmp(l1, l2) == 0 && cmp(r1, r2) == 0) return true;
		}
	return false;
}

bool solve(const Point &p, const vector<Circle> &C) {
	int n = C.size();
	vector<Node> intervals; intervals.clear();
	for (int i = 0; i < n; ++ i) {
		int sgn = cmp((p - C[i].u).abs(), C[i].r);
		if (sgn < 0) return false;
		else if (sgn == 0) {
			Point t = C[i].u - p;
			real theta = atan2(t.y, t.x);
			intervals.push_back(Node(theta - Pi / 2, theta + Pi / 2));
		}
		else {
			Line l = tangent(p, C[i]);
			Point A = l.v - p, B = l.u - p;
			intervals.push_back(Node(atan2(A.y, A.x), atan2(B.y, B.x)));
		}
	}
	n = intervals.size();
	for (int i = 0; i < n; ++ i) {
		for (int j = i + 1; j < n; ++ j) {
			Node u = intervals[i], v = intervals[j];
			if (intersect(u, v)) return false;
		}
	}
	return true;
}

int main() {
	freopen("zen.in", "r", stdin);
	freopen("zen.out", "w", stdout);
	int n, x, y;
	scanf("%d%d%d", &n, &x, &y);
	vector<Circle> C(n);
	vector<Line> Lines;
	vector<Point> Points;
	Lines.clear(); Points.clear();
	for (int i = 0; i < n; ++ i) {
		scanf("%lf%lf%lf", &C[i].u.x, &C[i].u.y, &C[i].r);
		C[i].r *= -1;
		for (int j = 0; j < i; ++ j) {
			pair<Line, Line> lr = tangent(C[i], C[j]);
			Line L = lr.first, R = lr.second;
			if (L.u.x == inf) continue;
			if (L.u == L.v) {
				Point o = (C[i].u - C[j].u).rotate();
				Lines.push_back(Line(L.u + o, L.u - o));
			}
			else {
				Lines.push_back(L);
				Lines.push_back(R);
			}
		}
		C[i].r *= -1;
	}
	Lines.push_back(Line(Point(0, 0), Point(x, 0)));
	Lines.push_back(Line(Point(x, 0), Point(x, y)));
	Lines.push_back(Line(Point(x, y), Point(0, y)));
	Lines.push_back(Line(Point(0, y), Point(0, 0)));
	for (int j = 0; j < (int)Lines.size(); ++ j) {
		for (int i = j + 1; i < (int)Lines.size(); ++ i) {
			Point t = intersect(Lines[i], Lines[j]);
			if (t.x == inf) continue;
			Points.push_back(t);
		}
	}
	sort(Points.begin(), Points.end());
	Points.erase(unique(Points.begin(), Points.end()), Points.end());
	
	int ans;
	for (ans = 0; ans < (int)Points.size(); ++ ans) {
		Point p = Points[ans];
		if (cmp(p.x, 0) < 0 || cmp(p.x, x) > 0) continue;
		if (cmp(p.y, 0) < 0 || cmp(p.y, y) > 0) continue;
		if (solve(p, C)) {
			break;
		}
	}
	if (ans == (int)Points.size()) puts("No Zen");
	else printf("%.15f %.15f\n", Points[ans].x, Points[ans].y);
	fclose(stdin); fclose(stdout);
	return 0;
}
