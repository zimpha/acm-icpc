#include <cstdio>
#include <cstring>

int main()
{
    freopen("tri.in", "r", stdin);
    freopen("tri.out", "w", stdout);
    
    int n;
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    {
	for (int j=i; j<=2*i-1; j++)
	    printf("%d", j%10);
	for (int j=2*i-2; j>=i; j--)
	    printf("%d", j%10);
	putchar('\n');
    }
    fclose(stdin); fclose(stdout);
    return 0;
}
