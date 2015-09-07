#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 10000 + 10;

bool hash[MAXN];
int A[MAXN];

inline bool check(int n) {
	for (int i = 0; i < n; ++ i) {
		fill(hash, hash + n, 0);
		for (int j = i + 1; j < n; ++ j) hash[A[j]] = 1;
		for (int j = i + 1; j < n; ++ j) {
			hash[A[j]] = 0;
			int tt = 2 * A[j] - A[i];
			if (tt < 0 || tt >= n) continue;
			if (hash[tt]) return false;
		}
	}
	return true;
}

int main() {
	int n;
	while (scanf("%d:", &n) == 1 && n) {
		for (int i = 0; i < n; ++ i) scanf("%d", &A[i]);
		if (check(n)) puts("yes");
		else puts("no");
	}
	return 0;
}
