#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef long long LL;

const int MAXL = 400010;
const int MAXN = 10010;
const int SIZE = 50;
const int C = 26;

struct Trie {
	int cnt[C], go[MAXL][C];
	int sz, root;
	
	int new_node() {
		memset(go[sz], -1, sizeof(go[sz]));
		return sz ++;
	}

	void init() {
		memset(cnt, 0, sizeof(cnt));
		sz = 0; root = new_node();
	}

	void insert(const char *s) {
		int now = root;
		for (int i = 0, o; s[i]; ++ i, now = go[now][o]) {
			o = s[i] - 'a';
			if (go[now][o] == -1) {
				go[now][o] = new_node();
				if (i) cnt[o] ++;
			}
		}
	}
}suffix, prefix;

char word[MAXN][SIZE];
bool flag[C];

int main() {
	int n;
	while (scanf("%d", &n) == 1 && n) {
		prefix.init();
		for (int i = 0; i < n; ++ i) {
			scanf("%s", word[i]);
			prefix.insert(word[i]);
		}
		suffix.init();
		memset(flag, 0, sizeof(flag));
		for (int i = 0; i < n; ++ i) {
			int len = strlen(word[i]);
			reverse(word[i], word[i] + len);
			suffix.insert(word[i]);
			if (len == 1) flag[word[i][0] - 'a'] = true;
		}
		LL ret = (LL)(suffix.sz - 1) * (LL)(prefix.sz - 1);
		for (int i = 0; i < C; ++ i) {
			if (flag[i]) ret ++;
			ret -= (LL)prefix.cnt[i] * (LL)suffix.cnt[i];
		}
		printf("%lld\n", ret);
	}
	return 0;
}
