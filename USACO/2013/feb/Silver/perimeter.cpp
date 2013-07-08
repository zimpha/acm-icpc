#include <map>
#include <cstdio>
#include <cstring>

using namespace std;

const int dy[]={1, 0, -1, 0};
const int dx[]={0, 1, 0, -1};
const int inf=100000000;

map<int, map<int, int> > hash;
int N;

int main()
{
	freopen("perimeter.in", "r", stdin);
	freopen("perimeter.out", "w", stdout);
	hash.clear();
	scanf("%d", &N);
	int sx=inf, sy=inf;
	for (int i=0; i<N; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		hash[y][x]=1;
		if (y<sy||(y==sy&&x<sx)) sy=y, sx=x;
	}
	int d=0, x=sx, y=sy;
	int ret=0;
	do
	{
		y+=dy[d], x+=dx[d], ret++;
		for (d=(d+3)%4; ; d=(d+1)%4)
			if ((d==0 && hash[y][x])||(d==1 && hash[y-1][x])||
			(d==2 && hash[y-1][x-1])||(d==3 && hash[y][x-1])) 
				break;
	}while (y!=sy || x!=sx);
	printf("%d\n", ret);
	fclose(stdin); fclose(stdout);
	return 0;
}
