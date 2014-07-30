#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>

typedef long long real;

int cmp(real a, real b, real c, real d) {
	real t = a/ b, s = c / d;
	if (t > s) return 1;
	if (t < s) return -1;
	a %= b, c %= d;
	if (a == 0 || c == 0) return (a == c) ? 0 : (a > c ? 1 : -1);
	return -cmp(b, a, d, c);
}

bool solve(real a, real b, real c, real l, real r) {
	if ((a * l + b) * l + c <= 0) return true;
	if ((a * r + b) * r + c <= 0) return true;
	if (a <= 0) return false;
	if (a * 2 * l <= -b && -b <= a * 2 * r) {
		if ((a >= 0 && c <= 0) || (a <= 0 && c >= 0)) return true;
		if (b == 0) return 0;
		return cmp(abs(b), abs(4 * a), abs(c), abs(b)) >= 0;
	}
	return false;
}

int main() {
	real x0, y0, c, T;
	while (scanf("%lld%lld%lld%lld", &x0, &y0, &c, &T) == 4) {
		int n, ret = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; ++ i) {
			real x, y, vx, vy;
			scanf("%lld%lld%lld%lld", &x, &y, &vx, &vy);
			x -= x0; y -= y0;
			if (solve(vx * vx + vy * vy - c * c, 2 * x * vx + 2 * y * vy, x * x + y * y, 0, T) ||
				solve(vx * vx + vy * vy - c * c, 2 * x * vx + 2 * y * vy + 4 * c * c * T, x * x + y * y - 4 * c * c * T * T, T, 2 * T))
				ret ++;
		}
		printf("%d\n", ret);
	}
	return 0;
}
