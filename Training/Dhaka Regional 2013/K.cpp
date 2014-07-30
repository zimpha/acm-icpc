#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXC = 150, SIZE = 5000, MAXR = 250;
int CubeSize[SIZE], blockID[30][30][30];
bool ret[MAXC], can[30][30][30];

class DLX {
public:
	int D[SIZE], U[SIZE], L[SIZE], R[SIZE];
	int CID[SIZE], RID[SIZE], S[MAXC], H[MAXR], sz;
	void init(int n) {
		memset(H, -1, sizeof(H));
		for (int i = 1; i <= n; ++ i) {
			L[i + 1] = R[i - 1] = i;
			U[i] = D[i] = i; S[i] = 0;
		}
		L[1] = R[n] = 0; L[0] = n; sz = n + 1;
	}
	void link(int r, int c) {
		D[sz] = D[c], U[sz] = c, U[D[c]] = sz, D[c] = sz;
		S[c] ++; CID[sz] = c; RID[sz] = r;
		if (H[r] == -1) H[r] = L[sz] = R[sz] = sz;
		R[L[H[r]]] = sz; L[sz] = L[H[r]];
		R[sz] = H[r]; L[H[r]] = sz; sz ++;
	}
	void remove(int c) {
		L[R[c]] = L[c]; R[L[c]] = R[c];
		for (int i = D[c]; i != c; i = D[i]) {
			for (int j = R[i]; j != i; j = R[j]) {
				D[U[j]] = D[j], U[D[j]] = U[j];
				S[CID[j]] --;
			}
		}
	}
	void resume(int c) {
		L[R[c]] = c; R[L[c]] = c;
		for (int i = U[c]; i != c; i = U[i]) {
			for (int j = L[i]; j != i; j = L[j]) {
				U[D[j]] = j, D[U[j]] = j;
				S[CID[j]] ++;
			}
		}
	}
	void dance(int n, int sum) {
		ret[n + sum] = true;
		if (R[0] == 0) return;
		int idx, now = 0;
		for (int i = R[0]; i; i = R[i]) {
			if (S[i] > now) now = S[i], idx = i;
		}
		remove(idx);
		for (int i = D[idx]; i != idx; i = D[i]) {
			if (CubeSize[RID[i]] == 1) continue;
			for (int j = R[i]; j != i; j = R[j]) remove(CID[j]);
			dance(n + 1, sum - CubeSize[RID[i]]);
			for (int j = L[i]; j != i; j = L[j]) resume(CID[j]);
		}
		resume(idx);
	}
} dlx;

bool check(int x, int y, int z, int p) {
	for (int i = 0; i < p; ++ i) {
		for (int j = 0; j < p; ++ j) {
			for (int k = 0; k < p; ++ k) {
				if (!can[x + i][y + j][z + k]) return false;
			}
		}
	}
	return true;
}

void add(int line, int x, int y, int z, int p) {
	for (int i = 0; i < p; ++ i) {
		for (int j = 0; j < p; ++ j) {
			for (int k = 0; k < p; ++ k) {
				dlx.link(line, blockID[x + i][y + j][z + k]);
			}
		}
	}
	CubeSize[line] = p * p * p;
}

int main() {
	int a, b, c, m, cas = 0;
	while (scanf("%d%d%d%d", &a, &b, &c, &m) == 4 && a) {
		memset(blockID, 0, sizeof(blockID));
		memset(ret, 0, sizeof(ret));
		memset(can, 1, sizeof(can));
		int sum = a * b * c;
		while (m --) {
			int x, y, z; scanf("%d%d%d", &x, &y, &z);
			can[x][y][z] = 0; sum --;
		}
		m = 0;
		for (int x = 1; x <= a; ++ x) {
			for (int y = 1; y <= b; ++ y) {
				for (int z = 1; z <= c; ++ z) {
					if (can[x][y][z]) blockID[x][y][z] = ++ m;
				}
			}
		}
		dlx.init(m);
		memset(CubeSize, 0, sizeof(CubeSize));
		for (int p = min(a, min(b, c)), line = 0; p >= 1; -- p) {
			for (int x = 1; x + p - 1 <= a; ++ x) {
				for (int y = 1; y + p - 1 <= b; ++ y) {
					for (int z = 1; z + p - 1 <= c; ++ z) {
						if (!check(x, y, z, p)) continue;
						add(++ line, x, y, z, p);
					}
				}
			}
		}
		dlx.dance(0, sum);
		printf("Case %d:", ++ cas);
		for (int i = 0; i < MAXC; ++ i)
			if (ret[i]) printf(" %d", i);
		puts("");
	}
	return 0;
}
