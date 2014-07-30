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
const int MAXN = 60;

map<int, int> mp;
int p[MAXN], c[MAXN], N;
LL A, B, M, retX, retY;

void factorize(LL n) {
	for (int i = 2; i * i <= n; ++ i) {
		while (n % i == 0) {
			mp[i] ++;
			n /= i;
		}
	}
	if (n > 1) mp[n] ++;
}

bool dfs(int dep, LL nowx) {
	if (dep == N) {
		LL nowy = A * B / nowx;
		LL X = nowx + B, Y = nowy + A;
		if (X >= M) {
			if (X + Y < retX + retY || (X + Y == retX + retY && X < retX)) {
				retX = X; retY = Y;
			}
			return true;
		}
		return false;
	}
	bool flag = false;
	for (int i = 0; i <= c[dep]; ++ i) {
		flag |= dfs(dep + 1, nowx);
		nowx *= (LL)p[dep];
	}
	return flag;
}

int main() {
	while (scanf("%lld%lld%lld", &A, &B, &M) == 3) {
		mp.clear();
		factorize(A); factorize(B);
		map<int, int>::iterator it;
		for (N = 0, it = mp.begin(); it != mp.end(); ++ it) {
			p[N] = it->first;
			c[N ++] = it->second;
		}
		retX = retY = 1e18;
		if (dfs(0, 1)) printf("%lld %lld\n", retX, retY);
		else puts("No answer");
	}
	return 0;
}
