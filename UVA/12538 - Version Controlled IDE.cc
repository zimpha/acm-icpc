#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ext/rope>
#include <algorithm>
using namespace __gnu_cxx;
using namespace std;

const int MAXN=50000+10;

rope<char> R[MAXN];
char A[1000];
int n, vnow, d;

void INSERT() {
	int pos;
	scanf("%d%s", &pos, A);
	vnow++; R[vnow]=R[vnow-1];
	pos+=d;
	R[vnow].insert(pos, A);
}

void DELETE() {
	int pos, tot;
	scanf("%d%d", &pos, &tot);
	vnow++; R[vnow]=R[vnow-1];
	pos+=d; tot+=d;
	R[vnow].erase(pos-1, tot);
}

void PRINT() {
	int ver, pos, tot;
	scanf("%d%d%d", &ver, &pos,  &tot);
	ver+=d; pos+=d; tot+=d;
	rope<char> t=R[ver].substr(pos-1, tot);
	rope<char>::iterator it;
	for (it=t.mutable_begin(); it!=t.mutable_end(); it++) {
		putchar(*it);
		if ((*it)=='c') d--;
	}
	puts("");
}

int main() {
	scanf("%d", &n); vnow=0; d=0;
	for (int i=0; i<n; i++) {
		int cmd;
		scanf("%d", &cmd);
		if (cmd==1) INSERT();
		else if (cmd==2) DELETE();
		else if (cmd==3) PRINT();
	}
}
