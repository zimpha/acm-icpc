#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, int> PLI;
typedef pair<PII, int> TT;
const int MAXN = 200000 + 10;
vector<PII> G[MAXN];
TT P[MAXN];
LL dis[MAXN];
int n;

inline void add(const TT &a, const TT &b) {
	G[a.second].push_back(PII(b.second, abs(a.first.first - b.first.first)));
}

void build() {
	sort(P, P + n);
	for (int i = 0; i < n; ++ i) {
		if (i) add(P[i], P[i - 1]);
		if (i + 1 < n) add(P[i], P[i + 1]);
	}
}

LL spfa() {
	for (int i = 0; i < n; ++ i) dis[i] = 1ll<<60;
	priority_queue<PLI> Q;
	Q.push(PII(0, 0)); dis[0] = 0;
	while (!Q.empty()) {
		PLI x = Q.top(); Q.pop();
		int u = x.second;
		LL d = -x.first;
		if (d > dis[u]) continue;
		for (auto &x : G[u]) {
			int v = x.first, w = x.second;
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				Q.push(PLI(-dis[v], v));
			}
		}
	}
	return dis[n - 1];
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i) {
		scanf("%d%d", &P[i].first.first, &P[i].first.second);
		P[i].second = i;
	}
	for (int i = 0; i < n; ++ i) G[i].clear();
	build();
	for (int i = 0; i < n; ++ i) {
		swap(P[i].first.first, P[i].first.second);
	}
	build();
	printf("%lld\n", spfa());
	return 0;
}
