#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
bool yes;
int n,m;
int a[110][110];
bool b[110][110];
int dx,dy;
int ans[30],tot;
void init()
{
    char ch;
    memset(a,0,sizeof(a));
    memset(b,false,sizeof(b));
    memset(ans,0,sizeof(ans));
    tot=0;
    dx=0;dy=0;
    for (int i=1;i<=n;i++)
    {
     for (int j=1;j<=m;j++)
      {
         scanf("%c",&ch);
         if (ch>='A' && ch<='Z')
         {
            a[i][j]=ch-'A'+1;
            b[i][j]=true;
            }
         }
         getchar();
         }
     }
//==================================================
void search(int x,int y,int d,int dep,int st,int ed)
{
     if (dep>0) b[x][y]=false;
     if (dep>3 && x==st && y==ed)
     {
        yes=true;
        }
     if (b[x][y+1] && a[x][y+1]==d) {dy++; search(x,y+1,d,dep+1,st,ed);}
     if (b[x+1][y] && a[x+1][y]==d) {dx++; search(x+1,y,d,dep+1,st,ed);}
     if (b[x][y-1] && a[x][y-1]==d)        search(x,y-1,d,dep+1,st,ed);
     if (b[x-1][y] && a[x-1][y]==d)        search(x-1,y,d,dep+1,st,ed);
     }
//=====================================================
bool check(int x,int y,int xx,int yy)
{
     for (int i=x;i<=x+xx-1;i++)
      for (int j=y;j<=y+yy-1;j++)
       if (a[i][j]!=0) return false;
       return true;
     }
//
int main()
{
    scanf("%d%d",&n,&m);getchar();
    while (n!=0 && m!=0)
    {
    init();
    for (int i=1;i<=n;i++)
     for (int j=1;j<=m;j++)
      {
          dx=0;dy=0;
          if (b[i][j]) {yes=false; search(i,j,a[i][j],0,i,j);
          if (yes==true)  if (check(i+1,j+1,dx-1,dy-1))
          {
           ans[++tot]=a[i][j];}
           }
          }
    sort(ans+1,ans+tot+1);
    for (int i=1;i<=tot;i++)
    printf("%c",ans[i]+'A'-1);
    printf("\n");
    scanf("%d%d",&n,&m);getchar();
}
    return 0;
    }
