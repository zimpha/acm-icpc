#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN=10005;

int a[MAXN];
int n,q;

int find(int x)
{
    int l=1,r=n;
    while (l<=r)
    {
	int m=(l+r)>>1;
	if (a[m]==x&&a[m-1]<x) return m;
	if (a[m]>=x) r=m-1;
	else l=m+1;
    }
    return 0;
}

bool cmp(int a,int b)
{
    return a<b;
}

int main()
{
    int cas=0;
    while ((cin >> n >> q)&&n)
    {
	a[0]=-1;
	for (int i=1; i<=n; i++) 
	    cin >> a[i];
	sort(a+1,a+1+n);
	cout << "CASE# " << ++cas << ":" <<endl;
	while (q--)
	{
	    int x;
	    cin >> x;
	    int y=find(x);
	    if (y) cout << x << " found at " << y <<endl;
	    else cout << x << " not found" << endl;
	}
    }
    return 0;
}
