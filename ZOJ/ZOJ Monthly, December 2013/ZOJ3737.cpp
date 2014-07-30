#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;
const int MAXN = 100 + 10;

double corner[MAXN][MAXN];
double H;
int N, M;

inline double ratio(double a, double b) {
	if (a == b) return 1.0;
	else return (a - H) / (a - b);
}

void calc(double a, double b, double c, double &ansdig, double &ansfill) {
	double low = min(a, min(b, c));
	double high = max(a, max(b, c));
	int same = (a == H) + (b == H) + (c == H);
	int more = (a > H) + (b > H) + (c > H);
	if (same == 3) return;
	double S = 0.25, total = S * (a + b + c) / 3.0;
	double dig = 0, fill = 0, tmp;
	switch (more) {
	case 0:
		dig = 0;
		fill = H * S - total;
		break;
	case 1:
		tmp = ratio(high, a) * ratio(high, b) * ratio(high, c) * S;
		dig = tmp * (high - H) / 3.0; fill = S * H - total + dig;
		break;
	case 2:
		tmp = ratio(low, a) * ratio(low, b) * ratio(low, c) * S;
		fill = tmp * (H - low) / 3.0; dig = total +fill - S * H;
		break;
	case 3:
		fill = 0;
		dig = total - H * S;
		break;
	}
	ansdig += dig; ansfill += fill;
}

int main() {
	while (scanf("%d%d", &N, &M) == 2) {
		scanf("%lf", &H);
		for (int i = 0; i <= N; ++ i) {
			for (int j = 0; j <= M; ++ j) {
				scanf("%lf", &corner[i][j]);
			}
		}
		double ansdig = 0, ansfill = 0;
		for (int i = 0; i < N; ++ i) {
			for (int j = 0; j < M; ++ j) {
				double c; scanf("%lf", &c);
				calc(c, corner[i][j], corner[i][j + 1], ansdig, ansfill);
				calc(c, corner[i][j], corner[i + 1][j], ansdig, ansfill);
				calc(c, corner[i + 1][j], corner[i + 1][j + 1], ansdig, ansfill);
				calc(c, corner[i][j + 1], corner[i + 1][j + 1], ansdig, ansfill);
			}
		}
		printf("%.3f %.3f\n", ansdig, ansfill);
	}
	return 0;
}
