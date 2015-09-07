#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main() {
	int T; scanf("%d", &T);
	while (T --) {
		int A, C; scanf("%d%d", &A, &C);
		if (C % A) puts("NO SOLUTION");
		else {
			int B = C / A, G;
			do {
				G = __gcd(A, B);
				B *= G;
				A /= G;
			} while (G != 1);
			printf("%d\n", B);
		}
	}
	return 0;
}
