#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAXN 50005

struct node
{
	int x, y;
};

node pos[MAXN];
int N, K;

bool cmp(node a, node b)
{
	if (a.x==b.x) return (a.y<b.y);
	else return (a.x<b.x);
}

int main()
{
	freopen("squares.in", "r", stdin);
	freopen("squares.out", "w", stdout);
	scanf("%d%d", &N, &K);
	for (int i=0; i<N; i++)
		scanf("%d%d", &pos[i].x, &pos[i].y);
	sort(pos, pos+N, cmp);
	vector<pair<int, int> > res;
	res.clear();
	for (int i=0; i<N&&res.size()<2; i++)
	{
		for (int j=i+1; j<N&&pos[j].x<pos[i].x+K&&res.size()<2; j++)
			if (abs(pos[j].y-pos[i].y)<K)
				res.push_back(make_pair(i, j));
	}
	long long ret=0;
	if (res.size()>1) ret=-1;
	else if (res.size()==1)
	{
		node a=pos[res[0].first];
		node b=pos[res[0].second];
		long long dx=abs(a.x-b.x);
		long long dy=abs(a.y-b.y);
		ret=(long long)(K-dx)*(K-dy);
	}
	printf("%lld\n", ret);
	fclose(stdin); fclose(stdout);
	return 0;
}
