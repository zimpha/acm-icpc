#include <cstdio>
#include <cstring>

const int MAXN=1005;

bool left[MAXN], right[MAXN];
bool normal[MAXN];
bool light[MAXN];
bool heavy[MAXN];
int n, k;

int main()
{
	int test;
	scanf("%d", &test);
	while (test--)
	{
	scanf("%d%d", &n, &k);
	memset(normal,0,sizeof(normal));
	memset(light,0,sizeof(light));
	memset(heavy,0,sizeof(heavy));
	for (int i=0; i<k; i++)
	{
		memset(left,0,sizeof(left));
		memset(right,0,sizeof(right));
		int p, x;
		char sign;
		scanf("%d", &p);
		for (int j=0; j<p; j++)
		{
			scanf("%d", &x);
			left[x]=true;
		}
		for (int j=0; j<p; j++)
		{
			scanf("%d", &x);
			right[x]=true;
		}
		scanf("\n%c", &sign);
		switch (sign)
		{
			case '=':
				for (int i=1; i<=n; i++)
					if (left[i]||right[i])
						normal[i]=true;
				break;
			case '<':
				for (int i=1; i<=n; i++)
				{
					if (!left[i]&&!right[i]) normal[i]=true;
					if (left[i]) light[i]=true;
					if (right[i]) heavy[i]=true;
				}
				break;
			case '>':
				for (int i=1; i<=n; i++)
				{
					if (!left[i]&&!right[i]) normal[i]=true;
					if (left[i]) heavy[i]=true;
					if (right[i]) light[i]=true;
				}
				break;
		}
	}
	int ans, count=0;
	for (int i=1; i<=n; i++)
	{
		if (light[i]&&heavy[i]) normal[i]=true;
		if (normal[i]) count++;
		else ans=i;
	}
	if (count==n-1) printf("%d\n",ans);
	else printf("0\n");
	if (test) puts("");
	}
	return 0;
}
