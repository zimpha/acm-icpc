#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;

const LL inf = 1ll << 60ll;
const int MAXN = 40;
const int MAXL = 400;
const int MAXT = 15;

struct node {
	char c;
	int t;
	friend bool operator < (node a, node b) {
		return(a.c > b.c);
	}
};

string ret;
node letter[MAXN];
LL dp[MAXN][MAXL], comb[MAXL][MAXT];
LL N, M, L;

LL calc(int l) {
	LL sum[MAXN];
	memset(sum, 0, sizeof(sum));
	for (int i = 1; i <= N; i++)
		sum[i] = sum[i-1] + letter[i].t;
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1ll;
	for (int i = 0; i < N; i++)
		for (int j = 0; j <= sum[i]; j++)
		for (int k = 0; k <= letter[i+1].t; k++) {
		if (dp[i][j] <= inf / comb[j + k][k])
			dp[i+1][j + k] += dp[i][j] * comb[j + k][k];
		else dp[i+1][j + k] = inf;
		if (dp[i+1][j + k] > inf)dp[i+1][j + k] = inf;
	}
	LL res = 0ll;
	for (int i = l; i <= sum[N]; i++) {
		res += dp[N][i];
		if (res > inf)res = inf;
	}
	return res;
}

void solve(LL m, int l) {
	for (int i = 1; i <= N; i++)
		if (letter[i].t) {
		letter[i].t--;
		LL tmp = calc(l-1);
		if (tmp < m) letter[i].t++, m -= tmp;
		else {
			ret += letter[i].c;
			solve(m, l-1);
			return;
		}
	}
}

int main() {
	comb[0][0] = 1ll;
	for (int i = 1; i <= 360; i++) {
		comb[i][0] = 1ll;
		for (int j = 1; j <= min(10, i); j++) {
			comb[i][j] = comb[i-1][j] + comb[i-1][j-1];
			if (comb[i][j] > inf)comb[i][j] = inf;
		}
	}
	while ((cin >> N >> M >> L)) {
		for (int i = 1; i <= N; i++)
			cin >> letter[i].c >> letter[i].t;
		sort(letter+1, letter+1 + N);
		ret.clear();
		solve(M, L);
		if (!ret.size())cout << -1 << endl;
		else cout << ret << endl;
	}
	return 0;
}

