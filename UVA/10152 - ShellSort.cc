#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

const int MAXN=1000;

string turtle[MAXN];
int pos[MAXN];
int n;

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
	cin >> n; getchar();
	for (int i=0; i<n; i++)
	    getline(cin,turtle[i]);
	string tmp;
	for (int i=0; i<n; i++)
	{
	    getline(cin,tmp);
	    for (int j=0; j<n; j++)
		if (tmp==turtle[j])
		{
		    pos[i]=j;
		    break;
		}
	}
	n--;
	while (n>0&&pos[n]>pos[n-1]) n--;
	for (int i=n-1; i>=0; i--)
	    cout << turtle[pos[i]] << endl;
	cout << endl;
    }
}
