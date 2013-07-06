#include <map>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN=100005;

struct node
{
	int l, r;
};

map<int, int>Index;
node seg[MAXN];
int hash[MAXN*2];
int sum[MAXN];
int N, M;

int main()
{
	freopen("paint.in", "r", stdin);
	freopen("paint.out", "w", stdout);
	scanf("%d", &N);
	int now=0; M=0;
	for (int i=0; i<N; i++)
	{
		int len;
		char ch;
		scanf("%d %c", &len, &ch);
		if (ch=='R')
		{
			seg[i].l=now; seg[i].r=now+len;
			hash[M++]=seg[i].l; hash[M++]=seg[i].r;
			now=now+len;
		}
		else
		{
			seg[i].l=now-len; seg[i].r=now;
			hash[M++]=seg[i].l; hash[M++]=seg[i].r;
			now=now-len;
		}
	}
	sort(hash, hash+M);
	Index.clear();
	int cnt=1; Index[hash[0]]=0;
	for (int i=1; i<M; i++)
		if (hash[i]!=hash[i-1])
		{
			hash[cnt]=hash[i];
			Index[hash[i]]=cnt++;
		}
	M=cnt;
	memset(sum, 0, sizeof(sum));
	for (int i=0; i<N; i++)
	{
		int a=Index[seg[i].l];
		int b=Index[seg[i].r];
		sum[a]++; sum[b]--;
	}
	cnt=0;
	for (int i=1; i<M; i++)
	{
		if (sum[i-1]>1) cnt+=hash[i]-hash[i-1];
		sum[i]+=sum[i-1];
	}
	printf("%d\n", cnt);
	fclose(stdin); fclose(stdout);
	return 0;
}
