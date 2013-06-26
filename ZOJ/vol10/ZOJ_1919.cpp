#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#define MAXN 1010

using std::cin;
using std::cout;
using std::string;
using std::endl;

int head[26],ind[26],oud[26];
int Link[MAXN],next[MAXN];
int path[MAXN],flow[MAXN];
bool vis[MAXN],flag;
string s[MAXN];
int n,cnt;
int st;

int cmp(string a,string b)
{
    return (a>b);
}

void construct()
{
    int i,u,v,l;
    memset(ind,0,sizeof(ind));
    memset(oud,0,sizeof(oud));
    memset(head,-1,sizeof(head));
    for (i=0;i<n;i++)
    {
        l=s[i].size();
        u=s[i][0]-'a';
        v=s[i][l-1]-'a';
        ind[v]++; oud[u]++;
        next[i]=head[u]; Link[i]=v;
        head[u]=i;
    }
}

bool check()
{
    int i,num=0;
    for (i=0;i<26;i++)
        if (oud[i]-ind[i]==1) num++,st=i;
        else
            if (oud[i]-ind[i]==-1) num++;
            else
                if (abs(ind[i]-oud[i])>1) return false;
    if (num>2) return false;
    if (num==0)
        for (i=0;i<26;i++)
            if (oud[i]) {st=i; break;}
    return true;
}

void dfs(int u,int id)
{
    int now;
    for (now=head[u];now!=-1;now=next[now])
    {
        if (!vis[now])
        {
            vis[now]=true;
            dfs(Link[now],now);
        }
    }
    if (id>-1)
    {
        cnt++;
        path[cnt]=id;
    }
}

int  main()
{
    int test,i;
    cin>>test;
    while (test--)
    {
        cin>>n;
        for (i=0;i<n;i++)
            cin>>s[i];
        sort(s,s+n,cmp);
        construct();

        flag=true; cnt=0;
        memset(vis,0,sizeof(vis));
        if (check()) dfs(st,-1);
        else flag=false;
        if (cnt<n) flag=false;
        if (!flag) cout<<"***\n";
        else
        {
            for (i=cnt;i>1;i--)
                cout<<s[path[i]]<<".";
            cout<<s[path[1]]<<endl;
        }
    }
    return 0;
}
