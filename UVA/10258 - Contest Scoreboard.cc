#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#define INT_MAX 2147483647
#define INT_MIN -2147483648
#define pi acos(-1.0)
#define long long LL
using namespace std;
 
struct Team
{
    Team(int TN, bool P)
    {
        TeamNumber = TN;
        Participating = P;
    }
    int nSolved;
    int PenaltyTime;
    int TeamNumber;
    bool Participating;
};
 
bool compareTeams(Team T1, Team T2)
{
    if (T1.nSolved != T2.nSolved)
        return T1.nSolved > T2.nSolved;
 
    if (T1.PenaltyTime != T2.PenaltyTime)
        return T1.PenaltyTime < T2.PenaltyTime;
 
    return T1.TeamNumber < T2.TeamNumber;
}
int main ()
{
    int N;
 
    scanf("%d\n",&N);
 
    for (int i=0; i<N; i++)
    {
        scanf("\n");
        vector<pair<char,int> > TeamsMessages[101][10];
        vector<Team> Teams;
 
        for (int i=0; i<101; i++)
            Teams.push_back(*(new Team(i, false)));
 
        char input [100];
 
        while(fgets(input,100,stdin) != NULL)
        {
            if (input[0] == '\n') break;
            stringstream s(input);
            int TeamNumber,ProblemNumber;
            pair<char,int> Message;
            char Type;
            s >> TeamNumber >> ProblemNumber >> Message.second >> Message.first;
            Teams[TeamNumber].Participating = true;
            if (Message.first == 'C' || Message.first == 'I')
                TeamsMessages[TeamNumber][ProblemNumber].push_back(Message);
 
        }
 
        for (int j=0; j<Teams.size(); j++)
        {
            Teams[j].PenaltyTime = 0;
            Teams[j].nSolved = 0;
            for (int k=1; k< 10; k++)
            {
                vector<pair<char,int> > Messages = TeamsMessages[j][k];
                int PenaltyTime=0;
 
                for (int h=0; h< Messages.size(); h++)
                {
                    if (Messages[h].first == 'I') PenaltyTime+= 20;
                    else if (Messages[h].first == 'C')
                    {
                        PenaltyTime += Messages[h].second;
                        Teams[j].nSolved++;
                        Teams[j].PenaltyTime += PenaltyTime;
                        break;
                    }
                }
            }
        }
 
        sort(Teams.begin(), Teams.end(), compareTeams);
 
        for (int i=0; i<Teams.size(); i++)
            if (Teams[i].Participating) printf("%d %d %d\n", Teams[i].TeamNumber, Teams[i].nSolved, Teams[i].PenaltyTime);
 
        if (i != N-1) printf("\n");
    }
 
    return 0;
}
