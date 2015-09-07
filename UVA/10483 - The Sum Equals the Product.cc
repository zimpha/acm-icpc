#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>

using namespace std;

const double tmp = 100.0;
const double eps = 1e-9;
const int N = 10005;
struct state {
	double s, a, b, c;
}ans[N];

int cnt;
double n, m;

bool cmp(const state& p, const state& q) {
	if (fabs(p.s - q.s) > eps) return p.s < q.s;
	if (fabs(p.a - q.a) > eps) return p.a < q.a;
	if (fabs(p.b - q.b) > eps) return p.b < q.b;
	return p.c < q.c;
}

void get_ans() {
	int N = 0, M = 25600;
	for (int i = 1; i * i * i <= M * 10000; i++) {
		for (int j = i; j * j * i<= M * 10000; j++) {
			if (i * j <= 10000 || (i + j) * 10000 % (i * j - 10000)) continue;
			int x = (i + j) * 10000 / (i * j - 10000);
			if (x < j || x < i) continue;
			int sum = i + j + x;
			int f = i * j * x;
			if (f % 10000) continue;
			if (sum >= N && M >= sum && sum == f / 10000) {
				ans[cnt].s = sum/tmp; ans[cnt].a = i/tmp;
				ans[cnt].b = j/tmp; ans[cnt].c = x/tmp;
				cnt++;
			}
		}
	}
	sort(ans, ans + cnt, cmp);
}

int main() {
	cnt = 0;
	get_ans();
	while (scanf("%lf%lf", &n, &m) == 2) {
		for (int i = 0; i < cnt; i++) {
			if (ans[i].s < n) continue;
			if (ans[i].s > m) break;
		printf("%.2lf = %.2lf + %.2lf + %.2lf = %.2lf * %.2lf * %.2lf\n", ans[i].s, ans[i].a, ans[i].b, ans[i].c, ans[i].a, ans[i].b, ans[i].c);
		}
	}
	return 0;
}
