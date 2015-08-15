#include <cctype>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main() {
	char s[100];
	int T, ret = 0;
	scanf("%d", &T);
	while (T --) {
		scanf("%s", s);
		int a[10], b[10], c[10], i;
		int n1 = 0, n2 = 0, n3 = 0, tt = 0;
		for (i = 0; isdigit(s[i]) || islower(s[i]); ++ i) {
			if (isdigit(s[i])) a[n1 ++] = s[i] - '0';
			else a[n1 ++] = s[i] - 'a' + 10;
			tt = max(tt, a[n1 - 1]);
		}
		for (i ++; isdigit(s[i]) || islower(s[i]); ++ i) {
			if (isdigit(s[i])) b[n2 ++] = s[i] - '0';
			else b[n2 ++] = s[i] - 'a' + 10;
			tt = max(tt, b[n2 - 1]);
		}
		for (i ++; isdigit(s[i]) || islower(s[i]); ++ i) {
			if (isdigit(s[i])) c[n3 ++] = s[i] - '0';
			else c[n3 ++] = s[i] - 'a' + 10;
			tt = max(tt, c[n3 - 1]);
		}
		for (int base = max(2, tt + 1); base <= 16; ++ base) {
			long long s1 = 0, s2 = 0, s3 = 0;
			for (int i = 0; i < n1; ++ i) s1 = s1 * base + a[i];
			for (int i = 0; i < n2; ++ i) s2 = s2 * base + b[i];
			for (int i = 0; i < n3; ++ i) s3 = s3 * base + c[i];
			if (s1 + s2 == s3) {
				ret ++;
				break;
			}
		}
	}
	printf("%d\n", ret);
	return 0;
}
