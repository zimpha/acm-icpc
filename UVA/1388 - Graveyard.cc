#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
	int n, m;
	while (scanf("%d%d", &n, &m) == 2) {
		double ret = 0;
		for (int i = 1; i < n; ++ i) {
			double pos = (double)i / n * (n + m);
			ret += fabs(pos - floor(pos + 0.5)) / (n + m);
		}
		printf("%.4lf\n", ret * 10000.0);
	}
	return 0;
}
