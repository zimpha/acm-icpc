#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN=10005;
const int inf=10000000;

typedef struct { int m, id; }stacknode;
typedef struct { int v, next; } edgenode;

stacknode stack[MAXN];
edgenode edge[MAXN*10];
char buff[MAXN];
int n, cnt, top;

void link(int a, int b)
{
	int p, e;
	p=cnt++;
	for (e=a; edge[e].next!=-1; e=edge[e].next);
	edge[p].v=b; edge[p].next=-1;
	edge[e].next=p;
}

void print(int u)
{
	if (edge[u].next==-1) putchar('a');
	else
	{
		int count=0;
		for (int e=edge[u].next; e!=-1; e=edge[e].next)
		{
			count++;
			print(edge[e].v);
		}
		printf("%d", count);
	}
}

int main()
{
	while (scanf("%s", buff)==1)
	{
	top=cnt=0;
	for (int i=0; buff[i]; i++)
	{
		if (buff[i]=='a')
		{
			int p=cnt++;
			edge[p].next=-1;
			stack[top].id=p;
			stack[top++].m=1;
		}
		else
		{
			int c=buff[i]-'0';
			int t[10];
			for (int j=0; j<c; j++)
				t[j]=stack[j+top-c].m;
			int ans=inf, pos;
			for (int j=0; j<c; j++)
			{
				int ret=0;
				for (int k=0; k<c; k++)
					ret=std::max(ret,k+t[(j+k)%c]);
				if (ret<ans)
				{
					ans=ret;
					pos=j;
				}
			}
			int p=cnt++;
			edge[p].next=-1;
			for (int j=0; j<c; j++)
				link(p,stack[(j+pos)%c+top-c].id);
			stack[top-c].id=p;
			stack[top-c].m=ans;
			top=top-c+1;
		}
	}
	printf("%d\n", stack[0].m);
	print(stack[0].id);
	puts("");
	}
	return 0;
}
