#include <iostream>
#include <algorithm>
#include <cstring>
#define INF 1000000000;
#define MAXN 60

using namespace std;

typedef struct
{
    int x,y;
}node;

int f[MAXN][MAXN];
node p[MAXN];
int n;

int cross(node a,node b,node c)
{
    return abs((b.x-a.x)*(b.y-c.y)-(b.y-a.y)*(b.x-c.x));
}

int judge(node a,node b,node c,node m)
{
    int tmp=cross(a,b,c);
    if (tmp==cross(a,m,b)+cross(a,m,c)+cross(b,m,c)) return 1;
    else return 0;
}

int main()
{
    int i,j,k,l;
    bool flag;
    int test;
    int tmp;

    cin>>test;
    while (test--)
    {
        cin>>n;
        for (i=1;i<=n;i++)
            cin>>p[i].x>>p[i].y;

        for (i=1;i<n-1;i++)
            f[i][i+2]=abs(cross(p[i],p[i+1],p[i+2]));
        for (i=n;i>=1;i--)
            for (j=i+2;j<=n;j++)
            {
                f[i][j]=INF;
                for (k=i+1;k<=j-1;k++)
                {
                    flag=false;
                    for (l=1;l<=n;l++)
                        if (i!=l&&j!=l&&k!=l&&judge(p[i],p[j],p[k],p[l]))
                        {
                            flag=true;
                            break;
                        }
                    if (flag) continue;
                    tmp=max(f[i][k],f[k][j]);
                    tmp=max(tmp,cross(p[i],p[j],p[k]));
                    f[i][j]=min(f[i][j],tmp);
                }
            }
        cout<<f[1][n]/2<<'.';
        if (f[1][n]%2) cout<<5<<endl;
        else cout<<0<<endl;
    }
    return 0;
}

