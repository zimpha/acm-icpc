#include <set>
#include <queue>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXN = 50 + 10;

typedef set<int>::iterator iter;

struct State {
	int s;
	set<int> rec;
};

State ret;
int D[MAXN], N, M;

inline int ID(int x) {
	return lower_bound(D, D + N, x) - D;
}

inline State Add(State u, int k) {
	for (iter it = u.rec.begin(); it != u.rec.end(); ++ it) {
		int t = abs(*it - k), id = ID(t);
		if (id >= N || D[id] != t) continue;
		u.s |= (1 << id);
	}
	u.rec.insert(k);
	return u;
}

void bfs() {
	queue<State> Q;
	while (!Q.empty()) Q.pop();
	State u, v; ret.rec.clear();
	u.s = 0; u.rec.insert(0);
	Q.push(u);
	while (!Q.empty()) {
		u = Q.front(); Q.pop();
		if (u.s == M) {ret = u; return;}
		if (u.rec.size() == (size_t)7) continue;
		for (int i = 0; i < N; ++ i)
			if ((u.s & (1 << i)) == 0) {
				for (iter it = u.rec.begin(); it != u.rec.end(); ++ it) {
					if (*it + D[i] <= D[N - 1]) 
						Q.push(Add(u, *it + D[i]));
					if (*it > D[i]) 
						Q.push(Add(u, *it - D[i]));
				}
			}
	}
}

int main() {
	int cas = 0;
	while (scanf("%d", &N) == 1 && N) {
		for (int i = 0; i < N; ++ i) scanf("%d", &D[i]);
		sort(D, D + N);
		N = unique(D, D + N) - D; M = (1 << N) - 1;
		bfs();
		printf("Case %d:\n", ++ cas);
		printf("%d\n", (int)ret.rec.size());
		for (iter it = ret.rec.begin(); it != ret.rec.end(); ++ it) {
			if (it != ret.rec.begin()) putchar(' ');
			printf("%d", *it);
		}
		puts("");
	}
	return 0;
}
