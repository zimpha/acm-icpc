#include <cmath>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXN = 2000 + 10;

struct Node {
	int A, idx, score;
	vector<int> D;
	void read(int i) {
		D.resize(3);
		scanf("%d %d/%d/%d %d", &A, &D[0], &D[1], &D[2], &score);
		idx = i;
	}
	bool operator < (const Node &rhs) const {
		if (score != rhs.score) return score > rhs.score;
		if (D != rhs.D) return D < rhs.D;
		return A < rhs.A;
	}
};

Node G[MAXN];
int N, T, LV[MAXN];

int main() {
	scanf("%d", &T);
	while (T --) {
		scanf("%d", &N);
		int sum = 0;
		for (int i = 0; i < N; ++ i) {
			G[i].read(i);
			sum += (G[i].score > 0);
		}
		sort(G, G + N);
		for (int i = sum; i < N; ++ i) LV[G[i].idx] = 1;
		for (int i = 0; i < sum; ++ i) LV[G[i].idx] = 2;
		int now = 0, left = floor(sum * 0.03 + 1e-8);
		while (left --) LV[G[now ++].idx] = 6;
		left = floor(sum * 0.07 + 1e-8);
		while (left --) LV[G[now ++].idx] = 5;
		left = floor(sum * 0.20 + 1e-8);
		while (left --) LV[G[now ++].idx] = 4;
		left = floor(sum * 0.30 + 1e-8);
		while (left --) LV[G[now ++].idx] = 3;
		for (int i = 0; i < N; ++ i) printf("LV%d\n", LV[i]);
	}
	return 0;
}
