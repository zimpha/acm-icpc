#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXN = 400010;

int cnt[MAXN], rank[MAXN], sa[MAXN];
int t_rank[MAXN][2], t_sa[MAXN];
int height[MAXN];
char s[MAXN];

void construct(char s[], int n, int m) {
	fill(cnt, cnt + m + 1, 0);
	for (int i = 0; i < n; ++ i) cnt[s[i] - 'a'] ++;
	for (int i = 0; i < m; ++ i) cnt[i + 1] += cnt[i];
	for (int i = 0; i < n; ++ i) rank[i] = cnt[s[i] - 'a'] - 1;
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

bool check(int n, int L, int m) {
	for (int i = 1, j; i < n; ) {
		if (height[i] >= L) {
			for (j = i; j < n && height[j] >= L; ++ j);
			if (j - i + 1 >= m) return true; i = j;
		} else ++ i;
	}
	return false;
}

int main() {
	int n, m;
	while (scanf("%d", &m) == 1 && m) {
		scanf("%s", s); n = strlen(s);
		if (m == 1) {
			printf("%d %d\n", n, 0);
			continue;
		}
		construct(s, n, 30);
		int left = 0, right = n, ans = 0, pos;
		while (left <= right) {
			int mid = (left + right) >> 1;
			if (check(n, mid, m)) {
				left = mid + 1;
				ans = mid;
			} else {
				right = mid - 1;
			}
		}
		if (ans == 0) {
			puts("none");
		} else {
			pos = 0;
			for (int i = 1, j; i < n; ) {
				if (height[i] >= ans) {
					for (j = i; j < n && height[j] >= ans; ++ j);
					if (j - i + 1 >= m) {
						for (int k = i - 1; k < j; ++ k) {
							pos = max(pos, sa[k]);
						}
					}
					i = j;
				}
				else i ++;
			}
			printf("%d %d\n", ans, pos);
		}
	}
	return 0;
}
