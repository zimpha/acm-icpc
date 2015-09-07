#include <cstdio>
#include <cstring>

int main()
{
	int T, G, L;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &G, &L);
		if (L%G==0) printf("%d %d\n", G, L);
		else puts("-1");
	}
	return 0;
}

