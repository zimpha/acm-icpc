#include <map>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 100000 + 10;
struct Node {
	int id, x, y;
};

struct Line {
	int x, y1, y2;
	Line () {}
	Line (int _x, int _y1, int _y2) : x(_x), y1(_y1), y2(_y2) {}
	bool operator < (const Line &rhs) const {
		return x < rhs.x;
	}
};

Line C[MAXN];
Node p[MAXN];
int fa[MAXN];
int N;

int getfa(int x) {
	if (x != fa[x]) fa[x] = getfa(fa[x]);
	return fa[x];
}

bool cmpx(const Node &a, const Node &b) {
	if (a.x == b.x) return a.y < b.y;
	else return a.x < b.x;
}

bool cmpy(const Node &a, const Node &b) {
	if (a.y == b.y) return a.x < b.x;
	else return a.y < b.y;
}

int solve() {
	vector<Node> v;
	int ret = 0, M  = 0;
	sort(p, p + N, cmpx);
	for (int i = 0, j; i < N; i = j) {
		v.clear();
		for (j = i; j < N && p[j].x == p[i].x; ++ j) v.push_back(p[j]);
		if (v.size() & 1) return -1;
		for (int k = 0; k < (int)v.size(); k += 2) {
			int a = v[k].id, b = v[k + 1].id;
			a = getfa(a); b = getfa(b);
			if (a != b) fa[a] = b;
			ret += v[k + 1].y - v[k].y;
			C[M ++] = Line(p[i].x, v[k].y, v[k + 1].y);
		}
	}

	sort(p, p + N, cmpy);
	for (int i = 0, j; i < N; i = j) {
		v.clear();
		for (j = i; j < N && p[j].y == p[i].y; ++ j) v.push_back(p[j]);
		if (v.size() & 1) return -1;
		for (int k = 0; k < (int)v.size(); k += 2) {
			int a = v[k].id, b = v[k + 1].id;
			a = getfa(a); b = getfa(b);
			if (a != b) fa[a] = b;
			a = lower_bound(C, C + M, Line(v[k].x, 0, 0)) - C;
			b = upper_bound(C, C + M, Line(v[k + 1].x, 0, 0)) - C;
			for (; a < b; ++ a)
				if (C[a].y1 < p[i].y && C[a].y2 > p[i].y) return -1;
			ret += v[k + 1].x - v[k].x;
		}
	}
	int cnt = 0;
	for (int i = 0; i < N; ++ i)
		if (getfa(i) == i) cnt ++;
	return (cnt > 1) ? -1 : ret;
}

int main() {
	int T; scanf("%d", &T);
	while (T --) {
		scanf("%d", &N);
		for (int i = 0; i < N; ++ i) {
			scanf("%d%d", &p[i].x, &p[i].y);
			p[i].id = i; fa[i] = i;
		}
		printf("%d\n", solve());
	}
	return 0;
}
