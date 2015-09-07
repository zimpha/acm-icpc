#include <set>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

struct point {
	int x, y;
	point (int x = 0, int y = 0) : x(x), y(y) {}
	void scan() { scanf("%d%d", &x, &y); }
	bool operator < (const point &oth) const {
		return (x < oth.x || (x == oth.x && y < oth.y));
	}
	point operator - (const point &oth) const {
		return point(x - oth.x, y - oth.y);
	}
	int operator ^ (const point &oth) const { //dmult
		return x * oth.x + y * oth.y;
	}
	int operator * (const point &oth) const { //xmult
		return x * oth.y - y * oth.x;
	}
};

struct line {
	point p, q;
	line (point p = point(), point q = point()) : p(p), q(q) {}
};

int sgn(int x) {
	return (x == 0 ? 0 : (x > 0 ? 1 : -1));
}

bool intersect(line A, line B) {
	point da = A.q - A.p, db = B.q - B.p;
	if ((!da.x && !da.y) || (!db.x && !db.y)) return false;
	if (da * db) {
		return (sgn(da * (B.q - A.p)) * sgn(da * (B.p - A.p)) <= 0 &&
				sgn(db * (A.q - B.p)) * sgn(db * (A.p - B.p)) <= 0);
	} else {
		if (da * (B.p - A.p) != 0) return false;
		int a1 = A.p ^ da, a2= A.q ^ da;
		if (a1 > a2) swap(a1, a2);
		int b1 = B.p ^ da, b2 = B.q ^da;
		if (b1 > b2) swap(b1, b2);
		if (a1 == b1) return true;
		if (a1 > b1) swap(a1, b1), swap(a2, b2);
		return a2 >= b1;
	}
}

int main() {
	int T; scanf("%d", &T);
	while (T --) {
		int S, R, W, P; scanf("%d%d%d%d", &S, &R, &W, &P);
		set <point> sensor; sensor.clear();
		for (int i = 0; i < S; ++ i) {
			point s; s.scan();
			sensor.insert(s);
		}
		vector <line> wall(W);
		for (int i = 0; i < W; ++ i) {
			wall[i].p.scan(); wall[i].q.scan();
		}
		for (int i = 0; i < P; ++ i) {
			vector <point> ret; ret.clear();
			point p, s; p.scan();
			for (s.x = p.x - R; s.x <= p.x + R; ++ s.x)
				for (s.y = p.y - R; s.y <= p.y + R; ++ s.y) {
					double D = sqrt((s - p) ^ (s - p));
					if (D <= R && sensor.count(s)) {
						for (int j = 0; j < W; ++ j) 
							if (intersect(line(s, p), wall[j])) D += 1;
						if (D <= R) ret.push_back(s);
					}
				}
			printf("%d", (int)ret.size());
			for (int j = 0; j < (int)ret.size(); ++ j) {
				printf(" (%d,%d)", ret[j].x, ret[j].y);
			}
			puts("");
		}
	}
	return 0;
}
