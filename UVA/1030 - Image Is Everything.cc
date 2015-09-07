#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

#define REP(i,n) for (int i = 0; i < (n); ++ i)

const int MAXN = 10;
char pos[MAXN][MAXN][MAXN];
char view[6][MAXN][MAXN];
int n;

char get_char() {
	char  ch;
	while (1) {
		ch = getchar();
		if ((ch >= 'A' && ch <= 'Z') || ch == '.') break;
	}
}

void get(int k, int i, int j, int len, int &x, int &y, int &z) {
	if (k == 0) x = len, y = j, z = i;
	if (k == 1) x = n - 1 - j, y = len, z = i;
	if (k == 2) x = n - 1 - len, y = n - 1 - j, z = i;
	if (k == 3) x = j, y = n - 1 - len, z = i;
	if (k == 4) x = n - 1 - i, y = j, z = len;
	if (k == 5) x = i, y = j, z = n - 1 - len;
}

int main() {
	while (scanf("%d", &n) == 1 && n) {
		REP(i,n) REP(k,6) REP(j,n) view[k][i][j] = get_char();
		REP(i,n) REP(j,n) REP(k,n) pos[i][j][k] = '#';
		REP(k,6) REP(i,n) REP(j,n) if (view[k][i][j] == '.') {
			REP(p,n) {
				int x, y, z;
				get(k, i, j, p, x, y, z);
				pos[x][y][z] = '.';
			}
		}
		while (1) {
			bool flag = true;
			REP(k,6) REP(i,n) REP(j,n) if (view[k][i][j] != '.') {
				REP(p,n) {
					int x, y, z;
					get(k, i, j, p, x, y, z);
					if (pos[x][y][z] == '.') continue;
					if (pos[x][y][z] == '#') {
						pos[x][y][z] = view[k][i][j];
						break;
					}
					if (pos[x][y][z] == view[k][i][j]) break;
					pos[x][y][z] = '.';
					flag = false;
				}
			}
			if (flag) break;
		}
		int ret = 0;
		REP(i,n) REP(j,n) REP(k,n)
			if (pos[i][j][k] != '.') ret ++;
		printf("Maximum weight: %d gram(s)\n", ret);
	}
	return 0;
}
