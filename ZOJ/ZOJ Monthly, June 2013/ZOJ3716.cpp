#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main() {
	double x[10], y[10], s[20];
	while (scanf("%lf%lf", x, y) == 2) {
		scanf("%lf%lf", x + 1, y + 1);
		scanf("%lf%lf", x + 2, y + 2);
		scanf("%lf%lf", x + 3, y + 3);
		int cnt = 0;
		for (int i = 0; i < 4; ++ i)
			for (int j = i + 1; j < 4; ++ j)
				s[cnt ++] = hypot(x[i] - x[j], y[i] - y[j]);
		double ret = 1e20;
		if (s[0] + s[5] < ret) ret = s[0] + s[5];
		if (s[1] + s[4] < ret) ret = s[1] + s[4];
		if (s[2] + s[3] < ret) ret = s[2] + s[3];
		printf("%.10f\n", ret);
	}
	return 0;
}
