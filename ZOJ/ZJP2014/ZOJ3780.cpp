#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>

using namespace std;

const int MAXN = 1000 + 10;

char x[MAXN][MAXN];
vector<int> edge[MAXN];
int now[MAXN], deg[1200], ans[MAXN], n;

int main() {
	int T; scanf("%d",&T);
	while (T --) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++ i) scanf("%s", x[i]);
		for (int i = 0; i < n + n; ++ i) edge[i].clear();
		memset(now, 0, sizeof(now));
		memset(deg, 0, sizeof(deg));
		int tot = 0, cnt = 0;
		for (int i = 0; i < n; ++ i) {
			bool flag = false;
			for (int j = 0; j < n; ++ j) 
				if (x[j][i] == 'O') {flag = true; break;}
			if (flag) {
				tot ++; now[i] = 1;
				for (int j = 0; j < n; ++ j) 
					if (x[j][i] == 'X') {
						edge[i].push_back(n + j);
						deg[n + j]++;
					}
			}
		}
		
		for(int i = 0; i < n; ++ i) {
			bool flag = false;
			for (int j = 0; j < n; ++ j) 
				if (x[i][j] == 'X') {flag = true; break;}
			if (flag) {
				now[n + i] = 1; tot ++;
				for (int j = 0;j < n; ++ j) 
					if (x[i][j] == 'O'){
						edge[n + i].push_back(j);
						deg[j] ++;
					}
			}
		}
		priority_queue<int, vector<int>, greater<int> > Q;
		for (int i = 0; i < n + n; ++ i) 
			if (now[i] && deg[i] == 0) Q.push(i);
		while (!Q.empty()) {
			int x = Q.top(); Q.pop();
			ans[cnt ++] = x;
			for (int i = edge[x].size() - 1; i >= 0; -- i) {
				int y = edge[x][i]; deg[y]--;
				if (deg[y] == 0) Q.push(y);
			}
		}
		if (cnt < tot) puts("No solution"); 
		else {
			for(int i = 0; i < tot; ++ i) {
				if (i) putchar(' ');
				if (ans[i] >= n) printf("R%d", ans[i] - n + 1);
				else printf("C%d", ans[i] + 1);
			}
			puts("");
		}
	}
	return 0;
}
