#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

bool vis[26], map[26][26];
char p[10], ans[10];

int main() {
	char st[1000];
	while (scanf("%s", st + 1) == 1 && st[1] != '#') {
		memset(vis, 0, sizeof(vis));
		memset(map, 0, sizeof(map));
		st[0] = ';';
		int n = strlen(st), m = 0;
		char u, v;
		for (int i = 0; i < n; ++ i) {
			if (st[i] == ':') continue;
			if (st[i] == ';') {
				u = st[i + 1]; i ++;
				if (i <n && !vis[u - 'A']) vis[u - 'A'] = 1, p[m ++] = u;
			} else {
				v = st[i];
				if (!vis[v - 'A']) vis[v - 'A'] = 1, p[m ++] = v;
				map[v - 'A'][u - 'A'] = map[u - 'A'][v - 'A'] = 1;
			}
		}
		sort(p, p + m);
		int ret = 1e9;
		do {
			int tmp = 0;
			for (int i = 0; i < m; ++ i)
				for (int j = i + 1; j < m; ++ j)
					if (map[p[i] - 'A'][p[j] - 'A']) tmp = max(tmp, j - i);
			if (tmp < ret) {
				ret = tmp;
				memcpy(ans, p, sizeof(p));
			}
		} while (next_permutation(p, p + m));
		for (int i = 0; i < m; ++ i) printf("%c ", ans[i]);
		printf("-> %d\n", ret);
	}
	return 0;
}
