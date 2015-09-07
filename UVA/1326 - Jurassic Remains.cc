#include <map>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXN = 30;

map<int, int> mp;

int A[MAXN];

inline int popcount(int x) {
	return __builtin_popcount(x);
}

int main() {
	int n;
	while (scanf("%d", &n) == 1) {
		for (int i = 0; i < n; ++ i) {
			static char st[10000];
			scanf("%s", st);
			A[i] = 0;
			for (int j = 0; st[j]; ++ j) {
				A[i] ^= 1 << (st[j] - 'A');
			}
		}
		mp.clear();
		int n1 = n / 2, n2 = n - n1;
		for (int mask = 0; mask < (1 << n1); ++ mask) {
			int x = 0;
			for (int i = 0; i < n1; ++ i) {
				if (mask & (1 << i)) x ^= A[i];
			}
			if (!mp.count(x) || popcount(mp[x]) < popcount(mask)) {
				mp[x] = mask;
			}
		}
		int ret = 0;
		for (int mask = 0; mask < (1 << n2); ++ mask) {
			int x = 0;
			for (int i = 0; i < n2; ++ i) {
				if (mask & (1 << i)) x ^= A[i + n1];
			}
			if (mp.count(x) && popcount(ret) < popcount(mp[x]) + popcount(mask)) {
				ret = (mask << n1) ^ mp[x];
			}
		}
		printf("%d\n", popcount(ret));
		for (int i = 0, first = 1; i < n; ++ i) {
			if (ret & (1 << i)) {
				if (!first) putchar(' ');
				else first = 0;
				printf("%d", i + 1);
			}
		}
		puts("");
	}
	return 0;
}
