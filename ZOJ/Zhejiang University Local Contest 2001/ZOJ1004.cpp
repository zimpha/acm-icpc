#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

string src, target;

void dfs(int t, string stk, int h, string now, string opt)
{
	if (t==0&&h==src.length())
	{
		if (now==target) cout << opt << endl;
		return;
	}
	if (h<src.length()) 
	{
		stk[t+1]=src[h];
		dfs(t+1, stk, h+1, now, opt+"i ");
	}
	if (t>0) dfs(t-1, stk, h, now+stk[t], opt+"o ");
}

int main()
{
	while (cin >> src >> target)
	{
		puts("[");
		if (src.length()==target.length())
			dfs(0, src+" ", 0, "", "");
		puts("]");
	}
	return 0;
}
