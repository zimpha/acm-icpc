#include <cstdio>
#include <cstring>

const int MAXN=1005;

int ans[MAXN];
int n;

int main()
{
	freopen("neg.in", "r", stdin);
	freopen("neg.out", "w", stdout);
	scanf("%d", &n);
	memset(ans, 0, sizeof(ans));
	ans[0]=1000; ans[1]=1;
	while (n--)
	{
		int x=0;
		for (int i=1; i<=ans[0]; i++)
		{
			int tmp=x*10+ans[i];
			ans[i]=tmp/2;
			x=tmp%2;
		}
	}
	while (ans[ans[0]]==0) ans[0]--;
	if (n==0) puts("1");
	else
	{
		printf("0.");
		for (int i=2; i<=ans[0]; i++)
			printf("%d", ans[i]);
		puts("");
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
