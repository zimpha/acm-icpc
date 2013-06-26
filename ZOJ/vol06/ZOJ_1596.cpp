#include <cstdio>
#include <cstring>

typedef long long LL;

const int MAXN=10005;

LL ham[MAXN];
LL p1, p2, p3, n;

int main()
{
	while (scanf("%lld%lld%lld%lld", &p1, &p2, &p3, &n)==4)
	{
	ham[0]=1;
	int n1, n2, n3;
	n1=n2=n3=0;
	for (int i=1; i<=n; i++)
	{
		if (ham[n1]*p1<ham[n2]*p2) ham[i]=ham[n1]*p1;
		else ham[i]=ham[n2]*p2;
		if (ham[n3]*p3<ham[i]) ham[i]=ham[n3]*p3;
		if (ham[i]==ham[n1]*p1) n1++;
		if (ham[i]==ham[n2]*p2) n2++;
		if (ham[i]==ham[n3]*p3) n3++;
	}
	printf("%lld\n", ham[n]);
	}
	return 0;
}
