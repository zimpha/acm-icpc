#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

typedef long double real;

real a[10][10];
real A, B, C, D;

inline real sqr(real x) {return x * x;}

inline real F(real x) {
	return A * sqr(x * x) / 4 + B * x * sqr(x) / 3 + C * sqr(x) / 2 + D * x;
}

inline real f(real x) {
	return A * x * sqr(x) + B * sqr(x) + C * x + D;
}

void find_root(real left, real right, vector<real> &roots) {
	real fl = f(left);
	for (int i = 0; i < 100; ++ i) {
		real mid = (left + right) * 0.5;
		real fm = f(mid);
		if ((fl > 0 && fm > 0) || (fl < 0 && fm < 0)) left = mid;
		else right = mid;
	}
	roots.push_back(left);
}

const real eps = 1e-9;

void gauss() {
	for (int r = 0; r < 4; ++ r) {
		for (int i = r; i < 4; ++ i) {
			if (fabs(a[i][r] > eps)) {
				for (int j = 0; j <= 4; ++ j) swap(a[i][j], a[r][j]);
				break;
			}
		}
		for (int i = 0; i < 4; ++ i) {
			if (i == r) continue;
			real co = -a[i][r] / a[r][r];
			for (int j = 0; j <= 4; ++ j) a[i][j] += a[r][j] * co;
		}
	}
	A = a[3][4] / a[3][3]; B = a[2][4] / a[2][2];
	C = a[1][4] / a[1][1]; D = a[0][4] / a[0][0];
}

int main() {
	int T; scanf("%d", &T);
	while (T --) {
		int MT; scanf("%d", &MT);
		for (int i = 0; i < 4; ++ i) {
			int ct, cv; scanf("%d%d", &ct, &cv);
			a[i][0] = 1;
			for (int j = 1; j < 4; ++ j) a[i][j] = a[i][j - 1] * ct;
			a[i][4] = cv;
		}
		gauss();
		vector<real> roots;
		real a = 3 * A, b = 2 * B, c = C;
		real delta = b * b - 4 * a * c;
		if (delta > 0) {
			real x1 = (-b + sqrt(delta)) / (2 * a);
			real x2 = (-b - sqrt(delta)) / (2 * a);
			if (x1 > x2) swap(x1, x2);
			if (x1 < 0) x1 = 0;
			if (x2 < 0) x2 = 0;
			if (x1 > MT) x1 = MT;
			if (x2 > MT) x2 = MT;
			find_root(0, x1, roots);
			find_root(x1, x2, roots);
			find_root(x2, MT, roots);
		}
		else find_root(0, MT, roots);
		roots.push_back(0); roots.push_back(MT);
		sort(roots.begin(), roots.end());
		real ret = 0;
		for (int i = 1; i < (int)roots.size(); ++ i) {
			a = roots[i - 1]; b = roots[i];
			ret += fabs(F(b) - F(a));
		}
		printf("%.20Lf\n", ret);
	}
}
