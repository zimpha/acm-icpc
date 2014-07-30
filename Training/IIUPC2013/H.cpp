#include <set>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXN = 40000 + 10;

int S[MAXN], P[MAXN], N, M;
int CS[MAXN], CP[MAXN];
set<int> same, large, small;

inline void add(int u) {
	if (CS[u] == CP[u]) same.insert(u);
	else if (CS[u] < CP[u]) small.insert(u);
	else large.insert(u);
}

inline void erase(int u) {
	if (CS[u] == CP[u]) same.erase(u);
	else if (CS[u] < CP[u]) small.erase(u);
	else large.erase(u);
}

int main() {
	int T; scanf("%d", &T);
	while (T --) {
		scanf("%d%d", &N, &M);
		vector<int> v;
		for (int i = 1; i <= N; ++ i) {
			scanf("%d", S + i);
			v.push_back(S[i]);
		}
		for (int i = 1; i <= M; ++ i) {
			scanf("%d", P + i);
			v.push_back(P[i]);
		}
		if (M > N) {printf("%d\n", 0); continue;}
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		memset(CS, 0, sizeof(CS)); memset(CP, 0, sizeof(CP));
		for (int i = 1; i <= N; ++ i) {
			S[i] = lower_bound(v.begin(), v.end(), S[i]) - v.begin();
			if (i < M) CS[S[i]] ++;
		}
		for (int i = 1; i <= M; ++ i) {
			P[i] = lower_bound(v.begin(), v.end(), P[i]) - v.begin();
			CP[P[i]] ++;
		}
		same.clear(); large.clear(); small.clear();
		for (int i = 0; i < (int)v.size(); ++ i) add(i);
		long long ret = 0;
		for (int i = M; i <= N; ++ i) {
			int u = S[i], v = S[i - M + 1];
			erase(u); CS[u] ++; add(u);
			if (large.empty() && small.empty()) ret += (long long)(i - M + 1) * (i - M + 1);
			erase(v); CS[v] --; add(v);
		}
		printf("%lld\n", ret);
	}
	return 0;
}
