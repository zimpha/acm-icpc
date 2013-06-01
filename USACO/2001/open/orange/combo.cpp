#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN=100000;

typedef struct node{int a, b;}node;

node ret[MAXN];
int n, m;

bool cmp(node a, node b)
{
    if (a.a==b.a) return (a.b<b.b);
    else return (a.a<b.a);
}

int main()
{
	freopen("combo.in", "r", stdin);
	freopen("combo.out", "w", stdout);

	scanf("%d", &m);
	n=0;
	for (int b=2; b<=sqrt(2*m); b++)
	{
		if (2*m%b) continue;
		int a=2*m/b+1-b;
		if (a%2==0&&a>1) ret[n].a=a/2, ret[n++].b=a/2+b-1;
	}
	sort(ret, ret+n, cmp);
	for (int i=0; i<n; i++)
		printf("%d %d\n", ret[i].a, ret[i].b);
	fclose(stdin); fclose(stdout);
}
