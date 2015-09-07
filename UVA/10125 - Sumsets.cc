#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1000 + 10;
const int mod = 1 << 18;

int x[MAXN], head[mod], len;

struct data {
	int a, b, sum;
	int next;
} data[MAXN * MAXN];

inline int gethash(int x) {
	if (x < 0) x = -x;
	return x & (mod-1);
}

void insert(int a, int b, int sum) {
	int cur = gethash(sum);
	for (int i = head[cur]; i != -1; i = data[i].next) {
		if (data[i].sum == sum && data[i].a == a && data[i].b == b) return;
	}
	data[len].a = a;
	data[len].b = b;
	data[len].sum = sum;
	data[len].next = head[cur];
	head[cur] = len ++;
}

bool search(int a, int b, int sum) {
	int cur = gethash(sum);
	for (int i = head[cur]; i != -1; i = data[i].next) {
		if (data[i].sum != sum || data[i].a == a || data[i].a == b || data[i].b == a || data[i].b == b) continue;
		return true;
	}
	return false;
}

int main() {
	int n;
	while (scanf("%d",&n) == 1 && n) {
		len = 0;
		memset(head, -1, sizeof(head));
		for (int i = 0; i < n; ++ i) scanf("%d", &x[i]);
		for (int i = 0; i < n; ++ i)
			for (int j = i + 1;j < n; ++ j)	
				insert(i, j, x[i] + x[j]);
		bool ok = false;
		int ans = -999999999;
		for (int i = 0; i < n; ++ i) {		
			for (int j = 0; j < n; ++ j) {
				if (i == j) continue;
				if (search(i, j, x[i] - x[j])) {
					ok = true;
					ans = max(ans, x[i]);
					break;
				}
			}
		}
		if (ok) printf("%d\n", ans);
		else puts("no solution");
	}
	return 0;
}
