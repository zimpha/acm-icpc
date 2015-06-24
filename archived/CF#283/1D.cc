#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;
typedef long double flt;
const flt eps = 1e-9, INF = 1e18, PI = acos(-1.0);

inline flt sqr(flt x) {return x * x;}
inline int sgn(flt x) {
	if (fabs(x) <= eps) return 0;
	else return (x > eps) ? 1 : -1;
}

struct Point {
	flt x, y;
	Point() {}
	Point(flt a, flt b) : x(a), y(b) {}
	bool operator < (const Point &rhs) const {
		if (sgn(x - rhs.x) != 0) return sgn(x - rhs.x) < 0;
		else return sgn(y - rhs.y) < 0;
	}
	bool operator == (const Point &rhs) const {
		return sgn(x - rhs.x) == 0 && sgn(y - rhs.y) == 0;
	}
	Point operator * (const flt &k) const {
		return Point(x * k, y * k);
	}
	Point operator / (const flt &k) const {
		return Point(x / k, y / k);
	}
	Point operator - (const Point &rhs) const {
		return Point(x - rhs.x, y - rhs.y);
	}
	Point operator + (const Point &rhs) const {
		return Point(x + rhs.x, y + rhs.y);
	}
	flt dot(const Point &rhs) { // 内积
		return x * rhs.x + y * rhs.y;
	}
	flt det(const Point &rhs) { // 外积
		return x * rhs.y - y * rhs.x;
	}
	flt sqr() {
		return x * x + y * y;
	}
	flt abs() { //sqrt(x^2+y^2)
        return hypot(x, y);
	}
	Point rotate(flt A) { // 逆时针旋转A rad
		return Point(x * cos(A) - y * sin(A), x * sin(A) + y * cos(A));
	}
	Point rotate() { // 逆时针旋转90
		return Point(-y, x);
	}
	Point resize(flt a = 1.0) { // 单位化
		return (*this) * (a / this->abs());
	}
    void read() {
        cin >> x >> y;
    }
};
// 判断点O是否在AB上
bool onSeg(Point &A, Point &B, Point &O) {
    return sgn((A - O).det(B - O) == 0) && sgn((A - O).dot(B - O)) <= 0;
}
// 判断AB是否与CD平行
bool parallel(Point &A, Point &B, Point &C, Point &D) {
    return sgn((B - A).det(D - C)) == 0;
}
// 点O到线段AB最短距离, 去掉前两行变成点到直线AB最短距离
flt disPointSeg(Point &A, Point &B, Point &O) {
    if (sgn((O - A).dot(B - A)) < 0) return (O - A).abs();
    if (sgn((O - B).dot(A - B)) < 0) return (O - B).abs();
    return fabs((O - A).det(B - A) / (A - B).abs());
}

const int MAXN = 1000 + 10;
Point P, Q;
Point A[MAXN], B[MAXN];
int n, m;

bool check(Point A, Point B, Point C) {
    flt r = (P - Q).abs();
    flt mn = min((B - A).abs(), (C - A).abs());
    flt mx = max((B - A).abs(), (C - A).abs());
    mn = min(mn, disPointSeg(B, C, A));
    return r > mn - eps && r < mx + eps;
}

int main() {
    P.read(); cin >> n;
    for (int i = 0; i < n; ++ i) A[i].read();
    A[n] = A[0];
    Q.read(); cin >> m;
    for (int i = 0; i < m; ++ i) B[i].read();
    B[n] = B[0];
    bool flag = false;
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < m; ++ j) {
            flag |= check(A[i] - P + Q, B[j], B[j + 1]);
            flag |= check(B[j] - Q + P, A[i], A[i + 1]);
        }
    }
    if (flag) puts("YES");
    else puts("NO");
    return 0;
}
