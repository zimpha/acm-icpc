#include <cstdio>
#include <cstring>
#include <cassert>

const char digit[][3][5] = {
	{"\\ / ", " |  ", "/o\\ "},
	{" o  ", "/|\\ ", "/ \\ "},
	{"    ", "    ", "__\\o"},
	{"    ", "    ", "\\_\\o"},
	{"_o_ ", " |  ", "/ \\ "},
	{"\\o/ ", " |  ", "/ \\ "},
	{"\\o_ ", "\\|  ", " |  "},
	{"\\o/ ", "\\|/ ", "    "},
	{"    ", " __o", "/  |"},
	{" o  ", "( ) ", "/ \\ "}
};

char st[100];
char map[3][10000];

int main() {
	int T; scanf("%d", &T);
	while (T --) {
		scanf("%s", st);
		int N = strlen(st), c = 0;
		for (int i = 0; i < N; ++ i) {
			int d = st[i] - '0';
			if (i) map[0][c] = map[1][c] = map[2][c] = ' ', c ++;
			for (int x = 0; x < 3; ++ x) {
				for (int y = 0; y < 4; ++ y) {
					map[x][c + y] = digit[d][x][y];
				}
			}
			c += 4;
		}
		map[0][c] = map[1][c] = map[2][c] = '\0';
		assert(strlen(map[0]) == 5 * N - 1);
		assert(strlen(map[1]) == 5 * N - 1);
		assert(strlen(map[2]) == 5 * N - 1);
		puts(map[0]);
		puts(map[1]);
		puts(map[2]);
		puts("");
	}
	return 0;
}
