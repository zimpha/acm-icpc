#include <cstdio>

int main()
{
	int dna[10],now[40],next[40];
	int test;
	scanf("%d",&test);
	while (test--)
	{
		for (int i=0;i<10;i++)
			scanf("%d",&dna[i]);
		for (int i=0;i<40;i++)
			next[i]=0;
		next[19]=1;
		for (int day=0;day<50;day++)
		{
			for (int i=0;i<40;i++)
				now[i]=next[i];
			for (int i=0;i<40;i++)
			{
				if (now[i]==0) printf(" ");
				else if (now[i]==1) printf(".");
				else if (now[i]==2) printf("x");
				else printf("W");
			}
			printf("\n");
			next[0]=dna[now[0]+now[1]];
			next[39]=dna[now[39]+now[38]];
			for (int i=1;i<39;i++)
				next[i]=dna[now[i]+now[i-1]+now[i+1]];
		}
		if (test) printf("\n");
	}
	return 0;
}
