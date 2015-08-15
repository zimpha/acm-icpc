#include <cstdio>
#include <cstring>

int main() {
	int N; 
	long long s1 = 0, s2 = 0;
	scanf("%d", &N);
	for (int i = 1; i <= N; ++ i) {
		int x; scanf("%d", &x);
		s1 += (long long)i; s2 += (long long)x;
	}
	if (s1 != s2) puts("NO");
	else puts("YES");
	return 0;
}
