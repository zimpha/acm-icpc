#include <cstdio>
#include <string>

const int MAXN=1005;

double score[MAXN];
double ave;
int n;

int main()
{
	int test;
	scanf("%d", &test);
	while (test--)
	{
		scanf("%d", &n);
		ave=0;
		for (int i=0; i<n; i++)
		{
			scanf("%lf", score+i);
			ave+=score[i];
		}
		ave/=1.0*n;
		double count=0;
		for (int i=0; i<n; i++)
			if (score[i]>ave) count++;
		printf("%.3f%%\n", count*100.0/n);
	}
	return 0;
}
