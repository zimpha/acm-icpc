#include <cstdio>
#include <cstring>

const int MAXN=205;

struct node
{
	int x, y, v;
};

int dir[2][4]={1,0,3,2,3,2,1,0};
bool vis[MAXN][4];
node pos[MAXN];
int N;

int findr(node now)
{
	int index=-1;
	node tmp;
	for (int i=1; i<=N; i++)
		if (now.y==pos[i].y&&now.x<pos[i].x)
		{
			if (index==-1||(index!=-1&&pos[i].x<tmp.x))
			{
				index=i;
				tmp=pos[i];
			}
		}
	return index;
}

int findu(node now)
{
	int index=-1;
	node tmp;
	for (int i=1; i<=N; i++)
		if (now.x==pos[i].x&&now.y<pos[i].y)
		{
			if (index==-1||(index!=-1&&pos[i].y<tmp.y))
			{
				index=i;
				tmp=pos[i];
			}
		}
	return index;
}

int findl(node now)
{
	int index=-1;
	node tmp;
	for (int i=1; i<=N; i++)
		if (now.y==pos[i].y&&now.x>pos[i].x)
		{
			if (index==-1||(index!=-1&&pos[i].x>tmp.x))
			{
				index=i;
				tmp=pos[i];
			}
		}
	return index;
}

int findd(node now)
{
	int index=-1;
	node tmp;
	for (int i=1; i<=N; i++)
		if (now.x==pos[i].x&&now.y>pos[i].y)
		{
			if (index==-1||(index!=-1&&pos[i].y>tmp.y))
			{
				index=i;
				tmp=pos[i];
			}
		}
	return index;
}

bool check()
{
	node now, tmp;
	memset(vis, 0, sizeof(vis));
	vis[0][2]=true;
	now.x=now.y=now.v=0;
	while (1)
	{
		int next;
		switch (now.v)
		{
			case 0: next=findr(now); break;
			case 1: next=findu(now); break;
			case 2:	next=findl(now); break;
			case 3: next=findd(now); break;
		}
		if (next==-1) return false;
		if (vis[next][now.v]) return false;
		vis[next][now.v]=true;
		tmp=pos[next];
		tmp.v=dir[pos[next].v][now.v];
		now=tmp;
		if (now.x==pos[N].x&&now.y==pos[N].y) break;
	}
	return true;
}

int main()
{
	freopen("mirrors.in", "r", stdin);
	freopen("mirrors.out", "w", stdout);
	scanf("%d", &N); N++;
	scanf("%d%d", &pos[N].x, &pos[N].y);
	for (int i=1; i<N; i++)
	{
		char ch;
		scanf("%d %d %c", &pos[i].x, &pos[i].y, &ch);
		if (ch=='/') pos[i].v=0;
		else pos[i].v=1;
	}
	pos[0].x=pos[0].y=pos[0].v=0;
	int ret;
	for (int i=0; i<=N; i++)
	{
		ret=i;
		pos[i].v=1-pos[i].v;
		if (check()) break;
		pos[i].v=1-pos[i].v;
	}
	if (ret==N) printf("-1\n");
	else printf("%d\n", ret);
	fclose(stdin); fclose(stdout);
}
