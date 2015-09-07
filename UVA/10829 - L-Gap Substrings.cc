#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXN = 100010;

struct SuffixArray{
	int Count[MAXN], t_rank[MAXN][2], t_sa[MAXN];
	int rank[MAXN], sa[MAXN], height[MAXN];
	int mx[MAXN][20], log2[MAXN];
	char *s;
	int len;

	void construct(char* string, int n, int m) {
		memset(Count, 0, sizeof(Count));
		this->len = n; this->s = string;
		for (int i = 0; i < n; ++ i) Count[(int)string[i]] ++;
		for (int i = 0; i < m; ++ i) Count[i + 1] += Count[i];
		for (int i = 0; i < n; ++ i) rank[i] = Count[(int)string[i]] - 1;
		for (int len = 1; len < n; len <<= 1) {
			for (int i = 0; i < n; ++ i) {
				t_rank[i][0] = rank[i];
				t_rank[i][1] = i + len < n ? rank[i + len] + 1 : 0;
			}
			memset(Count, 0, sizeof(Count));
			for (int i = 0; i < n; ++ i) Count[t_rank[i][1]] ++;
			for (int i = 0; i < n; ++ i) Count[i + 1] += Count[i];
			for (int i = n - 1; i >= 0; -- i) t_sa[-- Count[t_rank[i][1]]] = i;
			memset(Count, 0, sizeof(Count));
			for (int i = 0; i < n; ++ i) Count[t_rank[i][0]] ++;
			for (int i = 0; i < n; ++ i) Count[i + 1] += Count[i];
			for (int i = n - 1; i >= 0; -- i) sa[-- Count[t_rank[t_sa[i]][0]]] = t_sa[i];
			rank[sa[0]] = 0;
			for (int i = 0; i + 1 < n; ++ i) {
				rank[sa[i + 1]] = rank[sa[i]] + (t_rank[sa[i]][0] != t_rank[sa[i + 1]][0] || t_rank[sa[i]][1] != t_rank[sa[i + 1]][1]);
			}
		}
		for (int i = 0, len = 0; i < n; ++ i) {
			if (!rank[i]) continue;
			int j = sa[rank[i] - 1];
			while (i + len < n && j + len < n && string[i + len] == string[j + len]) len++;
			height[rank[i]] = len;
			if (len) len--;
		}
		rmq_init(n);
	}

	void rmq_init(int n) {
		for (int i = 0; i < n; ++ i) mx[i][0] = height[i];
		for (int j = 1; (1 << j) < n; ++ j) {
			for (int i = 0; i + (1 << j) <= n; ++ i)
				mx[i][j] = min(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);
		}
		log2[1] = 1;
		for (int i = 2; i <= n; ++ i) log2[i] = log2[i >> 1] + 1;
	}

	int lcp(int a, int b) {
		a = rank[a], b = rank[b];
		if (a == b) return len - a + 1;
		if (a > b) swap(a, b);
		int k = log2[b - a] - 1;
		a ++; b -= (1 << k) - 1;
		return min(mx[a][k], mx[b][k]);
	}
}SA;

char st[MAXN];

int main() {
	int T; scanf("%d", &T);
	for (int cas = 1; cas <= T; ++ cas) {
		int L; scanf("%d%s", &L, st);
		int n = strlen(st);
		st[n] = 127;
		for (int i = 0; i < n; ++ i) st[n + i + 1] = st[n - i - 1];
		st[2 * n + 1] = '\0';
		SA.construct(st, 2 * n + 1, 256);
		int ret = 0;
		for (int len = 1; len < n / 2; ++ len) {
			for (int i = 0; i < n; i += len) {
				int j = i + L + len;
				int sum = 0;
				if (j < n) sum += min(SA.lcp(i, j), len);
				if (i >= 1) sum += min(SA.lcp(2 * n - i + 1, 2 * n - j + 1), len - 1);
				ret += max(0, sum - len + 1);
			}
		}
		printf("Case %d: %d\n", cas, ret);
	}
	return 0;
}
