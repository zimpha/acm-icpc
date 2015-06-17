#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
char s[100005];
int c[26],n;
int main(){
  int T;scanf("%d",&T);
  while(T--){
    scanf("%s",s);
    for (int i = 0; i < 26; ++ i) c[i] = 0;
    n=strlen(s);
    for (int i = 0; i < n; ++ i) ++c[s[i]-'a'];
    vector<pii> p;
    for (int i = 0; i < 26; ++ i) if(c[i])p.push_back(pii(c[i],i));
    sort(p.begin(), p.end(), greater<pii>());
    bool ok=1;
    set<pii> ds;
    for(auto &o:p)ds.insert(o);
    int pr=-1;
    string res;
    for (int ss = 0; ss < n; ++ ss) {
      auto f=--ds.end();
      if(f->second==pr){
        if(f==ds.begin()){
          ok=0;
          break;
        }
        --f;
      }
      res+=('a'+f->second);
      pr=f->second;
      int c=f->first;
      ds.erase(f);
      if(c-1>0)
        ds.insert(pii(c-1,pr));
    }
    if(!ok) puts("-1");
    else puts(res.c_str());
  }
  return 0;
}