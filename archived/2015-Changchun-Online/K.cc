#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cassert>
#include<map>
#include<cmath>
using namespace std;
typedef unsigned __int128 u128;
typedef unsigned long long u64;
u128 g128(){
  string s;
  cin >> s;
  u128 x=0;
  for(size_t i=0;i<s.size();++i)
    x=x*10+s[i]-'0';
  return x;
}
namespace PT{
  u128 x64,m;
  void set(u128 _m){
    m=_m;
    x64 = 1;
    x64 = (x64<<64) %m;
  }
  u128 mul(u128 a,u128 b){
    static const u128 msk=~0uLL;
    u128 a_hi = a>>64, b_hi=b>>64;
    u128 a_lo = a& msk , b_lo = b&msk;
    u128 res=a_hi*b_hi % m;
    res=(res*x64+a_hi*b_lo+a_lo*b_hi) %m;
    return (res*x64+a_lo*b_lo)%m;
  }
  u128 pm(u128 x,u128 n){
    u128 r=1;
    for(;n;n>>=1,x=mul(x,x))
      if(n&1)r=mul(r,x);
    return r;
  }
  bool mr(u128 a){
    int s,i;
    u128 d=m-1,x=pm(a%m,d),n1=m-1;
    for(s=0;!(d&1);++s)d>>=1;
    for(i=0;i<s&&x!=1&&x!=n1;++i)
      x=mul(x,x);
    return x==n1||i==0;
  }
  bool isprime(u128 n){
    set(n);
    if(n<=4)return n&2;
    static const int s7[]={2,325,9375,28178,450775,9780504, 1795265022};
    if(n<341531)return mr(9345883071009581737ULL);
    if(n<1050535501)return mr(336781006125ULL) && mr(9639812373923155ULL);
    if(n<4759123141ull) 
      return mr(2)&&mr(7) && mr(61);
    for(int i=0;i<7;++i)
      if(!mr(s7[i]))return 0;
    if(!(n>>64))return 1;
    return mr(3) && mr(5) && mr(7) && mr(97) && mr(101);
  }
}

vector<int> ps;
const int L=1<<20;
bool sv[L];
namespace FAC{
  u64 p;
  vector<u128> *pv;
  void rho(u128 n){
    static map<u128,u64> cache;
    map<u128,u64>::iterator it=cache.find(n);
    if(it!=cache.end()){
      u64 t=it->second;
      if(t==0){
        pv->push_back(n);
      }else{
        rho(t);rho(n/t);
      }
      return;
    }
    if(p*p>n || PT::isprime(n)){
      pv->push_back(n);
      cache[n]=0;
      return;
    }
    u64 x=sqrt((long double)n);
    for(int tm=5;tm--;)x=x+n/x>>1;
    for(;(u128)x*x < n; ++x);
    if(n%x==0){
      cache[n]=x;
      rho(x);
      rho(n/x);
      return;
    }
    x=cbrt((long double)n);
    for(;(u128)x*x*x < n; ++x);
    for(;(u128)x*x*x > n; --x);
    if(n%x==0){
      cache[n]=x;
      cache[n/x]=x;
      rho(x);
      rho(n/x);
      return;
    }
    u128 d=1;
    int tm=30000;
    for(u128 x=2,y=2;d==1 && tm--;){
      x=PT::mul(x,x)+1;
      y=PT::mul(y,y)+1;
      y=PT::mul(y,y)+1;
      d=__gcd((x<y?y-x:x-y), n);
    }
    if(d>1 && d<n){
      u128 t=n/d;
      cache[n]= min(t,d);
      u64 g=__gcd(t,d);
      if(g>1 && g<d)cache[d]=g;
      if(g>1 && g<t)cache[t]=g;
      rho(d);rho(t);
    }
  }
  void gao(vector<u128>& v,u128 n){
    if(n==1)return;
    for(int i=0;i<ps.size();++i){
      for(p=ps[i];n%p==0;n/=p)v.push_back(p);
      if(p*p>n)break;
    }
    pv=&v;
    if(n>1)rho(n);
  }
}

u64 sol(vector<u128> u){
  sort(u.begin(),u.end());
  vector<u128> v;
  for(int i=0,k=0;i<u.size();++i)
  if(i==0 || u[i]!=u[i-1]){
    k=v.size();
    FAC::gao(v,u[i]);
  }else{
    int z=k;
    k=v.size();
    for(int i=v.size();i-->z;)v.push_back(v[i]);
  }
  map<u128,int> cc;
  for(int i=0;i<v.size();++i)++cc[v[i]];
  u64 res=1;
  for(map<u128,int>::iterator it=cc.begin();it!=cc.end();++it)
    res*=it->second;
  return res;
}

int main(){
  int T;
  for(int i=2;i<L;++i)if(!sv[i]){
    ps.push_back(i);
    if(L/i>=i)
      for(int j=i*i;j<L;j+=i)sv[j]=false;
  }
  for(cin >> T;T--;) {
    u128 a=g128();
    u128 b=g128();
    u128 g=__gcd(a,b);
    vector<u128> A,B;
    A.push_back(g);
    B.push_back(g);
    A.push_back(a/g);
    B.push_back(b/g);
    for(bool fine=false;!fine;){
      fine=true;
      for(int i=A.size();i--;)
        for(int j=i;j>=0;--j)if(A[i]!=A[j]){
          u128 x=__gcd(A[i],A[j]);
          if(x==1)continue;
          fine=false;
          if(x!=A[i]){A[i]/=x;A.push_back(x);}
          if(x!=A[j]){A[j]/=x;A.push_back(x);}
        }
      for(int i=B.size();i--;)
        for(int j=i;j>=0;--j)if(B[i]!=B[j]){
          u128 x=__gcd(B[i],B[j]);
          if(x==1)continue;
          fine=false;
          if(x!=B[i]){B[i]/=x;B.push_back(x);}
          if(x!=B[j]){B[j]/=x;B.push_back(x);}
        }
      for(int i=A.size();i--;)
        for(int j=B.size();j--;)if(A[i]!=B[j]){
          u128 x=__gcd(A[i],B[j]);
          if(x==1)continue;
          fine=false;
          if(x!=A[i]){A[i]/=x;A.push_back(x);}
          if(x!=B[j]){B[j]/=x;B.push_back(x);}
        }
    }
    cout << sol(A) << " " << sol(B) << endl;
  }
}