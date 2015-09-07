#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1000 + 10;

struct Node {
	int pos, code;
	Node () {}
	Node (int p, int c) : pos(p), code(c) {}
	bool operator < (const Node &rhs) const {
		return pos < rhs.pos;
	}
};

int PixLen[MAXN], PixVal[MAXN];
Node Map[MAXN << 3];
int N, W, tot;

inline int getval(int pos) {
	int i = 0, p = 0;
	while (p <= pos) p += PixLen[i], i ++;
	return PixVal[i - 1];
}

inline int encode(int pos) {
	int NowVal = getval(pos), ret = 0;
	int r = pos / W, c = pos % W;
	for (int x = r - 1; x <= r + 1; ++ x) {
		for (int y = c - 1; y <= c + 1; ++ y) {
			int tmp = x * W + y;
			if (x < 0 || y < 0 || y >= W || tmp >= tot) continue;
			int TmpVal = getval(tmp);
			if (ret < abs(NowVal - TmpVal)) ret = abs(NowVal - TmpVal);
		}
	}
	return ret;
}

int main() {
	while (scanf("%d", &W) == 1 && W) {
		N = tot = 0;
		int M = 0;
		while (scanf("%d%d", &PixVal[N], &PixLen[N]) == 2 && PixLen[N]) {
			tot += PixLen[N]; N ++;
		}
		printf("%d\n", W);
		for (int i = 0, pos = 0; i <= N; ++ i) {
			int r = pos / W, c = pos % W;
			for (int x = r - 1; x <= r + 1; ++ x) {
				for (int y = c - 1; y <= c + 1; ++ y) {
					int tmp = x * W + y;
					if (x < 0 || y < 0 || y >= W || tmp >= tot) continue;
					Map[M ++] = Node(tmp, encode(tmp));
				}
			}
			pos += PixLen[i];
		}
		sort(Map, Map + M);
		Node tmp = Map[0];
		for (int i = 0; i < M; ++ i) {
			if (tmp.code == Map[i].code) continue;
			printf("%d %d\n", tmp.code, Map[i].pos - tmp.pos);
			tmp = Map[i];
		}
		printf("%d %d\n", tmp.code, tot - tmp.pos);
		puts("0 0");
	}
	puts("0");
	return 0;
}
