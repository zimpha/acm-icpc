#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 40000 + 10;

struct Node{
	int ti, b;
	bool operator < (const Node &rhs) const{
		return ti < rhs.ti;
	}
};

Node a[MAXN];

int main() {
	int T; scanf("%d", &T);
	while (T --) {
		int n, m, now;
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++ i) {
			int hh, mm, ss; scanf("%d:%d:%d", &hh, &mm, &ss);
			a[i].ti = hh * 3600 + mm * 60 + ss;
			a[i].b = i + 1;
		}
		sort(a, a + n);
		vector<int> V;
		vector<bool> h(n, 0);
		for (int i = 0; i < n; ++ i) {
			if (h[i]) continue;
			now = a[i].ti + m;
			for (int j = i; j < n; ++ j) {
				if (a[j].ti < now) h[j] = 1;
				else break;
			}
			V.push_back(a[i].b);
		}
		sort(V.begin(), V.end());
		printf("%d\n", (int)V.size());
		for (int i = 0; i < (int)V.size() - 1; ++ i) printf("%d ", V[i]);
		if (V.size()) printf("%d\n", V.back());
	}
	return 0;	
}
