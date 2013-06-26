#include <cstdio>
#include <cstring>

const int MAXN=100;
const int inf=100000000;
const int cost[5][5]={1,1,1,1,1,1,3,5,7,5,1,5,3,5,7,1,7,5,3,5,1,5,7,5,3};

struct node
{
	int l, r, p;
};

node p[MAXN][5][5][3];
int dp[MAXN][5][5][3];
int a[MAXN];
int n;

void print(int n, int pl, int pr, int pp)
{
	if (n==0) return;
	print(n-1,p[n][pl][pr][pp].l,p[n][pl][pr][pp].r,p[n][pl][pr][pp].p);
	if (pp==0) putchar('.');
	else if (pp==1) putchar('L');
	else putchar('R');
}

bool crossl(int l, int r)
{
	if ((l==1||l==3)&&r==4) return true;
	else return false;
}

bool crossr(int l, int r)
{
	if ((r==1||r==3)&&l==2) return true;
	else return false;
}

void update(int n, int l, int r, int pp)
{
	if (!crossl(l,r)||(l==pp)) //left foot
	{
		if (dp[n][pp][r][1]>dp[n-1][l][r][0]+1)
		{
			dp[n][pp][r][1]=dp[n-1][l][r][0]+1;
			p[n][pp][r][1].l=l;
			p[n][pp][r][1].r=r;
			p[n][pp][r][1].p=0;
		}
		if (dp[n][pp][r][1]>dp[n-1][l][r][2]+1)
		{
			dp[n][pp][r][1]=dp[n-1][l][r][2]+1;
			p[n][pp][r][1].l=l;
			p[n][pp][r][1].r=r;
			p[n][pp][r][1].p=2;
		}
		if (dp[n][pp][r][1]>dp[n-1][l][r][1]+cost[l][pp])
		{
			dp[n][pp][r][1]=dp[n-1][l][r][1]+cost[l][pp];
			p[n][pp][r][1].l=l;
			p[n][pp][r][1].r=r;
			p[n][pp][r][1].p=1;
		}
	}
	if (!crossr(l,r)||(r==pp)) //right foot
	{
		if (dp[n][l][pp][2]>dp[n-1][l][r][0]+1)
		{
			dp[n][l][pp][2]=dp[n-1][l][r][0]+1;
			p[n][l][pp][2].l=l;
			p[n][l][pp][2].r=r;
			p[n][l][pp][2].p=0;
		}
		if (dp[n][l][pp][2]>dp[n-1][l][r][1]+1)
		{
			dp[n][l][pp][2]=dp[n-1][l][r][1]+1;
			p[n][l][pp][2].l=l;
			p[n][l][pp][2].r=r;
			p[n][l][pp][2].p=1;
		}
		if (dp[n][l][pp][2]>dp[n-1][l][r][2]+cost[r][pp])
		{
			dp[n][l][pp][2]=dp[n-1][l][r][2]+cost[r][pp];
			p[n][l][pp][2].l=l;
			p[n][l][pp][2].r=r;
			p[n][l][pp][2].p=2;
		}
	}
}

int main()
{
	char st[MAXN];
	while (gets(st)&&st[0]!='#')
	{
		n=strlen(st);
		memset(a,0,sizeof(a));
		for (int i=0; i<n; i++)
			if (st[i]=='U') a[i+1]=1;
			else if (st[i]=='R') a[i+1]=2;
			else if (st[i]=='D') a[i+1]=3;
			else if (st[i]=='L') a[i+1]=4;

		for (int i=0; i<MAXN; i++)
			for (int j=0; j<5; j++)
				for (int k=0; k<5; k++)
					for (int l=0; l<3; l++)
						dp[i][j][k][l]=inf;
		dp[0][4][2][0]=0;
		for (int i=0; i<n; i++)
			for (int j=1; j<5; j++)
				for (int k=1; k<5; k++)
					if (j!=k)
					{
						if (a[i+1]) update(i+1,j,k,a[i+1]);
						else
						{
							for (int l=1; l<5; l++) update(i+1,j,k,l);
							for (int l=0; l<3; l++)
								if (dp[i+1][j][k][0]>dp[i][j][k][l])
								{
									dp[i+1][j][k][0]=dp[i][j][k][l];
									p[i+1][j][k][0].l=j;
									p[i+1][j][k][0].r=k;
									p[i+1][j][k][0].p=l;
								}
						}
					}
		int ret=inf;
		int pl, pr, pp;
		for (int i=1; i<5; i++)
			for (int j=1; j<5; j++)
				for (int k=0; k<3; k++)
					if (i!=j&&ret>dp[n][i][j][k])
					{
						ret=dp[n][i][j][k];
						pl=i; pr=j; pp=k;
					}
		print(n,pl,pr,pp);
		puts("");
	}
	return 0;
}
