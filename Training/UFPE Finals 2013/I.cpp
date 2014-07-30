#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const double PI = acos(-1.0);
const double eps = 1e-8;
const int MAXN = 10000 + 10;

struct Interval {
	double l, r;
	Interval() {}
	Interval(double _l, double _r) : l(_l), r(_r) {}
	bool operator < (const Interval &rhs) const {
		if (l != rhs.l) return l < rhs.l;
		return r < rhs.r;
	}
};

vector<Interval> Walls[MAXN], Doors[MAXN];
int N;

void init() {
	scanf("%d", &N);
	for (int i = 0, K; i < N; ++ i) {
		Walls[i].clear(); scanf("%d", &K);
		while (K --) {
			double l, r; scanf("%lf%lf", &l, &r);
			if (l > r) r += PI * 2;
			if (r > PI * 2) {
				Walls[i].push_back(Interval(0, r - PI * 2));
				r = PI * 2;
			}
			Walls[i].push_back(Interval(l, r));
		}
	}
}

void merge(vector<Interval> &V) {
	sort(V.begin(), V.end());
	vector<Interval> tmp(V);
	V.clear();
	double l = -1, r = -1;
	for (int i = 0; i < (int)tmp.size(); ++ i) {
		double x = tmp[i].l, y = tmp[i].r;
		if (r + eps > x) r = max(r, y);
		else {
			if (r > -eps) V.push_back(Interval(l, r));
			l = x, r = y;
		}
	}
	if (r > -eps) V.push_back(Interval(l, r));
}

void get_door() {
	for (int i = 0; i < N; ++ i) {
		merge(Walls[i]); Doors[i].clear();
		double st = 0;
		for (int j = 0; j < (int)Walls[i].size(); ++ j) {
			double x = Walls[i][j].l, y = Walls[i][j].r;
			if (st + eps < x) {
				Doors[i].push_back(Interval(st, x));
				st = y;
			}
			else st = max(st, y);
		}
		if (st + eps < PI * 2) Doors[i].push_back(Interval(st, PI * 2));
		merge(Doors[i]);
	}
}

bool check(double p) {
	double v = p * PI * 2;
	vector<Interval> now;
	now.push_back(Interval(0, PI * 2));
	for (int i = 0; i < N; ++ i) {
		vector<Interval> nxt;
		for (int j = 0; j < (int)now.size(); ++ j) {
			double x = now[j].l - v, y = now[j].r + v;
			if (x < 0) nxt.push_back(Interval(x + PI * 2, PI * 2));
			x = max(x, 0.0);
			if (y > PI * 2) nxt.push_back(Interval(0, y - PI * 2));
			y = min(PI * 2, y);
			nxt.push_back(Interval(x, y));
		}
		merge(nxt); now.clear();
		for (int a = 0, b = 0; a < (int)nxt.size() && b < (int)Doors[i].size();) {
			double l1 = nxt[a].l, r1 = nxt[a].r;
			double l2 = Doors[i][b].l, r2 = Doors[i][b].r;
			double l = max(l1, l2), r = min(r1, r2);
			if (l - eps < r) now.push_back(Interval(l, r));
			if (r1 < r2) a ++;
			else b ++;
		}
		merge(now);
	}
	return (int)now.size();
}

void solve(int cas) {
	double left = 0, right = 0.5;
	for (int times = 0; times < 100; ++ times) {
		double mid = (left + right) / 2;
		if (check(mid)) right = mid;
		else left = mid;
	}
	printf("Case #%d: %.4f\n", cas, left);
}

int main() {
	int T; scanf("%d", &T);
	for (int cas = 1; cas <= T; ++ cas) {
		init();
		get_door();
		check(0.44);
		solve(cas);
	}
	return 0;
}
