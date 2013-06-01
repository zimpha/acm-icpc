#include <cstdio>
#include <cstring>

const int MAXN=30;

int main()
{
    freopen("sum.in", "r", stdin);
    freopen("sum.out", "w", stdout);
    
    int ans=0, n;
    scanf("%d", &n);
    for (int i=0; i<(1<<(n-2)); i++)
    {
	int ret=-1;
	for (int j=2; j<n; j++)
	    if (i&(1<<(j-2))) ret+=j;
	    else ret-=j;
	if (ret==n) ans++;
    }
    printf("%d\n", ans);
    fclose(stdin); fclose(stdout);
    return 0;
}
