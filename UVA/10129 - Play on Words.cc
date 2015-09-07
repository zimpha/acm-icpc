#include <cstring>
#include <cstdio>

const int MAXN=26;

bool vis[MAXN], g[MAXN][MAXN];
int ind[MAXN], oud[MAXN];
int linked;

void dfs(int u)
{
    vis[u]=true;
    for (int v=0; v<MAXN; v++)
        if (!vis[v]&&g[u][v])
            dfs(v);
    linked++;
}

int main()
{
    int test;
    scanf("%d", &test);
    while (test--)
    {
        memset(ind,0,sizeof(ind));
        memset(oud,0,sizeof(oud));
        memset(g,0,sizeof(g));
        int n;
        scanf("%d", &n);
        while (n--)
        {
            char s[1005];
            scanf("%s", s);
            int l=strlen(s)-1;
            int u=s[0]-'a';
            int v=s[l]-'a';
            ind[v]++; oud[u]++;
            g[u][v]=g[v][u]=true;

        }
        memset(vis,0,sizeof (vis));
        int first=0, np=0;
        for (int i=0; i<MAXN; i++)
            if (ind[i]||oud[i])
            {
                if (!first) first = i;
                np++;
            }
        linked=0;
        dfs(first);
        if (linked!=np)
        {
            puts("The door cannot be opened.");
            continue;
        }
        int na=0, nb=0, ne=0, nt=0;
        for (int i=0; i<MAXN; i++)
        {
            if (ind[i]==0&&oud[i]==0) continue;
            nt++;
            if (ind[i]-oud[i]==1) na++;
            else if (ind[i]-oud[i]==-1) nb++;
            else if (ind[i]==oud[i]) ne++;
        }
        if ((na==1&&nb==1&&ne==nt-2)||ne==nt) puts("Ordering is possible.");
        else puts("The door cannot be opened.");
    }
    return 0;
} 
