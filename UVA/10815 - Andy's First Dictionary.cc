#include <string>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#define MAXN 500005

using namespace std;

string s[MAXN];

bool cmp(string a,string b)
{
    return (a<b);
}

int main()
{
    int n=-1;
    bool flag=false;
    char c;
    while ((c=getchar())!=EOF)
    {
        if (c>='A'&&c<='Z') c=c+'a'-'A';
        if (c>='a'&&c<='z')
        {
            if (!flag)
            {
                n++;
                flag=true;
                s[n]+=c;
            }
            else s[n]+=c;
        }
        else flag=false;
    }
    n++;
    sort(s,s+n,cmp);
    cout<<s[0]<<endl;
    for (int i=1;i<n;i++)
        if (s[i]!=s[i-1]) cout<<s[i]<<endl;
    return 0;
}
