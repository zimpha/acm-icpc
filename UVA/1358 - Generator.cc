#include <queue>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef long long LL;

const int MAXL = 100;
const int C = 26;

LL mat[MAXL][MAXL];
int N;

struct automata {
	int go[MAXL][C], fail[MAXL], val[MAXL], id[MAXL];
	int sz;
	int New_Node() {
		memset(go[sz], 0, sizeof(go[sz]));
		val[sz] = 0; fail[sz] = 0; return sz ++;
	}
	void init() {
		sz = 0; New_Node();
	}
	void insert(char s[]) {
		int now = 0;
		for (int i = 0, o; s[i]; ++ i, now = go[now][o]) {
			o = s[i] - 'A';
			if (go[now][o] == 0) go[now][o] = New_Node();
		}
		val[now] = 1;
	}
	void get_fail() {
		queue <int> q; while (!q.empty()) q.pop();
		q.push(0);
		while (!q.empty()) {
			int x = q.front(); q.pop();
			for (int i = 0; i < N; ++ i) {
				int y = go[x][i];
				if (!y) go[x][i] = go[fail[x]][i];
				else q.push(y);
				if (x && y) {
					fail[y] = go[fail[x]][i];
					val[y] |= val[fail[y]];
				}
			}
		}
	}
	void get_matrix(int &n) {
		memset(id, 0, sizeof(id)); n = 0;
		for (int i = 0; i < sz; ++ i) {
			if (!val[i]) id[i] = n ++;
		}
		memset(mat, 0, sizeof(mat));
		for (int i = 0; i < sz; ++ i) {
			if (val[i]) continue;
			mat[id[i]][n] = -N;
			mat[id[i]][id[i]] = -N;
			for (int j = 0; j < N; ++ j) {
				int k = go[i][j];
				if (val[k]) continue;
				mat[id[i]][id[k]] += 1;
			}
		}
	}
};

LL gcd(LL a, LL b) {
	return b ? gcd(b, a % b) : a;
}

void gauss(int n) {
	for (int r = 0; r < n; ++ r) {
		int id = r;
		for (int i = r; i < n; ++ i) {
			if (abs(mat[id][r]) > abs(mat[i][r]) && mat[i][r]) id = i;
		}
		for (int i = 0; i <= n; ++ i) swap(mat[r][i], mat[id][i]);
		for (int i = r + 1; i < n; ++ i) {
			if (mat[i][r] != 0) {
				LL g = gcd(abs(mat[i][r]), abs(mat[r][r]));
				LL lcm = mat[i][r] * mat[r][r] / g;
				LL l1 = lcm / mat[i][r], l2 = lcm / mat[r][r];
				for (int j = r; j <= n; ++ j) 
					mat[i][j] = mat[i][j] * l1 - mat[r][j] * l2;
			}
		}
	}
	for (int i = n - 1; i >= 0; -- i) {
		for (int j = i + 1; j < n; ++ j) {
			mat[i][n] -= mat[i][j] * mat[j][j];
		}
		mat[i][i] = mat[i][n] / mat[i][i];
	}
}

int main() {
	int T, n;
	scanf("%d", &T);
	for (int cas = 1; cas <= T; ++ cas) {
		char st[100];
		scanf("%d%s", &N, st);
		automata AC;
		AC.init();
		AC.insert(st);
		AC.get_fail();
		AC.get_matrix(n);
		gauss(n);
		printf("Case %d:\n%lld\n", cas, mat[0][0]);
		if (cas < T) puts("");
	}
	return 0;
}
