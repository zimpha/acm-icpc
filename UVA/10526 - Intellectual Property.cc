#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 200010;

struct Node {
	int len, pos;
} ret[MAXN];

int Count[MAXN], t_rank[MAXN][2], t_sa[MAXN];
int rank[MAXN], sa[MAXN], height[MAXN];
int mx[MAXN][20], log2[MAXN];
int prev[MAXN], next[MAXN];
char st[MAXN], tmp[MAXN];
int N, M, K;

void construct(char* string, int n, int m) {
	memset(Count, 0, sizeof(Count));
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
}

void get_height(char* string, int n) {
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
			mx[i][j] = min(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);
	}
	log2[0] = -1;
	for (int i = 1; i < n; ++ i) log2[i] = log2[i >> 1] + 1;
}

int lcp(int a, int b) {
	int k = log2[b - a + 1];
	return min(mx[a][k], mx[b - (1 << k) + 1][k]);
}

void initial() {
	construct(st, N, 1000);
	get_height(st, N);
	rmq_init(N);
	for (int i = 0, last = -1; i < N; ++ i) {
		if (st[sa[i]] == '$') continue;
		if (sa[i] < M) last = i;
		if (sa[i] > M) prev[i] = last;
	}
	for (int i = N - 1, last = -1; i >= 0; -- i) {
		if (st[sa[i]] == '$') continue;
		if (sa[i] < M) last = i;
		if (sa[i] > M) next[i] = last;
	}
}

int get_len(int pos) {
	if (prev[pos] == -1) {
		if (next[pos] == -1) return 0;
		else return lcp(pos + 1, next[pos]);
	} else {
		if (next[pos] == -1) return lcp(prev[pos] + 1, pos);
		else return max(lcp(prev[pos] + 1, pos), lcp(pos + 1, next[pos]));
	}
}

bool cmp1(const Node &a, const Node &b) {
	if (a.pos == b.pos) return (a.pos + a.len < b.pos + b.len);
	else return a.pos < b.pos;
}

bool cmp2(const Node &a, const Node &b) {
	if (a.len == b.len) return a.pos < b.pos;
	else return a.len > b.len;
}

void solve() {
	int cnt = 0;
	for (int i = M + 1; i < N; ++ i) {
		int len = get_len(rank[i]);
		if (len) ret[cnt ++] = (Node){len, i};
	}
	sort(ret, ret + cnt, cmp1);
	int tmp = 1, mx = ret[0].pos + ret[0].len - 1;
	for (int i = 1; i < cnt; ++ i) {
		if (mx < ret[i].pos + ret[i].len - 1) {
			mx = ret[i].pos + ret[i].len - 1;
			ret[tmp ++] = ret[i];
		}
	}
	cnt = tmp; sort(ret, ret + cnt, cmp2);
	for (int i = 0; i < cnt && i < K; ++ i) {
		int len = ret[i].len, pos = ret[i].pos;
		printf("INFRINGING SEGMENT %d LENGTH %d POSITION %d\n", i + 1, len, pos - M - 1);
		for (int j = pos; j < len + pos; ++ j) putchar(st[j]);
		puts("");
	}
}

int main() {
	int cas = 0;
	while (scanf("%d", &K) == 1 && K) {
		getchar();
		N = 0;
		gets(tmp);
		while (gets(tmp)) {
			if (strcmp(tmp, "END TDP CODEBASE") == 0) break;
			int t = strlen(tmp);
			for (int i = 0; i < t; ++ i) st[N ++] = tmp[i];
			st[N ++] = '\n';
		}
		M = N; st[N ++] = '$';
		gets(tmp);
		while (gets(tmp)) {
			if (strcmp(tmp, "END JCN CODEBASE") == 0) break;
			int t = strlen(tmp);
			for (int i = 0; i < t; ++ i) st[N ++] = tmp[i];
			st[N ++] = '\n';
		}
		initial();
		if (cas) puts("");
		printf("CASE %d\n", ++ cas);
		solve();
	}
	return 0;
}
