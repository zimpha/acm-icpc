#include <cstdio>
#include <cstring>

const int MAXN=20000;

int card[MAXN], tmp[MAXN];
int n;

bool check()
{
	for (int i=1; i<2*n; i++)
		if (card[i]!=card[i+1]-1) return false;
	return true;
}

int main()
{
	freopen("shuffle.in", "r", stdin);
	freopen("shuffle.out", "w", stdout);
	scanf("%d", &n);
	for (int i=1; i<=2*n; i++)
		card[i]=i;
	int ret=0;
	while (1)
	{
		ret++;
		for (int i=1, l=n, r=2*n; i<=n; i++, l--, r--)
		{
			tmp[2*i-1]=card[r];
			tmp[2*i]=card[l];
		}
		memcpy(card, tmp, sizeof(tmp));
		if (check()) break;
	}
	printf("%d\n", ret);
	fclose(stdin); fclose(stdout);
}
