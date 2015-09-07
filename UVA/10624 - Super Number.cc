#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

char ret[100];
int N, M;

inline bool check(int p) {
	int res = 0;
	for (int i = 0; i < p; ++ i) {
		res = res * 10 + ret[i] - '0';
		res %= p;
	}
	return res;
}

bool solve(int dep) {
	if (dep >= M) return true;
	for (char i = '0'; i <= '9'; ++ i) {
		ret[dep] = i;
		if (ret[0] != '0') {
			if (dep + 1 < N || (dep + 1 >= N && !check(dep + 1))) 
				if (solve(dep + 1)) return true;
		}
	}
	return false;
}

int main() {
	int T; scanf("%d", &T);
	for (int cas = 1; cas <= T; ++ cas) {
		scanf("%d%d", &N, &M); ret[M] = '\0';
		printf("Case %d: ", cas);
		if (solve(0)) puts(ret);
		else puts("-1");
	}
	return 0;
}
