#include <cstdio>
#include <cstring>

int calc(int a, int b, char c) {
	if (c == '+') return a + b;
	if (c == '-') return a - b;
	if (c == '*') return a * b;
	if (c == '/') return a / b;
	if (c == '%') return a % b;
}

int main() {
	int T; scanf("%d", &T);
	while (T --) {
		int a, b, c, ret;
		char s1[10], s2[10];
		scanf("%d%s%d%s%d", &a, s1, &b, s2, &c);
		if (s1[0] == '+' || s1[0] == '-') {
			if (s2[0] == '+' || s2[0] == '-') {
				ret = calc(calc(a, b, s1[0]), c, s2[0]);
			}
			else {
				ret = calc(a, calc(b, c, s2[0]), s1[0]);
			}
		}
		else {
			ret = calc(calc(a, b, s1[0]), c, s2[0]);
		}
		printf("%d\n", ret);
	}
	return 0;
}
