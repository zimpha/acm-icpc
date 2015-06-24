#include<bits/stdc++.h>
using namespace std;
vector<int> e[500];
int f[500];
int main(){
  int n;cin >> n;
  map<string,int> id;
  for(string a,_,b;n--;){
    cin >> a >> _ >> b;
    for(char&c:a)c=tolower(c);
    for(char&c:b)c=tolower(c);
    int x,y;
    if(id.count(a))x=id[a];
    else{ x=id.size();id[a]=x;}
    if(id.count(b))y=id[b];
    else{ y=id.size();id[b]=y;}
    e[x].push_back(y);
  }
  n=id.size();
  for(int i=0;i<n;++i)f[i]=1;
  for(int j=0;j<n*50;++j)
    for(int i=0;i<n;++i)
      for(int k:e[i])f[i]=max(f[k]+1,f[i]);
  cout << *max_element(f,f+n) << endl;
}