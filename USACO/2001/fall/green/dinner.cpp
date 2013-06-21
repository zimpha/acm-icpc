#include <cstdio>
#include <cstring>

const int MAXN=50005;

bool used[MAXN];
int mat[MAXN];
int n;

int main()
{
	freopen("dinner.in", "r", stdin);
	freopen("dinner.out", "w", stdout);
	scanf("%d", &n);
	memset(used, 0, sizeof(used));
	memset(mat, 0, sizeof(mat));
	used[0]=true;
	for (int i=0; i<n; i++)
	{
		int x;
		scanf("%d", &x);
		if (mat[x]) printf("%d\n", mat[x]);
		else if (!used[x-1])
		{
			used[x-1]=used[x]=1;
			mat[x]=x-1; mat[x-1]=x;
			printf("%d\n", x-1);
		}
		else
		{
			used[x]=1;
			mat[x]=x;
			printf("%d\n", x);
		}
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
