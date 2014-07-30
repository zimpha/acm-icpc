#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-8;

struct Point {
	double x, y;
	Point() {}
	Point(double a, double b) : x(a), y(b) {}
	friend Point operator * (const double &k, const Point &u) {
		return Point(u.x * k, u.y * k);
	}
	friend Point operator * (const Point &u, const double &k) {
		return Point(u.x * k, u.y * k);
	}
	friend Point operator / (const Point &u, const double &k) {
		return Point(u.x / k, u.y / k);
	}
	friend Point operator - (const Point &a, const Point &b) {
		return Point(a.x - b.x, a.y - b.y);
	}
	friend Point operator + (const Point &a, const Point &b) {
		return Point(a.x + b.x, a.y + b.y);
	}
	double operator % (const Point &rhs) { //dmult
		return x * rhs.x + y * rhs.y;
	}
	double operator * (const Point &rhs) { //xmutl
		return x * rhs.y - y * rhs.x;
	}
	double sqr() {
		return x * x + y * y;
	}
	double abs() { //sqrt(x^2+y^2)
		return sqrt(this->sqr());
	}
	Point rotate(double A) { //ÄæÊ±ÕëÐý×ªA»¡¶È
		return Point(x * cos(A) - y * sin(A), x * sin(A) + y * cos(A));
	}
	Point rotate() {
		return Point(-y, x);
	}
	Point resize(double a) {
		return (*this) * (a / this->abs());
	}
    void read() {
        scanf("%lf%lf", &x, &y);
    }
};

inline int sgn(double x) {
    if (fabs(x) < eps) return 0;
    return x < 0 ? -1 : 1;
}

bool onSegment(const Point &O, const Point &A, const Point &B) { // O on AB
    if (sgn((B - A) * (O - A)) != 0) return false;
    if (sgn(A.x - B.x) != 0) return sgn(O.x - A.x) * sgn(O.x - B.x) <= 0;
    else return sgn(O.y - A.y) * sgn(O.y - B.y) <= 0;
}

bool intersect(const Point &A, const Point &B, const Point &C, const Point &D) { //AB & CD
    Point AB = B - A, CD = D - C;
    if (onSegment(A, C, D) || onSegment(B, C, D) || onSegment(C, A, B) || onSegment(D, A, B)) return true;
    int d1 = sgn(AB * (C - A)) * sgn(AB * (D - A));
    int d2 = sgn(CD * (A - C)) * sgn(CD * (B - C));
    return d1 < 0 && d2 < 0;
}

Point S, T, A, B, C;
double dis[5][5];

void init() {
    for (int i = 0; i < 5; ++ i) {
        dis[i][i] = 0;
        for (int j = i + 1; j < 5; ++ j) {
            dis[i][j] = dis[j][i] = 1e8;
        }
    }
    if (!intersect(S, A, B, C)) dis[0][1] = dis[1][0] = (A - S).abs();
    if (!intersect(T, A, B, C)) dis[4][1] = dis[1][4] = (A - T).abs();
    if (!intersect(S, C, A, B)) dis[0][3] = dis[3][0] = (C - S).abs();
    if (!intersect(T, C, A, B)) dis[4][3] = dis[3][4] = (C - T).abs();
    if (!intersect(S, T, A, B) && !intersect(S, T, B, C)) {
        dis[0][4] = dis[4][0] = (S - T).abs();
    }
    dis[1][2] = dis[2][1] = (A - B).abs();
    dis[1][3] = dis[3][1] = (A - C).abs();
    dis[2][3] = dis[3][2] = (B - C).abs();
    if (sgn((S - B) * (A - B)) * sgn((S - B) * (C - B)) >= 0) {
        dis[0][2] = dis[2][0] = (S - B).abs();
    }
    if (sgn((T - B) * (A - B)) * sgn((T - B) * (C - B)) >= 0) {
        dis[4][2] = dis[2][4] = (T - B).abs();
    }
}

int main() {
    int cas = 0; scanf("%d", &cas);
    while (cas --) {
        S.read(); T.read(); A.read(); B.read(); C.read();
        init();
        for (int k = 0; k < 5; ++ k) {
            for (int i = 0; i < 5; ++ i) {
                for (int j = 0; j < 5; ++ j) {
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }
        printf("%.10f\n", dis[0][4]);
    }
    return 0;
}
