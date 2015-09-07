#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN=100005;

char str[MAXN];

int min_index(char *str) {
	int i = 0, j = 1, k, n = strlen(str);
	char ci, cj;
	while (1) {
		for (k = 0; k < n; ++ k) {
			ci = str[(i + k) % n];
			cj = str[(j + k) % n];
			if (ci != cj) break;
		}
		if (k == n) break;
		if (ci > cj) {
			i += k + 1;
			if (i == j) i ++;
		} else {
			j += k + 1;
			if (i == j) j ++;
		}
	}
	return min(i, j);
}


int main() {
	int T;
	scanf("%d", &T);
	while (T --) {
		scanf("%s", str);
		printf("%d\n", min_index(str) + 1);
	}
	return 0;
}
