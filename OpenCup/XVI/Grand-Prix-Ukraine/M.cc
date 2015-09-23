#include<bits/stdc++.h>
using namespace std;

int a[30720][8];
typedef long long ll;

ll eval(int*a,ll x){
  return ((((((a[0]*x+a[1])*x+a[2])*x+a[3])*x+a[4])*x+a[5])*x+a[6])*x+a[7];
}
typedef tuple<ll,int,int> tp;
priority_queue<tp,vector<tp>,greater<tp>> q;
int main(){
  int n;
  scanf("%d",&n);
  for(int i=0;i<n;++i){
    for(int j=0;j<8;++j)scanf("%d",a[i]+j);
    q.push(make_tuple(eval(a[i],1),1,i));
  }
  scanf("%d",&n);
  for(int i=1;i<n;++i){
    auto t=q.top();
    q.pop();
    int x=get<1>(t)+1,j=get<2>(t);
    q.push(make_tuple(eval(a[j],x),x,j));
  }
  printf("%lld\n",get<0>(q.top()));
}
