#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long LL;

int N,M;
vector <int> E[1111];
int h[1111],b[1111],s[1111];

inline void bfs(){
    queue <int> Q;
    Q.push(1); h[1]=1;
    while (!Q.empty()){
        int u=Q.front(); Q.pop();
        for (int i=0; i<E[u].size(); i++){
            int v=E[u][i];
            if (!h[v]){
                h[v]=1; Q.push(v);
            }
        }
    }
}

int main(){
    //freopen("in","r",stdin);
    while (scanf("%d%d",&N,&M)!=EOF){
        int i,j,k;
        for (i=1; i<=N; i++) E[i].clear();
        for (i=1; i<=M; i++){
            int x,y;
            scanf("%d%d",&x,&y);
            if (x>y) swap(x,y);
            E[x].push_back(y);
        }
        memset(s,0,sizeof(s));
        memset(b,0,sizeof(b));
        b[1]=1; s[1]=1;
        for (i=2; i<=N; i++) if (b[i]==0){
            memset(h,0,sizeof(h));
            h[i]=1; b[i]=i; s[i]=1;
            bfs();
            for (j=i+1; j<=N; j++)
                if (!h[j]){
                    b[j]=i; s[i]++;
                }
        }
        int rst=0;
        for (i=1; i<=N; i++){
            rst+=s[i]*(N-s[i]);
            //cout << i << ' ' << s[i] << endl;
        }
        cout << rst/2 << endl;
    }
    return 0;
}
