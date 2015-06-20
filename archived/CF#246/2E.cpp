#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 200;
char A[MAXN][MAXN];
int N, M;

char get(int x, int y) {
	if (A[x][y]) return A[x][y];
	char ret = 'A';
	while (ret == A[x - 1][y] || ret == A[x][y - 1] || ret == A[x + 1][y] || ret == A[x][y + 1]) ret ++;
	return ret;
}

int main() {
	cin >> N >> M;
	memset(A, 0, sizeof(A));
	for (int x = 1; x <= N; ++ x) {
		for (int y = 1; y <= M; ++ y) {
			char now = get(x, y);
			cout << now;
			if (A[x][y]) continue;
			int len = 1;
			while (x + len <= N && y + len <= M && get(x, y + len) == now) len ++;
			for (int i = 0; i < len; ++ i)
				for (int j = 0; j < len; ++ j)
					A[x + i][y + j] = now;
		}
		cout << endl;
	}
}
