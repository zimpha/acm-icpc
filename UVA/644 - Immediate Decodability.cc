#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

const int MAXN=100;

string a[MAXN];
int n;

bool prefix(string a,string b)
{
    if (a.size()>b.size()) return false;
    for (int i=0; i<a.size(); i++)
	if (a[i]!=b[i]) return false;
    return true;
}

int main()
{
    int cas=0;
    n=0;
    while (cin >> a[n])
    {
	if (a[n]=="9")
	{
	    bool flag=true;
	    for (int i=0; i<n; i++)
	    {
		for (int j=0; j<n; j++)
		    if (i!=j&&prefix(a[i],a[j]))
		    {
			flag=false;
			break;
		    }
		if (!flag) break;
	    }
	    if (flag) printf("Set %d is immediately decodable\n",++cas);
	    else printf("Set %d is not immediately decodable\n",++cas);
	    n=0;
	}
	else n++;
    }
}
