#include <vector>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1000 + 10;

int Count[MAXN], t_rank[MAXN][2], t_sa[MAXN];
int rank[MAXN], sa[MAXN], height[MAXN];
char st[MAXN];

void construct(char* string, int n, int m = 256) {
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

int main() {
	while (gets(st)) {
		if (strlen(st) == 0) break;
		int n = strlen(st), m = 0;
		for (int i = 0; i < n; ++ i) 
			if (isupper(st[i])) st[m ++] = st[i];
		n = m; construct(st, n);
		get_height(st, n);
		for (int len = 1; len < n; ++ len) {
			int cnt = 0;
			vector <int> ret; ret.clear();
			for (int i = 1; i < n; ++ i) {
				if (height[i] >= len) cnt ++;
				else {
					ret.push_back(cnt + 1);
					cnt = 0;
				}
			}
			ret.push_back(cnt + 1);
			sort(ret.begin(), ret.end());
			if (ret.back() > 1) printf("%d\n", ret.back());
			else break;
		}
		puts("");
	}
	return 0;
}
