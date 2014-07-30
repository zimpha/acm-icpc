#include <map>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

#define MP make_pair
#define PB push_back

using namespace std;

typedef pair<int, int> PII;

map<pair<PII, PII>, int> mp;
vector<vector<PII> >ans;
vector<PII> point;

bool check(PII a, PII b, PII c)
{
	if ((b.second-c.second)*(a.first-c.first)==(a.second-c.second)*(b.first-c.first)) return true;
	return false;
}

int main()
{
	int x, y;
	while ((cin >> x >> y))
	{
		if (x==0&&y==0) break;
		point.clear();
		do
		{
			point.PB(MP(x, y));
			cin >> x >> y;
		}while ((x!=0||y!=0));
		ans.clear(); mp.clear();
		for (int i=0; i<(int)point.size(); i++)
			for (int j=i+1; j<(int)point.size(); j++)
			{
				vector<PII> tmp; tmp.clear();
				for (int k=0; k<(int)point.size(); k++)
					if (check(point[i], point[j], point[k]))
						tmp.PB(point[k]);
				if ((int)tmp.size()==2) continue;
				sort(tmp.begin(), tmp.end());
				PII a=tmp[0], b=tmp[tmp.size()-1];
				if (mp.find(MP(a, b))==mp.end())
				{
					mp.insert(MP(MP(a, b), 1));
					ans.PB(tmp);
				}
			}
		sort(ans.begin(), ans.end());
		if (ans.size()==0) cout << "No lines were found" << endl;
		else
		{
			cout << "The following lines were found:" << endl;
			for (int i=0; i<(int)ans.size(); ++i)
			{
				vector<PII> ret=ans[i];
				for (int j=0; j<(int)ret.size(); ++j)
					printf("(%4d,%4d)", ret[j].first, ret[j].second);
				puts("");
			}
		}
	}
	return 0;
}
