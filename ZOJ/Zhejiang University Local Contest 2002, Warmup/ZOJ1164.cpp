#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int g=34943;

vector<char> v;

void change(int n)
{
	v.clear();
	for (int i=0; i<4; ++i, n/=16)
	{
		int t=n%16;
		if (t>9) v.push_back('A'+t-10);
		else v.push_back('0'+t);
	}
}

int main()
{
	string st;
	while (getline(cin, st))
	{
		if (st=="#") break;
		int val=0;
		for (int i=0; i<(int)st.size(); ++i)
			val=(val*256+(int)st[i])%g;
		val=val*256%g*256%g;
		for (int i=0; i<g; i++)
			if ((val+i)%g==0)
			{
				change(i);
				cout << v[3] << v[2] << " " << v[1] << v[0] << endl;
				break;
			}
	}
	return 0;
}
