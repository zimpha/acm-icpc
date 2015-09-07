#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char st[100];
int ans[20];

void getAns(vector <string> v, int x) {
	int deg = 0, cof = x;
	for (int i = 0; i < (int)v.size(); ++ i) {
		int l = v[i].size();
		if (v[i][0] == 'n') deg ++;
		else {
			int sum = 0;
			for (int j = 0; j < l; ++ j) sum = sum * 10 + v[i][j] - '0';
			cof *= sum;
		}
	}
	ans[deg] += cof;
}

void solve(vector <string> v) {
	while (1) {
		scanf("%s", st);
		if (st[0] == 'L') {
			scanf("%s", st);
			v.push_back(st);
			solve(v);
			v.pop_back();
		} else if (st[0] == 'O') {
			int x;
			scanf("%d", &x);
			getAns(v, x);
		} else if (st[0] == 'E') {
			return;
		}
	}
	return;
}

void output() {
	printf("Runtime = ");
	vector <int> cof, deg;
	cof.clear(); deg.clear();
	for (int i = 19; i >= 0; -- i) 
		if (ans[i]) {
			cof.push_back(ans[i]);
			deg.push_back(i);
		}
	for (int i = 0; i < (int)deg.size(); ++ i) {
		if (i) putchar('+');
		if (deg[i] == 0) {
			printf("%d", cof[i]);
			continue;
		}
		if (cof[i] != 1) printf("%d*", cof[i]);
		if (deg[i] == 1) printf("n");
		else if (deg[i] > 1) printf("n^%d", deg[i]);
	}
	if (!deg.size()) printf("0");
	puts(""); puts("");
}

int main() {
	int T; scanf("%d", &T);
	for (int cas = 1; cas <= T; ++ cas) {
		scanf("%s", st);
		memset(ans, 0, sizeof(ans));
		printf("Program #%d\n", cas);
		vector <string> v; v.clear();
		solve(v);
		output();
	}
	return 0;
}
