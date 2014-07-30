#include <bitset>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const char *op = "DLRU";
const int M = 8 * 9 * 5 * 7;
const int d[4][3][3] = {
	{{0,3,6},{1,4,7},{2,5,8}},
	{{2,1,0},{5,4,3},{8,7,6}},
	{{0,1,2},{3,4,5},{6,7,8}},
	{{6,3,0},{7,4,1},{8,5,2}}
};

struct Node {
	int st, mv;
	Node() {}
	Node(int s, int m) : st(s), mv(m) {}
};

inline int get(int s, int k) {return s >> (k << 1) + k & 7;}
inline int set(int b, int k) {return b << (k << 1) + k;}

void move(int &s, const int v[]) {
	int a = get(s, v[0]), b = get(s, v[1]), c = get(s, v[2]);
	s ^= set(a, v[0]) ^ set(b, v[1]) ^ set(c, v[2]);
	if (!b) b = a, a = 0;
	if (!c) c = b, b = a, a = 0;
	if (b && b == c) c ++, b = a, a = 0;
	else if (a && a == b) b ++, a = 0;
	s ^= set(a, v[0]) ^ set(b, v[1]) ^ set(c, v[2]);
}

void solve() {
	int R, P, Q; scanf("%d%d%d", &R, &P, &Q);
	R %= M; P %= M; Q %= M;
	int s = 0;
	for (int i = 0, x; i < 9; ++ i) {
		scanf("%d", &x);
		s |= set((x == 0) ? 0 : __builtin_ctz(x), i);
	}
	vector<Node> q; q.push_back(Node(s, 0));
	static bitset<6 << 24> hash; hash.reset();
	for (int h = 0, nt = 1; h < (int)q.size(); ) {
		for (int i = 0; i < 4; ++ i) {
			int now = q[h].st;	
			for (int k = 0; k < 3; ++ k) move(now, d[i][k]);
			int t = now & 0666666666;
			if (t & t >> 1) {
				string ret = {op[i]};
				for (; h > 0; h = q[h].mv >> 2) ret = op[q[h].mv & 3] + ret;
				puts(ret.c_str());
				return;
			}
			if (now != q[h].st) {
				int rest = 0;
				for (int k = 0; k < 9; ++ k) rest += !get(now, k);
				int c = 1 + R % rest;
				for (int k = 0; k < 9; ++ k) {
					if (!get(now, k)) c --;
					if (c == 0) {
						now |= set(R % 10 ? 1 : 2, k);
						break;
					}
				}
				if (!hash[now]) {
					q.push_back(Node(now, h << 2 | i));
					hash.set(now);
				}
			}
		}
		if (++ h == nt) {
			R = (R * P + Q) % M;
			nt = q.size();
		}
	}
	puts("Always lose!");
}

int main() {
	int T; scanf("%d", &T);
	while (T --) {
		solve();
	}
}
