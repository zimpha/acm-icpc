#include <cstdio>
#include <cstdlib>
#include <cstring>
#define MAXN 210
#define SIZE 10010

int vis[MAXN];
int que[SIZE];
int bit[SIZE];
int pre[SIZE];
int head,tail;
int n;

void expand(int b)
{
    int now;
    now=(que[head]*10+b)%n;
    if (!vis[now])
    {
        tail++;
        que[tail]=now;
        bit[tail]=b;
        pre[tail]=head;
        vis[now]=1;
    }
}

void bfs()
{
    memset(vis,0,sizeof(vis));
    vis[1]=que[1]=bit[1]=1; pre[1]=0;
    head=tail=1;
    while (head<=tail)
    {
        if (que[head]==0) break;
        expand(0);
        expand(1);
        head++;
    }
}

void print(int n)
{
    if (!n) return;
    print(pre[n]);
    printf("%d",bit[n]);
}

int main()
{
    while (scanf("%d",&n)!=EOF&&n)
    {
        bfs();
        print(head);
        printf("\n");
    }
    return 0;
}
