#include <map>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

map<string, string> mp;
string st;

void getdict()
{
	mp.clear();
	string s1, s2;
	while (getline(cin, st))
	{
		if (st=="") break;
		int pos=st.find(' ');
		s1=st.substr(0, pos);
		s2=st.substr(pos+1, st.length()-pos-1);
		mp[s2]=s1;
	}
}

int main()
{
	getdict();
	while (cin >> st)
	{
		map<string, string>::iterator it;
		it=mp.find(st);
		if (it==mp.end()) cout << "eh" << endl;
		else cout << it->second << endl;
	}
	return 0;
}
