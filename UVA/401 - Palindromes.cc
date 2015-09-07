#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

const char rev[]="A   3  HIL JM O   2TUVWXY51SE Z  8 ";
string str;

bool p(string str)
{
    int i,n;
    n=str.size();
    for (i=0;i<n;i++)
    {
        if (str[i]=='0') str[i]='O';
        if (str[n-i-1]=='0') str[n-i-1]='O';
        if (str[i]!=str[n-i-1]) return 0;
    }
    return 1;
}

bool r(string str)
{
    int i,n;
    n=str.size();
    for (i=0;i<n;i++)
    {
        if (str[i]=='0') str[i]='O';
        if (str[n-i-1]=='0') str[n-i-1]='O';
        char ch=str[i];
        if (ch>='A'&&ch<='Z') ch=rev[ch-'A'];
        else
            if (ch>'0'&&ch<='9') ch=rev[ch-'1'+26];
        if (ch!=str[n-i-1]) return 0;
    }
    return 1;
}

int main()
{
    while (cin>>str)
    {
        bool fa=p(str);
        bool fb=r(str);
        cout<<str+" -- ";
        if (fa&&fb) cout<<"is a mirrored palindrome."<<endl;
        if (fa&&!fb) cout<<"is a regular palindrome."<<endl;
        if (!fa&&fb) cout<<"is a mirrored string."<<endl;
        if (!fa&&!fb) cout<<"is not a palindrome."<<endl;
        cout<<endl;
    }
    return 0;
}
