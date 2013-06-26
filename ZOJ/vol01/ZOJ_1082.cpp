#include <iostream>
#define inf 100000
#define MAXN 105


using namespace std;

int main()
{
    int n;
    int g[MAXN][MAXN];
    while (cin >> n)
    {
        if (!n) break;

        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                g[i][j]=inf;

        for (int u=1;u<=n;u++)
        {
            int m;
            cin >> m;
            for (int j=0;j<m;j++)
            {
                int v,w;
                cin >> v >> w;
                g[u][v]=w;
            }
        }

        for (int k=1;k<=n;k++)
            for (int i=1;i<=n;i++)
                for (int j=1;j<=n;j++)
                    if (g[i][j]>g[i][k]+g[k][j])
                        g[i][j]=g[i][k]+g[k][j];

        int min=inf,ans;
        for (int i=1;i<=n;i++)
        {
            int max=0;
            for (int j=1;j<=n;j++)
                if (i!=j&&g[i][j]>max) max=g[i][j];
            if (min>max)
            {
                min=max;
                ans=i;
            }
        }
        cout <<ans<<" "<<min<<endl;
    }
    return 0;
}
