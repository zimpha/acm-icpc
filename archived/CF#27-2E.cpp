#include <iostream>
using namespace std;

typedef long long LL;
const int p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
int n;
LL ret;

void dfs(int dep, LL now, int cnt, int pre) {
	if (cnt > n) return;
	if (cnt == n && ret > now) ret = now;
	for (int i = 1; i <= pre; ++ i) {
		if (ret / p[dep] < now) break;
		dfs(dep + 1, now *= (LL)p[dep], cnt * (i + 1), i);
	}
}

int main() {
	cin >> n;
	ret = 1ll << 60;
	dfs(0, 1, 1, 64);
	cout << ret << endl;
	return 0;
}
