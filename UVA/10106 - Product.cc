#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>
#include <iostream>
#define SIZE 600

using namespace std;

string s1,s2;
int a[SIZE],b[SIZE],c[SIZE];

void change(string s,int a[SIZE])
{
    a[0]=s.size();
    for (int i=0;i<a[0];i++)
        a[i+1]=s[a[0]-i-1]-'0';
}

void mul(int a[SIZE],int b[SIZE],int c[SIZE])
{
    int i,j,x;
    for (i=1;i<=a[0];i++)
    {
        x=0;
        for (j=1;j<=b[0];j++)
        {
            c[i+j-1]+=a[i]*b[j]+x;
            x=c[i+j-1]/10;
            c[i+j-1]%=10;
        }
        c[i+j-1]=x;
    }
    c[0]=a[0]+b[0];
    while (c[0]>1&&c[c[0]]==0) c[0]--;
}

int main()
{
    while (getline(cin,s1))
    {
        getline(cin,s2);
        memset(a,0,sizeof(a));
        change(s1,a);
        memset(b,0,sizeof(b));
        change(s2,b);
        memset(c,0,sizeof(c));
        mul(a,b,c);
        for (int i=c[0];i>0;i--)
            cout<<c[i];
        cout<<endl;
    }
    return 0;
}
