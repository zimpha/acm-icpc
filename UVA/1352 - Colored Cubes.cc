#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int cube[24][6] = {
	{2, 1, 5, 0, 4, 3}, {2, 0, 1, 4, 5, 3}, {2, 4, 0, 5, 1, 3}, {2, 5, 4, 1, 0, 3},
	{4, 2, 5, 0, 3, 1}, {5, 2, 1, 4, 3, 0}, {1, 2, 0, 5, 3, 4}, {0, 2, 4, 1, 3, 5},
	{0, 1, 2, 3, 4, 5}, {4, 0, 2, 3, 5, 1}, {5, 4, 2, 3, 1, 0}, {1, 5, 2, 3, 0, 4},
	{5, 1, 3, 2, 4, 0}, {1, 0, 3, 2, 5, 4}, {0, 4, 3, 2, 1, 5}, {4, 5, 3, 2, 0, 1},
	{1, 3, 5, 0, 2, 4}, {0, 3, 1, 4, 2, 5}, {4, 3, 0, 5, 2, 1}, {5, 3, 4, 1, 2, 0},
	{3, 4, 5, 0, 1, 2}, {3, 5, 1, 4, 0, 2}, {3, 1, 0, 5, 4, 2}, {3, 0, 4, 1, 5, 2},
};
const int MAXN = 4;

vector<string> Name;
int r[MAXN], color[MAXN][6];
int n, ret, dice[MAXN][6];

inline int ID(const char s[]) {
	string st(s);
	for (int i = 0; i < (int)Name.size(); ++ i) 
		if (st == Name[i]) return i;
	Name.push_back(st);
	return Name.size() - 1;
}

inline void solve() {
	for (int i = 0; i < n; ++ i) 
		for (int j = 0; j < 6; ++ j)
			color[i][cube[r[i]][j]] = dice[i][j];
	int tot = 0;
	for (int i = 0; i < 6; ++ i) {
		int cnt[MAXN * 6];
		memset(cnt, 0, sizeof(cnt));
		int maxface = 0;
		for (int j = 0; j < n; ++ j) {
			maxface = max(maxface, ++ cnt[color[j][i]]);
		}
		tot += n - maxface;
	}
	ret = min(ret, tot);
}

void dfs(int dep) {
	if (dep == n) solve();
	else {
		for (int i = 0; i < 24; ++ i) {
			r[dep] = i;
			dfs(dep + 1);
		}
	}
}

int main() {
	while (scanf("%d", &n) == 1 && n) {
		Name.clear();
		for (int i = 0; i < n; ++ i)
			for (int j = 0; j < 6; ++ j) {
				char st[100]; scanf("%s", st);
				dice[i][j] = ID(st);
			}
		ret = n * 6;
		r[0] = 0;
		dfs(1);
		printf("%d\n", ret);
	}
	return 0;
}
