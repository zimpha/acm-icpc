#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int SIZE = 10250;

int num[16], st[16], Sum[(1<<16)];
vector<int> sum[SIZE];

bool judge(int state) {
	int sn = 0;
	for (int i = 0; i < 16; ++ i) {
		if (state & (1 << i))
			st[sn ++] = num[i];
	}
	return (sn == 4);
}

int solve() {
	int ans = 0;
	for (int i = 0; i < SIZE; ++ i) sum[i].clear();
	memset(Sum, 0, sizeof(Sum));
	sort(num, num + 16);
	for (int i = 0; i < (1 << 16); ++ i) {
		if (judge(i)) {
			do {
				int s = st[0] * 4 + st[1] * 3 + st[2] * 2 + st[3];
				for (size_t j = 0; j < sum[s].size(); ++ j) {
					if ((i & sum[s][j]) == 0)
						Sum[i | sum[s][j]] ++;
				}
				sum[s].push_back(i);
			} while(next_permutation(st, st + 4));
		}
	}
	for (int k = 0; k < (1 << 16); ++ k)
		ans += Sum[k] * Sum[k ^ ((1 << 16) - 1)];
	return ans >> 1;
}

int main() {
	int cas = 0;
	while (scanf("%d", &num[0]) == 1 && num[0]) {
		for (int i = 1; i < 16; ++ i) scanf("%d", &num[i]);
		printf("Case %d: %d\n", ++cas, solve());
	}
	return 0;
}
