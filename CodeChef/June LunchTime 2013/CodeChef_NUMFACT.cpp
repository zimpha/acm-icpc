#include <map>
#include <cstdio>
#include <cstdlib>
using namespace std;

map <int, int> mp;

void solve(int x) {
	for (int i = 2; i * i <= x; ++ i) {
		while (x % i == 0) {
			x /= i;
			mp[i] ++;
		}
	}
	if (x > 1) mp[x] ++;
}

int main() {
	int T; scanf("%d", &T);
	while (T --) {
		mp.clear();
		int n, x; scanf("%d", &n);
		while (n --) {
			scanf("%d", &x);
			solve(x);
		}
		long long ret = 1;
		for (map <int, int>::iterator it = mp.begin(); it != mp.end(); ++ it) {
			ret = ret * (long long)(it->second + 1);
		}
		printf("%lld\n", ret);
	}
	return 0;
}
