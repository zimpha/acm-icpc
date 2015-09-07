#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

typedef long long LL;

LL L[2][2] = {{1, 1}, {0, 1}};
LL R[2][2] = {{1, 0}, {1, 1}};

void mul(LL a[2][2], LL b[2][2], LL c[2][2]) {
	c[0][0] = a[0][0] * b[0][0] + a[0][1] * b[1][0];
	c[0][1] = a[0][0] * b[0][1] + a[0][1] * b[1][1];
	c[1][0] = a[1][0] * b[0][0] + a[1][1] * b[1][0];
	c[1][1] = a[1][0] * b[0][1] + a[1][1] * b[1][1];
}

LL gcd(LL a, LL b) {
	return (b) ? gcd(b, a % b) : a;
}

int main() {
	int N; scanf("%d", &N);
	while (N --) {
		char st[100]; scanf("%s", st);
		LL ret[2][2], tmp[2][2];
		ret[0][0] = ret[1][1] = 1;
		ret[0][1] = ret[1][0] = 0;
		for (int i = 0; st[i]; ++ i) {
			if (st[i] == 'L') mul(ret, L, tmp);
			else mul(ret, R, tmp);
			memcpy(ret, tmp, sizeof(tmp));
		}
		LL a = ret[1][0] + ret[1][1];
		LL b = ret[0][0] + ret[0][1];
		LL g = gcd(a, b);
		printf("%lld/%lld\n", a / g, b / g);
	}
	return 0;
}
