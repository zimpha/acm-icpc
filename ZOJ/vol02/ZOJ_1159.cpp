#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN=100005;

string num[MAXN];
bool flag;
int n;

string change(string a)
{
    string s="";
    for (int i=0; i<a.size(); i++)
	if (a[i]!='-')
	{
	    if (a[i]>='0'&&a[i]<='9') s+=a[i];
	    else
	    {
		switch (a[i])
		{
		    case 'A':case 'B': case 'C':s+='2';break;
		    case 'D':case 'E': case 'F':s+='3';break;
		    case 'G':case 'H': case 'I':s+='4';break;
		    case 'J':case 'K': case 'L':s+='5';break;
		    case 'M':case 'N': case 'O':s+='6';break;
		    case 'P':case 'R': case 'S':s+='7';break;
		    case 'T':case 'U': case 'V':s+='8';break;
		    case 'W':case 'X': case 'Y':s+='9';break;
		}
	    }
	}
    return s;
}

void print(string a,int sum)
{
    for (int i=0; i<3; i++) cout << a[i];
    cout << "-";
    for (int i=3; i<7; i++) cout << a[i];
    cout << " " << sum <<endl;
    flag=true;
}

int main()
{
	int test;
	scanf("%d", &test);
	while (test--)
	{
    	scanf("%d",&n);
		for (int i=0; i<n; i++)
		{
	   		cin >> num[i];
	    	num[i]=change(num[i]);
		}
		sort(num,num+n);
		flag=false;
		for (int i=0; i<n; i++)
		{
	 	   	int sum=0,j;
	  	  	for (j=i; j<n&&num[i]==num[j]; j++)
				sum++;
	    	if (sum>1) print(num[i],sum);
	    	i=j-1;
		}
		if (!flag) printf("No duplicates.\n");
		if (test) puts("");
    }
    return 0;
}
