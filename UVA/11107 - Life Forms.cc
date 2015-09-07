#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXN = 200010;
const int SIZE = 1010;

int cnt[MAXN], rank[MAXN], sa[MAXN];
int t_rank[MAXN][2], t_sa[MAXN];
int s[MAXN], bel[MAXN];
int height[MAXN];
int n, m;

void construct(int s[], int n, int m) {
	fill(cnt, cnt + m + 1, 0);
	for (int i = 0; i < n; ++ i) cnt[s[i]] ++;
	for (int i = 0; i < m; ++ i) cnt[i + 1] += cnt[i];
	for (int i = 0; i < n; ++ i) rank[i] = cnt[s[i]] - 1;
	for (int len = 1; len < n; len <<= 1) {
		for (int i = 0; i < n; ++ i) {
			t_rank[i][0] = rank[i];
			t_rank[i][1] = i + len < n ? rank[i + len] + 1 : 0;
		}
		fill(cnt, cnt + n + 1, 0);
		for (int i = 0; i < n; ++ i) cnt[t_rank[i][1]] ++;
		for (int i = 0; i < n; ++ i) cnt[i + 1] += cnt[i];
		for (int i = n - 1; i >= 0; -- i) t_sa[-- cnt[t_rank[i][1]]] = i;
		fill(cnt, cnt + n + 1, 0);
		for (int i = 0; i < n; ++ i) cnt[t_rank[i][0]] ++;
		for (int i = 0; i < n; ++ i) cnt[i + 1] += cnt[i];
		for (int i = n - 1; i >= 0; -- i) sa[-- cnt[t_rank[t_sa[i]][0]]] = t_sa[i];
		rank[sa[0]] = 0;
		for (int i = 0; i + 1 < n; ++ i) {
			rank[sa[i + 1]] = rank[sa[i]] + (t_rank[sa[i]][0] != t_rank[sa[i + 1]][0] || t_rank[sa[i]][1] != t_rank[sa[i + 1]][1]);	
		}
	}
	for (int i = 0, len = 0; i < n; ++ i) {
		if (rank[i] == 0) continue;
		int j = sa[rank[i] - 1];
		while (i + len < n && j + len < n && s[i + len] == s[j + len]) len ++;
		height[rank[i]] = len;
		if (len) len --;
	}
}

bool check(int n, int L, int tot, bool f) {
	static int flag[SIZE], stk[SIZE];
	fill(flag, flag + tot, 0);
	int ret = 0, top = 0; 
	for (int i = 1; i < n; ++ i) {
		if (height[i] >= L) {
			if (flag[bel[sa[i]]] == false) {
				flag[bel[sa[i]]] = true;
				stk[top ++] = bel[sa[i]];
				ret ++;
			}
			if (flag[bel[sa[i - 1]]] == false) {
				flag[bel[sa[i - 1]]] = true;
				stk[top ++] = bel[sa[i - 1]];
				ret ++;
			}
		}
		else {
			if (ret > tot / 2) {
				if (f) {
					return true;
				} else {
					for (int j = 0; j < L; ++ j) {
						putchar(s[sa[i - 1] + j] + 'a');
					}
					puts("");
				}
			}
			while (top --) {
				flag[stk[top]] = false;
			}
			top = ret = 0;
		}
	}
	return false;
}

int main() {
	char st[SIZE];
	int n, m, left, right, cas = 0;
	while (scanf("%d", &m) == 1 && m) {
		if (cas) puts(""); cas ++;
		n = right = 0;
		for (int i = 0; i < m; ++ i) {
			scanf("%s", st);
			right = max(right, (int)strlen(st));
			for (int j = 0; st[j]; ++ j) {
				s[n ++] = st[j] - 'a';
				bel[n - 1] = i;
			}
			s[n ++] = i + 26; bel[n - 1] = i;
		}
		if (m == 1) {
			puts(st);
			continue;
		}
		construct(s, n, m + 26);
		left = 0;
		int ret = 0;
		while (left <= right) {
			int mid = (left + right) >> 1;
			if (check(n, mid, m, 1)) {
				left = mid + 1;
				ret = mid;
			} else {
				right = mid - 1;
			}
		}
		if (ret == 0) {
			puts("?");
		} else {
			check(n, ret, m, 0);
		}
	}
	return 0;
}
