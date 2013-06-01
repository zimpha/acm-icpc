#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN=105;

char cows[MAXN];
int diff[3][3];
int a, b, c, n;

int main()
{
	freopen("picky.in", "r", stdin);
	freopen("picky.out", "w", stdout);
	
	scanf("%s", cows+1);
	n=strlen(cows+1);
	a=b=c=0;
	for (int i=1; i<=n; i++)
		if (cows[i]=='A') a++;
		else if (cows[i]=='B') b++;
		else c++;
	memset(diff, 0, sizeof(diff)); 
	for (int i=1; i<=a; i++)
		if (cows[i]=='B') diff[0][1]++;
		else if (cows[i]=='C') diff[0][2]++;
	for (int i=a+1; i<=a+b; i++)
		if (cows[i]=='A') diff[1][0]++;
		else if (cows[i]=='C') diff[1][2]++;
	for (int i=a+b+1; i<=a+b+c; i++)
		if (cows[i]=='A') diff[2][0]++;
		else if (cows[i]=='B') diff[2][1]++;
	int ret=0, tmp;
	for (int i=0; i<3; i++)
		for (int j=i+1; j<3; j++)
		{
			tmp=min(diff[i][j], diff[j][i]);
			ret+=tmp;
			diff[i][j]-=tmp; diff[j][i]-=tmp;
		}
	tmp=0;
	for (int i=0; i<3; i++)
		for (int j=i+1; j<3; j++)
			tmp+=diff[i][j]+diff[j][i];
	ret+=2*tmp/3;
	printf("%d\n", ret);
	fclose(stdin); fclose(stdout);
	return 0;
}
