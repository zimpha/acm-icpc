#include <map>
#include <queue>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

typedef priority_queue<int> PQ;
const int MOD = 1e9 + 7;

map<int, int> mp;
vector<int> P;
vector<PQ> V;
int N;

void add(int p, int c) {
	if (mp.count(p)) V[mp[p]].push(c);
	else {
		mp[p] = P.size(); P.push_back(p);
		PQ t; t.push(c);
		V.push_back(t);
	}
}

void factorize(int n) {
	for (int i = 2; i * i <= n; ++ i) {
		if (n % i == 0) {
			int c = 0;
			while (n % i == 0) n /= i, c ++;
			add(i, c);
		}
	}
	if (n > 1) add(n, 1);
}

long long solve(PQ &Q, int p) {
	while (Q.size() > 1) {
		int a = Q.top(); Q.pop();
		int b = Q.top(); Q.pop();
		a --; b --;
		if (a) Q.push(a);
		if (b) Q.push(b);
	}
	long long ret = 1, t;
	if (Q.empty()) return 1;
	else t = Q.top();
	for (int i = 0; i < t; ++ i)
		ret = ret * p % MOD;
	return ret;
}

int main() {
	int T; scanf("%d", &T);
	while (T --) {
		V.clear(); P.clear(); mp.clear();
		scanf("%d", &N);
		for (int i = 0; i < N; ++ i) {
			int x; scanf("%d", &x);
			factorize(x);
		}
		long long ret = 1;
		for (int i = 0; i < (int)P.size(); ++ i) {
			ret = ret * solve(V[i], P[i]) % MOD;
		}
		printf("%lld\n", ret);
	}
	return 0;
}
