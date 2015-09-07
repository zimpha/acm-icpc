#include <cstdio>
#include <cstring>

const int MAXN=105;

bool map[MAXN][MAXN],g[MAXN][MAXN];
int value[MAXN],dis[MAXN];
int n;

int main()
{
    while (scanf("%d",&n)&&n!=-1)
    {
        memset(value,0,sizeof(value));
        memset(map,0,sizeof(map));
        memset(dis,-1,sizeof(dis));
        for (int i=1; i<=n; i++)
        {
	    int m,x;
            scanf("%d%d",&value[i],&m);
            while (m--)
            {
                scanf("%d",&x);
                map[i][x]=true;
            }
        }
        memcpy(g,map,sizeof(map));
        for (int k=1; k<=n; k++)
            for (int i=1; i<=n; i++)
                for (int j=1; j<=n; j++)
		    g[i][j]|=g[i][k]&&g[k][j];
        if (!g[1][n])
        {
            printf("hopeless\n");
            continue;
        }
        g[n][n]=true; dis[1]=100;
	int k;
        for (k=1; k<=n; k++)
        {
            bool flag=true;
            for (int i=1; i<=n; i++)
                for (int j=1; j<=n ;j++)
                    if (map[i][j]&&g[j][n]&&dis[j]<dis[i]+value[j]&&dis[i]>0)
                    {
                        dis[j]=dis[i]+value[j];
                        flag=false;
                    }      
            if (flag) break;
        }
        if (k>n||dis[n]>=0) printf("winnable\n");
        else printf("hopeless\n");
    }
    return 0;
}
