#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int rotate(int val, int n)
{
	return (val>>1)|((val&1)<<(n-1));
}

int solve(string form)
{
	int bug = 0;
	map<int, int>bugmap;
	int len=form.size();
	for(int i=0; i<len; i++)
		if (form[i]=='G') bug|=(1<<i);
	for (int cnt=0; ; cnt++)
	{
		bug=bug^rotate(bug, len);
		for (int i=0; i<len; i++)
		{
			map<int,int>::iterator iter=bugmap.find(bug);
			if(iter!=bugmap.end()) return cnt-(*iter).second;
			bug=rotate(bug, len);
		}
		bugmap[bug]=cnt;
	}
}

int main()
{
	int test;
	scanf("%d", &test);
	while (test--)
	{
		string str;
		cin >> str;
		printf("%d\n", solve(str));
	}
	return 0;
}