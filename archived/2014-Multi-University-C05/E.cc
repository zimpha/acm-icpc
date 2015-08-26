#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
const int MaxN=1e6+7;
char S[MaxN],T[MaxN];
int a[MaxN],w[MaxN];

int idx(char c){
    if (c=='?') return 0;
    if (c=='(') return 1;
    if (c==')') return -1;
}

int check(){
    int b=0,q=0,flag=0;
    int i,j,k,len=strlen(S);
    for (i=0; i<len; i++){
        b+=idx(S[i]); q+=!idx(S[i]);
        if (q>b) q--, b++;
        if (q<0) return 0;
    }
    if (q!=b) return 0;
    return 1;
}

char cov(char c){
    if (c=='(') return ')';
    if (c==')') return '(';
    return c;
}

int f[2][MaxN][2];

int gao(){
    int i,j,len=strlen(S);
    int rst=1;
    memset(f,0,sizeof(f));
    for (i=0; i<2; i++){
        for (j=0; j<len; j++) T[j]=cov(S[len-1-j]);
        for (j=0; j<len; j++) S[j]=T[j];

        int b=0, q=0;
        for (j=0; j<len; j++){
            b+=idx(S[j]); q+=!idx(S[j]);
            if (q>b) q--, b++;
            f[i][j][0]=b-q;
            f[i][j][1]=b+q;
        }
    }

    for (i=0; i<len-1; i++){
        int x=max(f[0][i][0],f[1][len-i-2][0]);
        int y=min(f[0][i][1],f[1][len-i-2][1]);
        if (y-x>=2) return 2;
    }
    return 1;
}

int main(){
    while (scanf("%s",S)!=EOF){
        if (!check()){ puts("None"); continue; }
        int rst=gao();
        if (rst==2) puts("Many");
        else        puts("Unique");
    }
    return 0;
}
