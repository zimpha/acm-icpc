#include <cmath>
#include <cstdio>
#include <cstring>

int main()
{
	int w, d, z;
	int cas=0;
	while (scanf("%d%d", &w, &d)==2&&w)
	{
		double y=5730.0*log(810.0*w/d)/log(2);
		if (y<10000) z=100*floor(y/100.0+0.5);
		else z=1000*floor(y/1000.0+0.5);
		printf("Sample #%d\n", ++cas);
		printf("The approximate age is %d years.\n\n", z);
	}
	return 0;
}
