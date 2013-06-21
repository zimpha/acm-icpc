#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN=20005;
const int SIZE=105;

struct node
{
	int val;
	char *str;
};

node word[MAXN];
char str[SIZE];
int n;

bool cmp(node a, node b)
{
	return (strcmp(a.str, b.str)<0);
}

int prefix(char *a, char *b)
{
	for (int i=0; ; i++)
	{
		if (a[i]!=b[i]) return i;
	}
	return 0;
}

int main()
{
	freopen("prefix.in", "r", stdin);
	freopen("prefix.out", "w", stdout);
	scanf("%d", &n);
	for (int i=0; i<n; i++)
	{
		scanf("%s", str);
		word[i].str=(char *)malloc(sizeof(str));
		strcpy(word[i].str, str);
		word[i].val=i;
	}
	sort(word, word+n, cmp);
	int ret=0, pos1=n, pos2=n;
	int ans1, ans2;
	for (int i=0; i<n; i++)
	{
		for (int j=i+1; j<n; j++)
		{
			int tmp=prefix(word[i].str, word[j].str);
			if (tmp<ret) break;
			int t1=min(word[i].val, word[j].val);
			int t2=max(word[i].val, word[j].val);
			if (ret==tmp)
			{
				if (t1<pos1||(t1==pos1&&t2<pos2))
				{
					pos1=t1; pos2=t2;
					ans1=i; ans2=j;
				}
			}
			else
			{
				pos1=t1; pos2=t2;
				ans1=i; ans2=j;
			}
			ret=tmp;
		}
	}
	if (word[ans1].val<word[ans2].val)
		printf("%s\n%s\n", word[ans1].str, word[ans2].str);
	else
		printf("%s\n%s\n", word[ans2].str, word[ans1].str);
	fclose(stdin); fclose(stdout);
	return 0;
}
