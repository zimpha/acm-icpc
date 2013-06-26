#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN=50005;

int w[MAXN], h[MAXN];
int stack[MAXN];
int n, top;

int main()
{
	while (scanf("%d", &n)==1&&n>0)
	{
		for (int i=1; i<=n; i++)
			scanf("%d%d", w+i, h+i);
		int ret=0;
		top=0;
		for (int i=1; i<=n; i++)
		{
			if (top==0) stack[++top]=i;
			else
			{
				if (h[i]>=h[stack[top]]) stack[++top]=i;
				else
				{
					int sum=0;
					while (top>0&&h[i]<h[stack[top]])
					{
						sum+=w[stack[top]];
						if (sum*h[stack[top]]>ret)
							ret=sum*h[stack[top]];
						top--;
					}
					w[i]+=sum;
					stack[++top]=i;
				}
			}
		}
		int sum=0;
		while (top)
		{
			sum+=w[stack[top]];
			if (sum*h[stack[top]]>ret) 
				ret=sum*h[stack[top]];
			top--;
		}
		printf("%d\n", ret);
	}
	return 0;
}
