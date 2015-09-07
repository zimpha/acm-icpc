#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN = 1 << 20;

int hash[MAXN], state[MAXN];
int trans[8];

inline void change(int n, int now, int &next) {
	next = 0;
	for (int i = 0; i < n; ++ i) {
		int tmp = 0;
		tmp = tmp * 2 + ((now & (1 << ((i - 2 + n) % n))) ? 1 : 0);
		tmp = tmp * 2 + ((now & (1 << i)) ? 1 : 0);
		tmp = tmp * 2 + ((now & (1 << ((i + 1) % n))) ? 1 : 0);
		next += trans[tmp] * (1 << i);
	}
}

int main() {
	int n, s, T, m;
	char st[100];
	while (scanf("%d", &n) == 1) {
		scanf("%s", st);
		fill(hash, hash + (1 << n), -1);
		int now = 0, next;
		for (int i = 0; i < n; ++ i) now += (st[i] - 'a') * (1 << i);
		for (int i = 0; i < 8; ++ i) {
			scanf("%s", st); next = 0;
			for (int j = 0; j < 3; ++ j) next = next * 2 + st[j] - 'a';
			trans[next] = st[3] - 'a';
		}

		scanf("%d", &s); m = 0;
		for (; ; now = next) {
			if (hash[now] != -1) {
				T = m - hash[now];
				break;
			}
			state[m] = now;
			hash[now] = m ++;
			change(n, now, next);
		}
		int ret;
		if (s <= hash[now]) ret = state[s];
		else ret = state[(s - hash[now]) % T + hash[now]];

		char ans[20], tmp[20];
		for (int i = 0; i < n; ++ i) ans[i] = 'b'; ans[n] = '\0';
		for (int i = 0; i < n; ++ i) {
			for (int j = i; j < i + n; ++ j) {
				if (ret & (1 << (j % n))) tmp[j - i] = 'b';
				else tmp[j - i] = 'a';
			}
			tmp[n] = '\0';
			if (strcmp(tmp, ans) < 0) strcpy(ans, tmp);
		}
		puts(ans);
	}	
	return 0;
}
