#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN=200+10;
const int inf=1e9;

struct node {
	int u, v, w;
	node(){}
	node(int _u, int _v, int _w):u(_u), v(_v), w(_w){}
};

vector<node> ans;
int cap[MAXN][MAXN];
int n;

bool dfs(vector<int> &v) {
	int cut=inf, sz=v.size();
	if (sz<=1) return true;
	for (int i=0; i<sz; i++) 
		for (int j=i+1; j<sz; j++)
			if (cap[v[i]][v[j]]<cut) cut=cap[v[i]][v[j]];
	vector<int> left, right; left.clear(); right.clear();
	left.push_back(v[0]);
	for (int i=1; i<sz; i++)
		if (cap[v[0]][v[i]]>cut) left.push_back(v[i]);
		else right.push_back(v[i]);
	if (left.empty()||right.empty()) return false;
	for (int i=0; i<(int)left.size(); i++)
		for (int j=0; j<(int)right.size(); j++)
			if (cap[left[i]][right[j]]!=cut) return false;
	if (cut) ans.push_back(node(left[0], right[0], cut));
	return dfs(left)&&dfs(right);
}

int main() {
	int T; scanf("%d", &T);
	for (int cas=1; cas<=T; cas++) {
		scanf("%d", &n);
		vector<int> v;
		for (int i=0; i<n; i++) 
			for (int j=0; j<n; j++)
				scanf("%d", &cap[i][j]);
		printf("Case #%d: ", cas);
		ans.clear();
		for (int i=0; i<n; i++) v.push_back(i);
		if (dfs(v)) {
			printf("%d\n", (int)ans.size());
			for (int i=0; i<(int)ans.size(); i++)
				printf("%d %d %d\n", ans[i].u, ans[i].v, ans[i].w);
		}
		else puts("Impossible");
	}
	return 0;
}
