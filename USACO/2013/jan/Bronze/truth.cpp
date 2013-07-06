#include <cstdio>
#include <cstring>

const int MAXN=1005;

int f[MAXN], val[MAXN];
int N, M;

int find(int x)
{
	int tmp;
	if (x!=f[x])
	{
		tmp=f[x];
		f[x]=find(f[x]);
		val[x]^=val[tmp];
	}
	return f[x];
}

int main()
{
	freopen("truth.in", "r", stdin);
	freopen("truth.out", "w", stdout);
	scanf("%d%d", &N, &M);
	for (int i=0; i<=N; i++)
		f[i]=i, val[i]=0;
	int ans=M;
	for (int i=1; i<=M; i++)
	{
		int a, b, fa, fb;
		char ch;
		scanf("%d%d %c", &a, &b, &ch);
		fa=find(a); fb=find(b);
		if (fa==fb)
		{
			if ((val[a]^val[b])!=(ch!='T'))
			{
				ans=i-1;
				break;
			}
		}
		else
		{
			f[fa]=fb;
			val[fa]=val[a]^val[b]^(ch!='T');
		}
	}
	printf("%d\n", ans);
	fclose(stdin); fclose(stdout);
	return 0;
}
