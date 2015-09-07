#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXP = 11;
const int MAXC = 101;
const int MAXN = 101;

struct Guess {
	int G[MAXP], cnt[MAXC];
	int B, BW;
};

int G[MAXP];
int P, C, N;
Guess Q[MAXN];

bool search(int dep) {
	for (int i = 0; i < N; ++ i) {
		if (Q[i].B < 0 || Q[i].BW < 0 || Q[i].B > P - dep || Q[i].BW > P - dep)
			return 0;
	}
	if (dep == P) return 1;
	for (int i = 0; i < C; ++ i) {
		for (int q = 0; q < N; ++ q) {
			if (Q[q].G[dep] == i) Q[q].B --;
			if (Q[q].cnt[i] -- > 0) Q[q].BW --;
		}
		G[dep] = i;
		if (search(dep + 1)) return 1;
		for (int q = 0; q < N; ++ q) {
			if (Q[q].G[dep] == i) Q[q].B ++;
			if (++ Q[q].cnt[i] > 0) Q[q].BW ++;
		}
	}
	return 0;
}

int main() {
	int T; scanf("%d", &T);
	while (T --) {
		scanf("%d%d%d", &P, &C, &N);
		for (int i = 0, b, w; i < N; ++ i) {
			for (int j = 0; j < C; ++ j) Q[i].cnt[j] = 0;
			for (int j = 0; j < P; ++ j) {
				scanf("%d", &Q[i].G[j]);
				Q[i].G[j] --;
				Q[i].cnt[Q[i].G[j]] ++;
			}
			scanf("%d%d", &b, &w);
			Q[i].B = b; Q[i].BW = b + w;
		}
		if (search(0)) {
			for (int i = 0; i < P; ++ i) {
				if (i) putchar(' ');
				printf("%d", G[i] + 1);
			}
			puts("");
		} else {
			puts("You are cheating!");
		}
	}
	return 0;
}
