#include <set>
#include <queue>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int MAXN = 100000 + 10;
const int inf = 1e9;

typedef pair<int, int> PII;

struct POS{
	int p, id;
	bool operator < (const POS &rhs) const {
		return p < rhs.p;
	}
};

struct Node {
	int l, r;
};

bool cmpl(const Node &a, const Node &b) {
	return (a.l < b.l || (a.l == b.l && a.r < b.r));
}

bool cmpr(const Node &a, const Node &b) {
	return (a.r > b.r || (a.r == b.r && a.l > b.l));
}

priority_queue<PII> Q;
multiset<int>::iterator it;
multiset<int> S;
Node CL[MAXN], CR[MAXN];
POS pos[MAXN];
int ret[MAXN];
int N, M;

int main() {
	int T; scanf("%d", &T);
	for (int cas = 1; cas <= T; ++ cas) {
		scanf("%d%d", &N, &M);
		for (int i = 0; i < N; ++ i) {
			int l, r, m; scanf("%d%d", &l, &r);
			m = (l + r) >> 1;
			if ((r - l) & 1) {
				CL[i] = (Node){l, m};
				CR[i] = (Node){m + 1, r};
			}
			else {
				CL[i] = (Node){l, m};
				CR[i] = (Node){m, r};
			}
		}
		for (int i = 0; i < M; ++ i) {
			scanf("%d", &pos[i].p);
			pos[i].id = i;
		}
		sort(pos, pos + M);
		sort(CL, CL + N, cmpl);
		S.clear(); while (!Q.empty()) Q.pop();
		for (int i = 0, j = 0; i < M; ++ i) {
			int x = pos[i].p, id = pos[i].id, y;
			while (j < N && CL[j].l <= x) {
				Q.push(make_pair(-CL[j].r, j));
				S.insert(CL[j].l);
				j ++;
			}
			while (!Q.empty()) {
				PII now = Q.top();
				if (-now.first < x) {
					Q.pop();
					it = S.find(CL[now.second].l);
					S.erase(it);
				}
				else break;
			}
			if (S.empty()) y = x;
			else y = *S.begin();
			ret[id] = max(x - y, 0);
		}
		sort(CR, CR + N, cmpr);
		S.clear(); while (!Q.empty()) Q.pop();
		for (int i = M - 1, j = 0; i >=0; -- i) {
			int x = pos[i].p, id = pos[i].id, y;
			while (j < N && CR[j].r >= x) {
				Q.push(make_pair(CR[j].l, j));
				S.insert(CR[j].r);
				j ++;
			}
			while (!Q.empty()) {
				PII now = Q.top();
				if (now.first > x) {
					Q.pop();
					it = S.find(CR[now.second].r);
					S.erase(it);
				}
				else break;
			}
			if (S.empty()) y = x;
			else y = *S.rbegin();
			ret[id] = max(ret[id], y - x);
		}
		printf("Case %d:\n", cas);
		for (int i = 0; i < M; ++ i) printf("%d\n", ret[i]);
	}
	return 0;
}
