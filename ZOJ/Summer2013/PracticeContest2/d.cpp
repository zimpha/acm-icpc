#include <cstdio>
#include <cstring>
#include <algorithm>

using std::swap;

int x1, x2, y1, y2;

int main()
{
	int test;
	scanf("%d", &test);
	while (test--)
	{
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		if (x1>x2) swap(x1,x2);
		if (y1>y2) swap(y1,y2);
		int count=-2;
		for (int i=x1; i<=x2; i++)
			for (int j=y1; j<=y2; j++)
				if ((i-x1)*(y2-y1)==(j-y1)*(x2-x1)) count++;
		printf("%d\n", count);
	}
	return 0;
}
