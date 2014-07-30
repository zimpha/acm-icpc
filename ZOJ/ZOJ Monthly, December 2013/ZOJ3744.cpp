#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main() {
	double x, e;
	while (scanf("%lf%%", &x) == 1) {
		if (x < 25) printf("0.000000000\n");
		else {
			x = sqrt(x * 0.04);
			e = 1 + 8.0 / sqrt(7.0) * sqrt(x) * sin(sqrt(7.0) / 2 * log(x));
			printf("%.12f\n", e);
		}
	}
	return 0;
}
