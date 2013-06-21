#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN=1005;
const int SIZE=30;

struct node
{
	int n;
	string str;
};

node num[MAXN];
int n, m;

bool cmp(node a, node b)
{
	return (a.str<b.str);
}

string tostr(int n)
{
	string ret, tmp;
	ret.clear();
	do
	{
		switch (n%10)
		{
			case 0: tmp="zero"; break;
			case 1: tmp="one"; break;
			case 2: tmp="two"; break;
			case 3: tmp="three"; break;
			case 4: tmp="four"; break;
			case 5: tmp="five"; break;
			case 6: tmp="six"; break;
			case 7: tmp="seven"; break;
			case 8: tmp="eight"; break;
			case 9: tmp="nine"; break;
		}
		ret=tmp+' '+ret;
		n/=10;
	}while (n);
	return ret;
}

int main()
{
	freopen("dictnum.in", "r", stdin);
	freopen("dictnum.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i=n; i<=m; i++)
	{
		num[i-n].n=i;
		num[i-n].str=tostr(i);
	}
	sort(num, num+m-n+1, cmp);
	printf("%d %d\n", num[0].n, num[m-n].n);
	fclose(stdin); fclose(stdout);
}
