#include <cstdio>
#include <algorithm>

using namespace std;

int n,g;
int a[110000],now,ans,t,pin,tot;

int main()
{
	while(scanf("%d%d",&n,&g) == 2)
	{
		t = 0;
		tot = ans = now = 0;
		pin = 0;
		for(int i = 0;i < n;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			if (x > y) now += 3; else
			if (x == y)
			{
				pin++;
			} else
			{
				a[t++] = y - x;
			}
		}
		sort(a,a+t);
		//printf("%d\t",now);
		ans = now + pin + min(pin,g) * 2;
		for(int i = 0;i < t && a[i] <= g;i++)
		{
			g -= a[i];
			pin++;
			tot = now + pin + min(pin,g) * 2;
			ans = max(ans,tot);
		}
		printf("%d\n",ans);
	}
	return 0;
}
