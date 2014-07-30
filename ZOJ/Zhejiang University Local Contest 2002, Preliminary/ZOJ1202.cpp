#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN=20;

int a[MAXN], fact[MAXN], cnt[MAXN];
int N;

int choose(int n, int m)
{
	int ret=1;
	for (int i=0; i<m; i++) ret*=(n-i);
	for (int i=0; i<m; i++) ret/=(i+1);
	return ret;
}

int main()
{
	while (cin >> N)
	{
		int sum=0;
		memset(cnt, 0, sizeof(cnt));
		fact[0]=1;
		for (int i=1; i<=N; i++) fact[i]=i*fact[i-1];
		for (int i=0; i<N; i++)
		{
			cin >> a[i];
			sum+=a[i];
			cnt[a[i]]++;
		}
		int ret=1;
		for (int i=0; i<N; i++)
		{
			ret*=choose(sum, a[i]);
			sum-=a[i];
		}
		for (int i=0; i<=12; i++)
			ret/=fact[cnt[i]];
		cout << ret << endl;
	}
	return 0;
}
