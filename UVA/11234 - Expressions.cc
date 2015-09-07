#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#define MAXN 10010

using namespace std;

int lch[MAXN],rch[MAXN];
char s[MAXN],ans[MAXN];
int len,n;

void build()
{
    int now=n;
    if (isupper(s[now]))
    {
        rch[now]=--n;
        build();
        lch[now]=n;
        build();
    }
    else lch[now]=rch[now]=-1, n--;
}

void construct()
{
    int head,tail,now;
    int queue[MAXN];
    head=tail=0;
    ans[len]=0;
    queue[0]=len-1;
    while (head<=tail)
    {
        now=queue[head]; head++;
        ans[--len]=s[now];
        if (lch[now]>=0) tail++,queue[tail]=lch[now];
        if (rch[now]>=0) tail++,queue[tail]=rch[now];
    }
}

int main()
{
    int test;
    scanf("%d ",&test);
    while (test--)
    {
        gets(s);
        len=strlen(s);
        n=len-1;
        build();
        construct();
        puts(ans);
    }
    return 0;
}

