#include <cstdio>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <algorithm>
#include <map>
#include <ctype.h>
#include <string.h>

#include <assert.h>

using namespace std;

typedef long long LL;
typedef pair<string, int> PII;
typedef pair<int, int> PII2;

#define MAXN 100005

PII s[MAXN];
int n;
int in[MAXN];

int id[MAXN];
int M[MAXN][25];

void RMQ_preprocess(int A[], int N){
    for(int i = 0; i < N; i++ )
        M[i][0] = i;
    for(int j = 1; 1<<j <= N; j++ ){
        for(int i = 0; i + (1<<j) - 1 < N; i++ )
            if(A[M[i][j - 1]] < A[M[i + (1 << (j - 1))][j - 1]])
                M[i][j] = M[i][j - 1];
            else
                M[i][j] = M[i + (1 << (j - 1))][j - 1];
    }
}

int RMQ_getMin(int A[], int left, int right){
    int num = right - left + 1;
    int e = 1;
    int k = 0;
    while(e * 2 <= num) e *= 2, k++;
    int temp = right - e + 1;
    if(A[M[left][k]] <= A[M[temp][k]]){
        return A[M[left][k]];
    } else {
        return A[M[temp][k]];
    }
}

char sss[1000005];

void solve(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++ ){
        scanf("%s", sss);
        s[i].first = string(sss);
        s[i].second = i + 1;
    }
    sort(s, s + n);
    for(int i = 0; i < n; i++ )
        id[s[i].second] = i;
    fill(in, in + n, 0);
    for(int i = 0; i < n - 1; i++ ){
        int p = min(s[i].first.size(), s[i + 1].first.size());
        for(int j = 0; j < p; j++ ){
            if(s[i].first[j] != s[i + 1].first[j]) break;
            in[i]++;
        }
    }

    RMQ_preprocess(in, n - 1);
    int m;
    int l, r;
    scanf("%d", &m);
    for(int i = 0; i < m; i++ ){
        scanf("%d %d", &l, &r);
        int ll = id[l];
        int rr = id[r];
        if(ll > rr) swap(ll, rr);
        if(ll == rr) printf("%d\n", s[ll].first.size());
        else printf("%d\n", RMQ_getMin(in, ll, rr - 1));
    }
}

int main(){
    int test;
    scanf("%d", &test);
    for(int tt = 0; tt < test; tt++ ){
        printf("Case %d:\n", tt + 1);
        solve();
    }
    return 0;
}
