#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN=805;
const int MAXK=45;
const int SIZE=400000;

struct EDGE
{
    int v, w;
    EDGE *next;
};

struct HEAP
{
    int u, s;
};

EDGE *head[MAXN];
HEAP heap[SIZE];
int done[MAXN];
int n, m, k;
int cnt;

void addedge(int u, int v, int w)
{
    EDGE *p=new(EDGE);
    p->v=v; p->w=w; p->next=head[u]; head[u]=p;
}

void insert(int u, int s)
{
    heap[++cnt].u=u; heap[cnt].s=s;
    int i=cnt;
    while (i>>1)
    {
	if (heap[i].s<heap[i>>1].s) std::swap(heap[i], heap[i>>1]);
	else break;
	i>>=1;
    }
}

HEAP pop()
{
    HEAP ret=heap[1];
    heap[1]=heap[cnt--];
    int i=1;
    while ((i<<1)<=cnt)
    {
	i<<=1;
	if (i<cnt&&heap[i].s>heap[i+1].s) i++;
	if (heap[i].s<heap[i>>1].s) std::swap(heap[i], heap[i>>1]);
	else break;
    }
    return ret;
}

int main()
{
    int ans=0;
    
    freopen("relay.in", "r", stdin);
    freopen("relay.out", "w", stdout);

    scanf("%d%d%d", &k, &n, &m);
    memset(head, 0, sizeof(head));
    for (int i=0; i<m; i++)
    {
	int u, v, w;
	scanf("%d%d%d", &u, &v, &w);
	addedge(u, v, w);
	addedge(v, u, w);
    }
    memset(heap, 0, sizeof(heap));
    memset(done, 0, sizeof(done));
    cnt=0; insert(1, 0);
    while (done[n]<k)
    {
	HEAP now;
	now=pop(); done[now.u]++;
	if (now.u==n) ans+=now.s;
	if (done[now.u]<=k&&now.u!=n)
	{
	    for (EDGE *p=head[now.u]; p; p=p->next)
	    {
		int v=p->v, w=p->w;
		insert(v, w+now.s);
	    }
	}
    }
    printf("%d\n", ans);
    fclose(stdin); fclose(stdout);
    return 0;
}
