#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 500010;

int Count[MAXN], t_rank[MAXN][2], t_sa[MAXN];
int rank[MAXN], sa[MAXN], height[MAXN];
int mx[MAXN][20], log2[MAXN];
char s1[MAXN], s[MAXN];

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

inline int rmq(int a, int b) {
	int k = log2[b - a + 1];
	return min(mx[a][k], mx[b - (1 << k) + 1][k]);
}

inline int lcp(int a, int b) {
	a = rank[a], b = rank[b];
	//if (a == b) return len - a + 1;
	if (a > b) swap(a, b);
	return rmq(a + 1, b);
}

int len[MAXN];

int main() {
	scanf("%s%s", s, s1);
	int M = strlen(s), N = strlen(s1);
	s[M] = '$';
	for (int i = 0; i <= N; ++ i) s[M + 1 + i] = s1[i];
	N += 1 + M;
	construct(s, N, 1000);
	get_height(s, N);
	rmq_init(N);
	for (int i = 0, tmp = -1; i < N; ++ i) {
		if (sa[i] == M) continue;
		if (sa[i] < M) tmp = i;
		else {
			if (tmp == -1) continue;
			len[sa[i]] = lcp(sa[tmp], sa[i]);
		}
	}

	for (int i = N - 1, tmp = -1; i >= 0; -- i) {
		if (sa[i] == M) continue;
		if (sa[i] < M) tmp = i;
		else {
			if (tmp == -1) continue;
			len[sa[i]] = max(len[sa[i]], lcp(sa[i], sa[tmp]));
		}
	}
	int mx = 0;
	for (int i = M + 1; i < N; ++ i) mx = max(mx, len[i]);
	if (mx == 0) puts("0");
	else {
		for (int i = M + 1; i < N; ++ i)
			if (mx == len[i]) {
				for (int j = i; j < i + mx; ++ j) putchar(s[j]);
				break;
			}
		printf("\n%d\n", mx);
	}
	return 0;
}

