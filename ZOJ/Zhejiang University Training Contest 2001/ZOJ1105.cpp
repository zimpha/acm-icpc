#include <cmath>
#include <cstdio>
#include <cstring>

char st[10000];

int main()
{
	double x1, y1, x2, y2;
	while (scanf("%lf%lf\n", &x1, &y1)==2)
	{
		double sum=0.0;
		while (gets(st))
		{
			if (strcmp(st, "java")==0) break;
			sscanf(st, "%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
			sum+=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
		}
		int ans=(int)floor(sum/1000*6+0.5);
		printf("%d:%02d\n", ans/60, ans%60);
	}
	return 0;
}
