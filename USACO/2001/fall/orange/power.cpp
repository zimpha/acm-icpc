#include <cstdio>

int main()
{
	int n;
	freopen("power.in", "r", stdin);
	freopen("power.out", "w", stdout);
	scanf("%d", &n);
	printf("%d\n", 1<<n);
	fclose(stdin); fclose(stdout);
}
