#include <map>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int MAXN = 20000 + 10;

int fa[MAXN], val[MAXN];
int n, Q;

int Find(int x) {
	if (x != fa[x]) {
		int tmp = fa[x];
		fa[x] = Find(fa[x]);
		val[x] ^= val[tmp];
	}
	return fa[x];
}

bool Union(int x, int y, int v) {
	int fx = Find(x);
	int fy = Find(y);
	if (fx == fy) return ((val[x] ^ val[y]) == v);
	if (fx == n) swap(fx, fy);
	fa[fx] = fy;
	val[fx] = val[x] ^ v ^ val[y];
	return true;
}

int main() {
	int cas = 0;
	while (scanf("%d%d", &n, &Q) == 2 && n) {
		for (int i = 0; i <= n; ++ i) fa[i] = i, val[i] = 0;
		printf("Case %d:\n", ++ cas);
		bool isError = false;
		int facts = 0;
		for (int i = 0; i < Q; ++ i) {
			char st[100]; scanf("%s", st);
			if (st[0] == 'I') {
				int p, q, v;
				gets(st);
				facts ++;
				if (isError) continue;
				int cnt = sscanf(st, "%d%d%d", &p, &q, &v);
				if (cnt == 2) v = q, q = n;
				if (!Union(p, q, v)) {
					isError = true;
					printf("The first %d facts are conflicting.\n", facts);
				}
			} else {
				int k; scanf("%d", &k);
				vector <int> X; X.clear();
				for (int j = 0, x; j < k; ++ j) {
					scanf("%d", &x);
					X.push_back(x);
				}
				if (isError) continue;
				bool isKnow = true;
				int ret = 0;
				map <int, int> mp; mp.clear();
				map <int, int> :: iterator it;
				for (int j = 0; j < k; ++ j) {
					int fx = Find(X[j]);
					ret ^= val[X[j]];
					mp[fx] ++;
				}
				for (it = mp.begin(); it != mp.end(); ++ it) {
					if (it->second % 2) {
						if (it->first != n) isKnow = false;
						break;
					} else ret ^= val[it->first];
				}
				if (isKnow) printf("%d\n", ret);
				else puts("I don't know.");
			}
		}
		puts("");
	}
	return 0;
}
