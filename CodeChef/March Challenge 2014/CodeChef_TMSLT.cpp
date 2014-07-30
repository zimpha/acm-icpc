#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int SIZE = 1000000 + 10;
const int MAXN = 3000000 + 10;
const int MOD = 1000000;

struct Node {
	int val, cnt;
	bool operator < (const Node &rhs) const {
		return val > rhs.val;
	}
};

Node A[SIZE];
int cnt[SIZE], stk[SIZE], top;

int main() {
	int T; scanf("%d", &T);
	memset(cnt, -1, sizeof(cnt));
	while (T --) {
		int N, a, b, c, d;
		scanf("%d%d%d%d%d", &N, &a, &b, &c, &d);
		cnt[d] = 0; top = 1; stk[0] = d;
		for (int i = 1; i < N; ++ i) {
			d = ((long long)a * d * d % MOD + b * d + c) % MOD;
			stk[top ++] = d;
			if (cnt[d] != -1) {
				top --;
				break;
			}
			cnt[d] = i;
		}
		int st = cnt[d], len = top - st;
		for (int i = 0; i < st; ++ i) {
			A[i].val = stk[i]; cnt[stk[i]] = -1;
			A[i].cnt = 1;
		}
		N -= st;
		for (int i = st; i < top; ++ i) {
			A[i].val = stk[i]; cnt[stk[i]] = -1;
			A[i].cnt = N / len + ((i - st) < N % len);
		}
		sort(A, A + top);
		long long c1 = 0, c2 = 0;
		N = 0;
		for (int i = 0; i < top; ++ i) {
			int d1, d2;
			d1 = d2 = A[i].cnt >> 1;
			if (A[i].cnt & 1) {
				if (N & 1) d1 ++;
				else d2 ++;
			}
			c1 += (long long)A[i].val * d1;
			c2 += (long long)A[i].val * d2;
			N += A[i].cnt;
		}
		if (c1 > c2) printf("%lld\n", c1 - c2);
		else printf("%lld\n", c2 - c1);
	}
	return 0;
}
