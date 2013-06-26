#include <cstdio>
#include <cstring>

const int MAXN=1000001;

bool num[MAXN];

int get(int n)
{
	int res=n;
	while (n)
	{
		res+=n%10;
		n/=10;
	}
	return res;
}

int main()
{
	memset(num,0,sizeof(num));
	for (int i=1; i<MAXN; i++)
		if (!num[i])
		{
			printf("%d\n", i);
			int n=i;
			while (1)
			{
				n=get(n);
				if (n>=MAXN||num[n]) break;
				num[n]=true;
			}
		}
	return 0;
}
