#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	int T; scanf("%d", &T);
	while (T --) {
		int n, m; scanf("%d%d", &n, &m);
		int s = 0;
		for (int i = 0, x; i < n; ++ i) scanf("%d", &x), s += x;	
		for (int i = 0, x; i < m; ++ i) scanf("%d", &x), s -= x;
		if (s > 0) puts("Calem");
		else if (s < 0) puts("Serena");
		else puts("Draw");		
	}
	return 0;	
}
