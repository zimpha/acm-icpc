#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char st[1000000];

int main() {
	scanf("%s", st);
	int cc = 0, ch = 0, ce = 0, cf = 0;
	for (int i = 0; st[i]; ++ i) {
		if (st[i] == 'C') cc ++;
		if (st[i] == 'H' && cc > ch) ch ++;
		if (st[i] == 'E' && ch > ce) ce ++;
		if (st[i] == 'F' && ce > cf) cf ++;
	}
	printf("%d\n", min(min(cc, ch), min(ce, cf)));
	return 0;
}
