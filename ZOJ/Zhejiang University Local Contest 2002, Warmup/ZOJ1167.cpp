#include <map>
#include <vector>
#include <string>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

typedef map<string, string>::iterator MIT;

map<string, string> mp;
vector<MIT> V;

inline bool cmp(const MIT& a, const MIT& b)
{
	if (a->first.size()<b->first.size()) return 1;
	if (a->first.size()>b->first.size()) return 0;
	return a->first<b->first;
}

int main()
{
	string st, v, s;
	while (cin >> st)
	{
		bool flag=true;
		mp.clear();
		while (1)
		{
			if (st=="()") break;
			int pos=st.find(',');
			v=st.substr(1, pos-1);
			s=st.substr(pos+1, st.size()-pos-2);
			if (mp.find(s)!=mp.end()) flag=false;
			else mp.insert(make_pair(s, v));
			cin >> st;
		}
		V.clear();
		if (!flag) {puts("not complete"); continue;};
		if (mp.empty()) {puts(""); continue;};
		for (MIT it=mp.begin(); flag&&it!=mp.end(); ++it)
		{
			V.push_back(it);
			s=it->first; v=it->second;
			if (v==""||(s!=""&&mp.find(s.substr(0, s.size()-1))==mp.end()))
				flag=false;
		}
		if (!flag) {puts("not complete"); continue;};
		sort(V.begin(), V.end(), cmp);
		for (int i=0; i<(int)V.size(); i++)
		{
			cout << V[i]->second;
			if (i!=(int)V.size()-1) cout << " ";
			else cout << endl;
		}
	}
	return 0;
}
