#include <map>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int SIZE = 128;

typedef vector<int> VI;

struct Tree {
	int N;
	char label[SIZE];
	VI G[SIZE];
	void clear() {
		N = 0;
		memset(label, 0, sizeof(label));
		for (int i = 0; i < SIZE; ++ i) G[i].clear();
	}
};

map<VI, int> IDCache;
int cnt;

inline int ID(VI &v) {
	if (!IDCache.count(v)) IDCache[v] = cnt ++;
	return IDCache[v];
}

int get_tree(Tree &T, int fa = -1) {
	int x = T.N ++;
	if (fa >= 0) T.G[x].push_back(fa);
	char ch; scanf(" %c %c", &T.label[x], &ch);
	if (ch != '(') {
		ungetc(ch, stdin);
		return x;
	}
	while (1) {
		T.G[x].push_back(get_tree(T, x));
		if (scanf(" %c", &ch) != 1 || ch != ',') break;
	}
	return x;
}

int encode(Tree &T, int x, int fa = -1) {
	VI v; v.clear();
	if (fa >= 0) {
		int i; for (i = 0; T.G[x][i] != fa; ++ i);
		while (1) {
			if (++ i >= (int)T.G[x].size()) i = 0;
			int y = T.G[x][i];
			if (y == fa) break;
			v.push_back(encode(T, y, x));
		}
	} else {
		for (int i = 0; i < (int)T.G[x].size(); ++ i)
			v.push_back(encode(T, T.G[x][i], x));
		int best = 0, m = v.size();
		for (int s = 1; s < m; ++ s) {
			for (int i = best, j = s, k = 0; k < m; ++ k) {
				if (v[i] != v[j]) {
					if (v[j] < v[i]) best = s;
					break;
				}
				if (++ i >= m) i = 0;
				if (++ j >= m) j = 0;
			}
		}
		rotate(v.begin(), v.begin() + best, v.end());
	}
	v.push_back(T.label[x]);
	return ID(v);
}

bool solve(Tree &T1, Tree &T2) {
	if (T1.N != T2.N) return false;
	IDCache.clear(); cnt = 0;
	int ret = encode(T1, 0);
	for (int i = 0; i < T2.N; ++ i)
		if (ret == encode(T2, i)) return true;
	return false;
}

int main() {
	int T; scanf("%d", &T);
	while (T --) {
		Tree T1, T2;
		T1.clear(); get_tree(T1);
		T2.clear(); get_tree(T2);
		if (solve(T1, T2)) puts("same");
		else puts("different");
	}
	return 0;
}
