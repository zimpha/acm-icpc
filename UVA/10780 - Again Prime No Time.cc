#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

void prime_table(int n, vector <int> &plist) {
	vector <bool> vis(n + 1, 0); plist.clear();
	for (int i = 2; i <= n; ++ i) {
		if (!vis[i]) {
			plist.push_back(i);
			for (int j = i; j <= n; j += i) vis[j]=true;
		}
	}
}

int main() {
	vector <int> plist;
	prime_table(10000, plist);
	int T; scanf("%d", &T);
	for (int cas = 1; cas <= T; ++ cas) {
		int N, M; scanf("%d%d", &M, &N);
		vector <int> cnt(plist.size(), 0);
		for (int i = 0; i < (int)plist.size(); ++ i) {
			for (int j = plist[i]; N / j; j *= plist[i]) cnt[i] += N / j;
		}
		int ret = 1e9;
		for (int i = 0; i < (int)plist.size(); ++ i) {
			int s = 0;
			while (M % plist[i] == 0) {
				s ++;
				M /= plist[i];
			}
			if (s) ret = min(ret, cnt[i] / s);
		}
		printf("Case %d:\n", cas);
		if (ret == 0) puts("Impossible to divide");
		else printf("%d\n", ret);
	}
	return 0;
}
