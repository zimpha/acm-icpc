#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define INF 1000000000;
#define SIZE 31

using namespace std;

char ch[]=" abcdefghijklmnopqrstuvwxyz+*/?";
int cost[SIZE][SIZE];
int sum[SIZE];
int f[13][SIZE];
int p[SIZE][SIZE];
int n;

int id(char a)
{
    int i;
    for (i=1;i<SIZE;i++)
        if (ch[i]==a) return i;
    return 0;
}

void print(int k,int n)
{
    if (k==1) return;
    print(k-1,p[k][n]-1);
    cout<<ch[p[k][n]];
}

int main()
{
    char s[SIZE];
    int test;
    int i,j,k;

    cin>>test;
    while (test--)
    {
        memset(sum,0,sizeof(sum));
        scanf("%d\n",&n);
        for (i=1;i<=n;i++)
        {
            scanf("%s",s);
            for (j=0;j<strlen(s);j++)
                sum[id(s[j])]++;
        }

        for (i=1;i<SIZE;i++)
            for (j=i;j<SIZE;j++)
            {
                cost[i][j]=0;
                for (k=i;k<=j;k++)
                    cost[i][j]+=sum[k]*(k-i+1);
            }

        memset(p,0,sizeof(p));
        for (i=1;i<SIZE;i++)
        {
            f[1][i]=cost[1][i];
            p[1][i]=1;
        }
        for (i=2;i<=12;i++)
            for (j=i;j<SIZE;j++)
            {
                f[i][j]=INF;
                for (k=i;k<=j;k++)
                    if (f[i][j]>f[i-1][k-1]+cost[k][j])
                    {
                        f[i][j]=f[i-1][k-1]+cost[k][j];
                        p[i][j]=k;
                    }
            }
        print(12,30);
        cout<<endl;
    }

    return 0;
}

