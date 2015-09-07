#include <queue>
#include <cctype>
#include <cstdio>
#include <cstring>

const int MAXN=1005;

struct node
{
    int x,y;
    node *next;
};

node *head[MAXN][MAXN];
int deg[MAXN][MAXN];
int val[MAXN][MAXN];
int n,m;

void addedge(int x1, int y1, int x2, int y2)
{
    node *p=new(node);
    p->x=x2; p->y=y2;
    p->next=head[x1][y1]; head[x1][y1]=p;
}

void topology()
{
    std::queue<node>q;
    while (!q.empty()) q.pop();
    for (int i=1; i<=n; i++)
	for (int j=1; j<=m; j++)
	    if (!deg[i][j])
	    {
		node tmp;
		tmp.x=i; tmp.y=j;
		q.push(tmp);
	    }
    while (!q.empty())
    {
	node u=q.front(); q.pop();
	for (node *p=head[u.x][u.y]; p; p=p->next)
	{
	    node v;
	    v.x=p->x; v.y=p->y;
	    deg[v.x][v.y]--;
	    val[v.x][v.y]+=val[u.x][u.y];
	    if (deg[v.x][v.y]==0) q.push(v);
	}
    }
}

int main()
{
    int test;
    scanf("%d",&test);
    while (test--)
    {
	char s[MAXN*MAXN];
	scanf("%d%d\n",&m,&n);
	memset(deg,0,sizeof(deg));
	memset(val,0,sizeof(val));
	memset(head,0,sizeof(head));
	for (int i=1; i<=n; i++)
	{
	    gets(s);
	    int num=0;
	    for (int j=0; j<strlen(s); j++)
	    {
		if (isdigit(s[j]))
		{
		    num++;
		    sscanf(&s[j],"%d",&val[i][num]);
		    while (isdigit(s[j])) j++;
		}
		else if (s[j]=='=')
		{
		    int col, row;
		    num++; j++;
		    while (1)
		    {
			col=0;
			while (isalpha(s[j]))
			{
			    col=col*26+s[j]-'A'+1;
			    j++;
			}
			sscanf(&s[j],"%d",&row);
			addedge(row,col,i,num);
			deg[i][num]++;
			while (isdigit(s[j])) j++;
			if (s[j]=='+') j++;
			else break;
		    }
		}
	    }
	}
	topology();
	for (int i=1; i<=n; i++)
	    for (int j=1; j<=m; j++)
		printf("%d%c",val[i][j],(j==m)?'\n':' ');
    }
    return 0;
}
