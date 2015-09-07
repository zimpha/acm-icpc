#include <cctype>
#include <cstdio>
#include <cstring>
#include <cstdlib>
const int SIZE = 10000;
const int MAXN = 110;

typedef long long LL;

LL cof[MAXN];
char buf[SIZE];

LL get_num(int &p) {
	LL ret = 0;
	while (isdigit(buf[p])) {
		ret = ret * 10 + buf[p] - '0';
		p ++;
	}
	return ret;
}

int main() {
	int cas = 0;
	while (gets(buf) && buf[0] != '.') {
		memset(cof, 0, sizeof(cof));
		int p, sgn, n;
		LL C, E, D;
		for (p = 1; buf[p] != ')'; ) {
			if (buf[p] == '-') sgn = -1, p ++;
			else if (buf[p] == '+') sgn = 1, p ++;
			else sgn = 1;
			if (buf[p] != 'n') C = (LL)sgn * get_num(p);
			else C = (LL)sgn;
			if (buf[p] != 'n') E = 0;
			else {
				p ++;
				if (buf[p] != '^') E = 1;
				else p++, E = get_num(p);
			}
			cof[E] = C;
		}
		p += 2; D = get_num(p);
		for (n = 100; cof[n] == 0 && n >= 0; -- n); 
		bool flag = true;
		for (n ++; flag && n > 0; -- n) {
			LL ret = 0, t = 1;
			for (int i = 0; i <= 100; ++ i) {
				ret = (ret + t * cof[i] % D) % D;
				t = t * n % D;
			}
			if (ret != 0) flag = false;
		}
		if (flag) printf("Case %d: Always an integer\n", ++ cas);
		else printf("Case %d: Not always an integer\n", ++ cas);
	}
	return 0;
}
