#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int SIZE = 50000000;
const int MAXN = 250000 + 10;
const int MAXL = 600;

struct Node {
	Node *ch[2];
	int sz;
} mem[SIZE], *root[600], *null, *cnt;

int ll[MAXL], rr[MAXL], XOR[MAXL];
int A[MAXN], N, Q, L;
int mx, times;

Node *NewNode() {
	cnt->ch[0] = cnt->ch[1] = null;
	cnt->sz = 0;
	return cnt ++;
}

void Insert(int idx, int x) {
	Node *p = root[idx];
	for (int i = 15; i >= 0; -- i) {
		bool o = ((x >> i) & 1);
		if (p->ch[o] == null) p->ch[o] = NewNode();
		p = p->ch[o]; p->sz ++;
	}
}

void Erase(int idx, int x) {
	Node *p = root[idx];
	for (int i = 15; i >= 0; -- i) {
		bool o = ((x >> i) & 1);
		p = p->ch[o]; p->sz --;
	}
}

void getMin(int idx, int x) {
	int ret = 0;
	Node *p = root[idx];
	for (int i = 15; i >= 0; -- i) {
		bool o = ((x >> i) & 1);
		if (p->ch[o] == null || p->ch[o]->sz == 0){
			ret |= (1 << i), o = !o;
		}
		p = p->ch[o];
	}
	if (ret < mx) mx = ret, times = p->sz;
	else if (ret == mx) times += p->sz;
}

void init() {
	cnt = mem; null = NewNode();
	null->ch[0] = null->ch[1] = null;
	null->sz = 0;
}

int main() {
	init();
	scanf("%d%d", &N, &Q);
	L = (int)sqrt(N);
	for (int i = 0, p = 0; i < N; ++ i) {
		if (i % L == 0) {
			root[p ++] = NewNode();
			XOR[p - 1] = 0;
			ll[p - 1] = i;
			rr[p - 1] = min(N - 1, i + L - 1);
		}
		scanf("%d", &A[i]);
		Insert(p - 1, A[i]);
	}
	while (Q --) {
		int type, l, r, k, bl, br;
		scanf("%d%d%d", &type, &l, &r);
		l --; r --;
		bl = l / L, br = r / L;
		if (type == 1) {
			mx = 65536; times = 0;
			for (int i = bl; i <= br; ++ i) {
				if (ll[i] >= l && rr[i] <= r) getMin(i, XOR[i]);
				else {
					int x = max(ll[i], l), y = min(rr[i], r);
					for (int j = x; j <= y; ++ j) {
						int t = A[j] ^ XOR[i];
						if (t < mx) mx = t, times = 1;
						else if (t == mx) times ++;
					}
				}
			}
			printf("%d %d\n", mx, times);
		}
		else {
			scanf("%d", &k);
			for (int i = bl; i <= br; ++ i) {
				if (ll[i] >= l && rr[i] <= r) XOR[i] ^= k;
				else {
					int x = max(ll[i], l), y = min(rr[i], r);
					for (int j = x; j <= y; ++ j) {
						Erase(i, A[j]);
						A[j] ^= k;
						Insert(i, A[j]);
					}
				}
			}
		}
	}
	return 0;
}
