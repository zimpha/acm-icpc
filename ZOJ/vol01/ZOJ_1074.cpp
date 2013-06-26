#include <iostream>
#include <algorithm>
#include <cstring>
#define MAXN 110
using namespace std;

int a[MAXN][MAXN];
int n,ans=0;

int main()
{
    int i,j,k;
    cin>>n;
    memset(a,0,sizeof(a));
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
        {
            cin>>a[i][j];
            a[i][j]+=a[i-1][j];
        }
    for (i=1;i<=n;i++)
        for (j=i;j<=n;j++)
        {
            int tmp=0,sum=0;
            for (k=1;k<=n;k++)
            {
                if (sum+a[j][k]-a[i-1][k]>0) sum+=a[j][k]-a[i-1][k];
                else sum=0;
                if (tmp<sum) tmp=sum;
            }
            if (tmp>ans) ans=tmp;
        }
    cout<<ans<<endl;
    return 0;
}
