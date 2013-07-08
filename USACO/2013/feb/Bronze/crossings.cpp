#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN=100005;

struct node
{
	int a, b;
};

node cow[MAXN];
node cnt[MAXN];
int N;

bool cmp(node a, node b)
{
	if (a.a==b.a) return (a.b<b.b);
	else return (a.a<b.a);
}

int main()
{
	freopen("crossings.in", "r", stdin);
	freopen("crossings.out", "w", stdout);
	scanf("%d", &N);
	for (int i=0; i<N; i++)
		scanf("%d%d", &cow[i].a, &cow[i].b);
	sort(cow, cow+N, cmp);
	cnt[0].a=cow[0].b;
	for (int i=1; i<N; i++)
		cnt[i].a=max(cnt[i-1].a, cow[i].b);
	cnt[N-1].b=cow[N-1].b;
	for (int i=N-2; i>=0; i--)
		cnt[i].b=min(cnt[i+1].b, cow[i].b);
	int ret=0;
	for (int i=0; i<N; i++)
	{
		bool flag=true;
		if (i!=0 && cnt[i-1].a>cow[i].b) flag=false;
		if (i!=N-1 && cnt[i+1].b<cow[i].b) flag=false;
		if (flag) ret++;
	}
	printf("%d\n", ret);
	fclose(stdin); fclose(stdout);
	return 0;
}
