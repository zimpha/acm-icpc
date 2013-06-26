#include <cstdio>
#include <cstring>

char s[100];
int n;

int main()
{
	int count=0;
	while (scanf("%s", s)==1&&s[0]!='#')
	{
		if (s[0]=='0')
		{
			printf("%d\n", count);
			count=0;
		}
		else
		{
			int m;
			scanf("%s%d", s, &m); scanf("%s", s);
			switch (s[0])
			{
				case 'F': 
					m+=m;
					break;
				case 'B':
					if (m&1) m+=(m+1)/2;
					else m+=m/2;
					break;
				case 'Y':
					if (m<500) m=500;
					break;
			}
			count+=m;
		}
	}
	return 0;
}
