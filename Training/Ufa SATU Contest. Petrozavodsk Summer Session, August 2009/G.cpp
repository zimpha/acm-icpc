#include <iostream>
using namespace std;

typedef long long LL;

const int p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};

LL ret, n, mcnt;

void dfs(int dep, LL now, int cnt, int pre) {
	if (dep >= 16) return;
	if (cnt > mcnt) mcnt = cnt, ret = now;
	if (cnt == mcnt && now < ret) ret = now;
	for (int i = 1; i <= pre; ++ i) {
		if (n / p[dep] < now) break;
		dfs(dep + 1, now *= (LL)p[dep], cnt * (i + 1), i);
	}
}

int main() {
	int T; cin >> T;
	while (T --) {
		cin >> n;
		ret = n, mcnt = 0;
		dfs(0, 1, 1, 63);
		cout << ret << " " << mcnt << endl;
	}
	return 0;
}
