#include <set>
#include <string>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

set<string> S;
char state[32][10];
int cnt[32], rev[32];
int a[10], ret;

inline void get_reverse() {
	memset(rev, 0, sizeof(rev));
	for (int i = 0; i < 32; ++ i) {
		for (int j = 0, n = i; j < 5; ++ j, n >>= 1) {
			rev[i] = rev[i] * 2 + (n & 1);
			state[i][4 - j] = '0' + (n & 1);
		}
		state[i][5] = '\0';
	}
}

inline void change(char s[]) {
	int ret = 0;
	for (int i = 0; i < 5; ++ i) {
		ret = ret * 2 + s[i] - '0';
	}
	cnt[ret] ++; cnt[rev[ret]] ++;
}

inline bool check() {
	int tc[32]; memset(tc, 0, sizeof(tc));
	for (int i = 0; i < 5; ++ i) {
		int n = 0;
		for (int j = 0; j < 5; ++ j) n = n * 2 + (a[j] & (1 << i) ? 0 : 1);
		tc[n] ++; tc[rev[n]] ++;
		if (tc[n] > cnt[n]) return false;
	}
	string st = "";
	for (int i = 0; i < 5; ++ i) st = st + (string)state[a[i]];
	return !S.count(st);
}

inline void rotate(char x[10][10]) {
	char y[10][10];
	for (int i = 0; i < 5; ++ i) strcpy(y[i], x[i]);
	for (int i = 0; i < 5; ++ i)
		for (int j = 0; j < 5; ++ j) x[i][j] = y[j][4 - i];
}

inline void mirror(char x[10][10]) {
	char y[10][10];
	for (int i = 0; i < 5; ++ i) strcpy(y[i], x[i]);
	for (int i = 0; i < 5; ++ i)
		for (int j = 0; j < 5; ++ j) x[i][j] = y[4 - i][j];
}

inline void Insert(char x[10][10]) {
	string st = "";
	for (int i = 0; i < 5; ++ i) st = st + (string)x[i];
	S.insert(st);
}

inline void add() {
	char x[10][10]; ret ++;
	for (int i = 0; i < 5; ++ i) strcpy(x[i], state[a[i]]);
	for (int i = 0; i < 2; ++ i) {
		mirror(x);
		for (int j = 0; j < 4; ++ j) {
			rotate(x);
			Insert(x);
		}
	}
}

void dfs(int dep) {
	if (dep == 5) {
		if (check()) add();
		return;
	}
	for (int i = 0; i < 32; ++ i) {
		if (cnt[i] == 0) continue;
		cnt[i] --; cnt[rev[i]] --; a[dep] = i;
		dfs(dep + 1);
		cnt[i] ++; cnt[rev[i]] ++;
	}
}

int main() {
	char st[10];
	get_reverse();
	while (scanf("%s", st) == 1 && st[0] != 'E') {
		memset(cnt, 0, sizeof(cnt)); S.clear(); ret = 0;
		change(st);
		for (int i = 1; i < 10; ++ i) {
			scanf("%s", st); change(st);
		}
		dfs(0);
		printf("%d\n", ret >> 1);
	}
	return 0;
}
