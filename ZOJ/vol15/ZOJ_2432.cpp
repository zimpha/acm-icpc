#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define MAXN 510

using namespace std;

typedef struct
{
    int i,j;
}node;

int f[MAXN][MAXN];
node pre[MAXN][MAXN];
int a[MAXN],b[MAXN];
int n,m;

void print(int x,int y)
{
    if (x==0||y==0) return;
    print(pre[x][y].i,pre[x][y].j);
    if (a[x]==b[y]) cout<<a[x]<<" ";
}

int main()
{
    int i,j,k;
    int test;
    scanf("%d", &test);
    while (test--)
    {
    cin>>n;
    for (i=1;i<=n;i++)
        cin>>a[i];
    cin>>m;;
    for (i=1;i<=m;i++)
        cin>>b[i];
    memset(f,0,sizeof(f));
    memset(pre,0,sizeof(pre));

    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
            if (a[i]!=b[j]){
                f[i][j]=f[i][j-1];
                pre[i][j].i=i;
                pre[i][j].j=j-1;
            }
            else{
                f[i][j]=1;
                for (k=1;k<i;k++){
                    if (a[i]>a[k]&&f[i][j]<f[k][j-1]+1){
                        f[i][j]=f[k][j-1]+1;
                        pre[i][j].i=k;
                        pre[i][j].j=j-1;
                    }
                }
            }

    int ans=0,x=0,y=0;
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
            if (ans<f[i][j]){
                ans=f[i][j];
                x=i;
                y=j;
            }

    cout<<ans<<endl;
    print(pre[x][y].i,pre[x][y].j);
    if (y) cout<<b[y];
    cout<<endl;
    	if (test) puts("");
    }
    return 0;
}

