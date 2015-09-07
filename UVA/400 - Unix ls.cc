#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN=105;

string file[MAXN];
int n;

int main()
{
    while (scanf("%d",&n)==1)
    {
	int width=0;
	for (int i=1; i<=n; i++)
	{
	    cin >> file[i];
	    if (file[i].size()>width) width=file[i].size();
	}
	sort(file+1,file+n+1);
	int col,row;
	width+=2; col=62/width;
	row=n/col;
	if (n%col) row++;
	for (int i=1; i<=60; i++) 
	    cout << "-";
	cout << endl;
	for (int i=1; i<=row; i++)
	{
	    for (int j=1,no=i; j<=col; j++,no+=row)
	    {
		if (no>n) break;
		int len=file[no].size();
		cout << file[no];
		for (int k=len; k<width; k++)
		    cout << " ";
	    }
	    cout << endl;
	}
    }
    return 0;
}
