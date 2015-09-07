#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
LL A,B;

LL gao(LL n){
    LL i,j,k;
    LL rst=0;
    int cnt=0;
    for (i=60; i>=0; i--){
        if ((n>>i)&1){
            if (i!=0) rst+=i*(1ll<<(i-1));
            rst+=cnt*(1ll<<i);
            cnt++;
        }
    }
    return rst;
}

int main(){
    //freopen("in","r",stdin);
    //cout << gao(8) << endl;
    while (scanf("%lld%lld",&A,&B)!=EOF){
        //cout << gao(A) << endl;
        //cout << gao(B+1) << endl;
        cout << gao(B+1)-gao(A) << endl;
    }
    return 0;
}
