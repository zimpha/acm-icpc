#include <cstdio>
#include <cstdlib>
using namespace std;

int main() {
	char buf[128];
	int c, h, m, s, t0 = 0, t1 = 0;
	double d = 0.0, v0 = 0.0, v1 = 0.0;
	while (gets(buf)) {
		c = sscanf(buf, "%d:%d:%d %lf", &h, &m, &s, &v1);
		t1 = h * 3600 + m * 60 + s;
		d += v0 * (t1 - t0) / 3600.0;
		t0 = t1;
		if (c == 3) printf("%.2d:%.2d:%.2d %.2lf km\n", h, m, s, d);
		else v0 = v1;
	}
	return 0;
}
