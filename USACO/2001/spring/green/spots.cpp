#include <cstdio>
#include <cstring>

const int MAXN=1005;
const int inf=1000000000;

struct node
{
	int r, c, s;
};

node cow[MAXN];
int n, a, b;

int main()
{
	freopen("spots.in", "r", stdin);
	freopen("spots.out", "w", stdout);
	scanf("%d%d%d", &n, &a, &b);
	for (int i=0; i<n; i++)
		scanf("%d%d%d", &cow[i].r, &cow[i].c, &cow[i].s);
	int ret=0;
	for (int i=0; i<n; i++)
	{
		int min=inf, max=0;
		for (int j=0; j<n; j++)
		{
			if (!(cow[j].r>=cow[i].r&&cow[j].c>=cow[i].c)) continue;
			if (!(cow[j].r<cow[i].r+a&&cow[j].c<cow[i].c+b)) continue;
			if (cow[j].s>max) max=cow[j].s;
			if (cow[j].s<min) min=cow[j].s;
		}
		if (ret<max-min) ret=max-min;
		min=inf; max=0;
		for (int j=0; j<n; j++)
		{
			if (!(cow[j].r>cow[i].r-a&&cow[j].c>=cow[i].c)) continue;
			if (!(cow[j].r<=cow[i].r&&cow[j].c<cow[i].c+b)) continue;
			if (cow[j].s>max) max=cow[j].s;
			if (cow[j].s<min) min=cow[j].s;
		}
		if (ret<max-min) ret=max-min;
	}
	printf("%d\n", ret);
	fclose(stdin); fclose(stdout);
	return 0;
}
