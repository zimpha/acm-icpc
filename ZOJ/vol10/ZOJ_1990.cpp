#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN=3005;

char tmp[MAXN];
int n;

string build(int i)
{
	vector<string>v;
	string ret;
	while (i<n&&tmp[i]=='0')
	{
		v.push_back('0'+build(i+1));
		i+=v.back().size();
	}
	sort(v.begin(),v.end());
	ret.clear();
	for (int k=0; k<v.size(); k++)
		ret+=v[k];
	return ret+'1';
}

int main()
{
	int test;
	scanf("%d", &test);
	while (test--)
	{
		scanf("%s", tmp);
		n=strlen(tmp);
		string a=build(0);
		scanf("%s", tmp);
		n=strlen(tmp);
		string b=build(0);
		if (a==b) printf("same\n");
		else printf("different\n");

	}
	return 0;
}
