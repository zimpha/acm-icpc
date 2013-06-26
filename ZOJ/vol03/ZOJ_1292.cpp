#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>
#include <iostream>
#define SIZE 150

using namespace std;

string s;
int a[SIZE],b[SIZE];

void get(int a[SIZE])
{
    cin >> s;
    memset(a,0,sizeof(a));
    a[0]=s.size();
    for (int i=0;i<a[0];i++)
        a[i+1]=s[a[0]-i-1]-'0';
}

void add(int a[SIZE],int b[SIZE])
{
    int i,x=0;
    for (i=1;i<=a[0]||i<=b[0];i++)
    {
        x+=a[i]+b[i];
        a[i]=x%10;
        x/=10;
    }
    if (x>0) a[0]=i,a[i]=x;
}

int main()
{
	int test;
	scanf("%d", &test);
	while (test--)
	{
    get(a);
    while (1)
    {
        get(b);
        if (b[0]==1&&b[1]==0) break;
        add(a,b);
    }
    for (int i=a[0];i>0;i--)
        cout<<a[i];
    cout<<endl;
    if (test) puts("");
    }
    return 0;
}
