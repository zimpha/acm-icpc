#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;
const int MAXN = 100000 + 10;
const LL inf = 1ll<<60;

struct Point {
	LL x, y;
	Point () {}
	Point (LL x, LL y) : x(x), y(y) {}
};

Point P[MAXN];
int n;

inline LL sqr(LL x) {return x * x;}
inline LL dist(Point a, Point b) {return sqr(a.x - b.x) + sqr(a.y - b.y);}

inline bool cmpx(const Point &a, const Point &b) {
	if (a.x == b.x) return a.y < b.y;
	else return a.x < b.x;
}

inline bool cmpy(const Point &a, const Point &b) {
	if (a.y == b.y) return a.x < b.x;
	else return a.y < b.y;
}

LL closest_pair(Point P[], int N) {
	int M = N / 2;
	if (N == 1) return inf;
	if (N == 2) return dist(P[0], P[1]);
	LL ret = min(closest_pair(P, M), closest_pair(P + M, N - M));
	vector <Point> v; v.clear();
	for (int i = 0; i < N; ++ i) {
		if (abs(P[i].x - P[M].x) < sqrt(ret)) v.push_back(P[i]);
	}
	sort(v.begin(), v.end(), cmpy);
	for (size_t i = 0; i < v.size(); ++ i) {
		for (size_t j = 1; j < 6 && i + j < v.size(); ++ j)
			ret = min(ret, dist(v[i], v[i + j]));
	}
	return ret;
}

int main() {
	cin >> n; P[0].y = 0;
	for (int i = 1; i <= n; ++ i) {
		cin >> P[i].y;
		P[i].x = i;
		P[i].y += P[i - 1].y;
	}
	cout << closest_pair(P + 1, n) << endl;
	return 0;
}
