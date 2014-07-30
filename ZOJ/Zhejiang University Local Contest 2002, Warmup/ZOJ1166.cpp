#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN=2005;
const int MAXM=30;

string dict[MAXN];
string word[MAXM];
string phrase, out;
int cnt[26];
int N, M;

void dfs(int cur, int sum, string st)
{
	if (sum==0)
	{
		if (st!=phrase) cout << out << " =" << st << endl;
		return;
	}
	for (int i=cur; i<N; i++)
	{
		int tmp[26];
		memset(tmp, 0, sizeof(tmp));
		for (int j=0; j<dict[i].length(); j++) tmp[dict[i][j]-'A']++;
		bool flag=true;
		for (int j=0; flag&&j<26; j++)
			if (cnt[j]<tmp[j]) flag=false;
		if (!flag) continue;
		for (int j=0; j<26; j++)
			cnt[j]-=tmp[j], sum-=tmp[j];
		dfs(i, sum, st+" "+dict[i]);
		for (int j=0; j<26; j++)
			cnt[j]+=tmp[j], sum+=tmp[j];
	}
}

int main()
{
	for (N=0; 1; N++)
	{
		getline(cin, dict[N]);
		if (dict[N]=="#") break;
	}
	sort(dict, dict+N);
	while (1)
	{
		getline(cin, out);
		if (out=="#") break;
		M=0; word[0]="";
		memset(cnt, 0, sizeof(cnt));
		for (int i=0; i<out.length(); i++)
		{
			if (out[i]==' ') M++, word[M]="";
			else word[M]=word[M]+out[i], cnt[out[i]-'A']++;
		}
		M++;
		sort(word, word+M);
		phrase="";
		for (int i=0; i<M; i++)
		{
			phrase+=" "+word[i];
		}
		int sum=0;
		for (int i=0; i<26; i++) sum+=cnt[i];
		dfs(0, sum, "");
	}
	return 0;
}
