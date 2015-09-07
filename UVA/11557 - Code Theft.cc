#include <map>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
typedef unsigned long long ULL;
const int SIZE = 1000000 + 10;
const int MAXN = 100 + 10;

std :: map <ULL, int> Table;
int Count[SIZE], t_rank[SIZE][2], t_sa[SIZE];
int rank[SIZE], sa[SIZE], height[SIZE];
int prev[SIZE], next[SIZE], loc[SIZE];
int mx[SIZE][20], LOG2[SIZE];
int string[SIZE];
char name[MAXN][300];
int N, M, NS, len;

void construct(int* string, int n, int m) {
	memset(Count, 0, sizeof(Count));
	for (int i = 0; i < n; ++ i) Count[string[i]] ++;
	for (int i = 0; i < m; ++ i) Count[i + 1] += Count[i];
	for (int i = 0; i < n; ++ i) rank[i] = Count[string[i]] - 1;
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
}

void get_height(int* string, int n) {
	for (int i = 0, len = 0; i < n; ++ i) {
		if (!rank[i]) continue;
		int j = sa[rank[i] - 1];
		while (i + len < n && j + len < n && string[i + len] == string[j + len]) len++;
		height[rank[i]] = len;
		if (len) len--;
	}
}

void rmq_init(int n) {
	for (int i = 0; i < n; ++ i) mx[i][0] = height[i];
	for (int j = 1; (1 << j) < n; ++ j) {
		for (int i = 0; i + (1 << j) <= n; ++ i)
			mx[i][j] = std :: min(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);
	}
	LOG2[0] = -1;
	for (int i = 1; i < n; ++ i) LOG2[i] = LOG2[i >> 1] + 1;
}

inline int rmq(int a, int b) {
	int k = LOG2[b - a + 1];
	return std :: min(mx[a][k], mx[b - (1 << k) + 1][k]);
}

inline ULL get_hash(char st[], int n) {
	ULL ret = 0;
	for (int i = 0; i < n; ++ i) ret = ret * 1003 + st[i];
	return ret;
}

inline bool isEmpty(char st[], int n) {
	for (int i = 0; i < n; ++ i) 
		if (st[i] != ' ') return false;
	return true;
}

inline void dealSpaces(char st[], int n) {
	int i, m = 0;
	for (i = 0; st[i] == ' '; ++ i);
	for ( ; i < n; ++ i) {
		if (st[i] != ' ') st[m ++] = st[i];
		else {
			if (st[i - 1] == ' ') continue;
			else st[m ++] = st[i];
		}
	}
	if (st[m - 1] == ' ') m --; st[m] = '\0';
}

inline int get_len(int pos) {
	if (prev[pos] == -1) {
		if (next[pos] == -1) return 0;
		else return rmq(pos + 1, next[pos]);
	} else {
		if (next[pos] == -1) return rmq(prev[pos] + 1, pos);
		else return std :: max(rmq(prev[pos] + 1, pos), rmq(pos + 1, next[pos]));
	}
}

int common[MAXN];

void solve() {
	memset(prev, -1, sizeof(prev));
	for (int i = 0, last = -1; i < len; ++ i) {
		if (loc[sa[i]] == -1) continue;
		if (sa[i] >= NS) last = i;
		if (sa[i] < NS) prev[i] = last;
	}
	memset(next, -1, sizeof(next));
	for (int i = len - 1, last = -1; i >= 0; -- i) {
		if (loc[i] == -1) continue;
		if (sa[i] >= NS) last = i;
		if (sa[i] < NS) next[i] = last;
	}
	memset(common, 0, sizeof(common));
	int ret = 0;
	for (int i = 0; i < NS; ++ i) {
		if (loc[i] == -1) continue;
		int maxlen = get_len(rank[i]);
		common[loc[i]] = std :: max(maxlen, common[loc[i]]);
		ret = std :: max(ret, maxlen);
	}
	std :: vector <int> ans; ans.clear();
	for (int i = 0; i < N; ++ i) 
		if (common[i] == ret) ans.push_back(i);
	printf("%d", ret);
	if (ret != 0) {
		for (int i = 0; i < (int)ans.size(); ++ i) {
			printf(" %s", name[ans[i]]);
		}
	}
	puts("");
}

int main() {
	static char tmp[SIZE];
	while (scanf("%d", &N) == 1) {
		Table.clear(); len = M = 0;
		getchar();
		memset(loc, -1, sizeof(loc));
		for (int i = 0; i < N; ++ i) {
			gets(name[i]);
			while (gets(tmp)) {
				if (strcmp(tmp, "***END***") == 0) break;
				if (isEmpty(tmp, strlen(tmp))) continue;
				dealSpaces(tmp, strlen(tmp));
				ULL tt = get_hash(tmp, strlen(tmp));
				if (Table.find(tt) == Table.end()) Table[tt] = M ++;
				loc[len] = i; string[len ++] = Table[tt];
			}
			loc[len] = -1; string[len ++] = M ++;
		}
		NS = len;
		while (gets(tmp)) {
			if (strcmp(tmp, "***END***") == 0) break;
			if (isEmpty(tmp, strlen(tmp))) continue;
			dealSpaces(tmp, strlen(tmp));
			ULL tt = get_hash(tmp, strlen(tmp));
			if (Table.find(tt) == Table.end()) Table[tt] = M ++;
			loc[len] = N; string[len ++] = Table[tt];
		}
		construct(string, len, M + 1);
		get_height(string, len);
		rmq_init(len);
		solve();
	}
	return 0;
}
