#include <cctype>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN=105;

struct Team
{
    string name;
    int point;
    int game;
    int win,tie,loss;
    int gd,gs,ga;
};

Team team[MAXN];
int n,m;

string lower(string a)
{
    for (int i=0; i<a.size(); i++)
	if (isalpha(a[i])) a[i]=tolower(a[i]);
    return a;
}

bool cmp(Team a,Team b)
{
    a.name=lower(a.name);
    b.name=lower(b.name);
    if (a.point==b.point)
	if (a.win==b.win)
	    if (a.gd==b.gd)
		if (a.gs==b.gs)
		    if (a.game==b.game) return (a.name<b.name);
		    else return (a.game<b.game);
		else return (a.gs>b.gs);
	    else return (a.gd>b.gd);
	else return (a.win>b.win);
    else return (a.point>b.point);
}

int find(string s)
{
    for (int i=0; i<n; i++)
	if (s==team[i].name) return i;
}

int main()
{
    int test;
    scanf("%d\n",&test);
    while (test--)
    {
	string s1,s2;
	char s[100];
	getline(cin,s1);
	cout << s1 << endl;
	scanf("%d\n",&n);
	for (int i=0; i<n; i++)
	{
	    getline(cin,team[i].name);
	    team[i].point=team[i].game=0;
	    team[i].win=team[i].tie=team[i].loss=0;
	    team[i].gd=team[i].gs=team[i].ga=0;
	}
	scanf("%d\n",&m);
	while (m--)
	{
	    s1=s2="";
	    gets(s);
	    int gs1,gs2,t1,t2;
	    for (int i=0; i<strlen(s); i++)
		if (s[i]!='#') s1+=s[i];
		else
		{
		    sscanf(&s[i++],"#%d@%d#",&gs1,&gs2);
		    while (s[i]!='#') i++; i++;
		    while (i<strlen(s)) s2+=s[i],i++;
		    break;
		}
	    t1=find(s1); t2=find(s2);
	    team[t1].game++; team[t2].game++;
	    team[t1].gs+=gs1; team[t1].ga+=gs2; team[t1].gd+=gs1-gs2;
	    team[t2].gs+=gs2; team[t2].ga+=gs1; team[t2].gd+=gs2-gs1;
	    if (gs1>gs2)
	    {
		team[t1].win++, team[t2].loss++;
		team[t1].point+=3;
	    }
	    else if (gs1<gs2)
	    {
		team[t1].loss++, team[t2].win++;
		team[t2].point+=3;
	    }
	    else
	    {
		team[t1].tie++, team[t2].tie++;
		team[t1].point++, team[t2].point++;
	    }

	}
	sort(team,team+n,cmp);
	for (int i=0; i<n; i++)
	{
	    cout << i+1 << ") " << team[i].name;
	    printf(" %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n",team[i].point,team[i].game,team[i].win,team[i].tie,team[i].loss,team[i].gd,team[i].gs,team[i].ga);
	}
	if (test) cout << endl;
    }
    return 0;
}
