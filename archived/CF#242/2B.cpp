#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1000 + 10;

int x[MAXN], y[MAXN], k[MAXN];
int n, s;

bool check(double r) {
	int ret = s;
	for (int i = 0; i < n; ++ i)
		if (hypot(x[i], y[i]) <= r) ret += k[i];
	return ret >= 1000000;
}

int main() {
	cin >> n >> s;
	for (int i = 0; i < n; ++ i) cin >> x[i] >> y[i] >> k[i];
	double left = 0, right = 1e5;
	for (int _ = 0; _ < 100; ++ _) {
		double mid = (left + right) * 0.5;
		if (check(mid)) right = mid;
		else left = mid;
	}
	if (left >= 4e4) cout << "-1" << endl;
	else {
		cout.precision(10);
		cout << fixed << left << endl;
	}
	return 0;
}
