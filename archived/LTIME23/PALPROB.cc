#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
static const int MAXN = 100000 + 10, SIGMA = 26;
namespace PT {
  struct Node {
    Node *ch[SIGMA],*suff;
    int len,cnt,deg;
    vector<Node*> revSuff;
    void clr() {
      memset(ch,0,sizeof(ch)); suff=0;
      len=cnt=deg=0; revSuff.clear();
    }//root of odd and even length
  } pool[MAXN],*lt,*sz,*rt0,*rt1;
  char *s;
  void init(char p[],int n) {
    for (int i=0;i<n+10;++i) pool[i].clr();
    sz=pool; s=p; lt=sz+1;
    rt0=sz++; rt0->suff=rt0; rt0->len=-1;
    rt1=sz++; rt1->suff=rt0; rt1->len=0;
  }
  bool add(int n) {
    Node *p=lt;
    int cl=p->len,c=s[n]-'a';
    while (n<cl+1||s[n-cl-1]!=s[n]) {
      p=p->suff; cl=p->len;
    }
    if (p->ch[c]) return lt=p->ch[c],lt->cnt++,false;
    lt=sz++; lt->cnt++; lt->len=p->len+2; p->ch[c]=lt;
    if (lt->len==1) return lt->suff=rt1,true;
    while (1) {
      p=p->suff, cl=p->len;
      if (n>=cl+1&&s[n-cl-1]==s[n]) {
        lt->suff=p->ch[c]; break;
      }
    }
    return true;
  }
  void build(char p[],int n) {
    init(p,n);
    for (int i=0;i<n;++i) add(i);
    for (Node *p=sz-1;p>pool+1;--p) {
      p->suff->cnt += p->cnt;
      p->suff->revSuff.push_back(p);
    }
  }
  int val[MAXN];
  void solve(Node *p) {
    if (p->len == 0) p->deg = 0;
    else if (p->len == 1) p->deg = 1;
    else p->deg = val[p->len / 2] + 1;
    val[p->len] = p->deg;
    for (auto q: p->revSuff) {
      solve(q);
    }
    val[p->len] = 0;
  }
  void calc(int n) {
    LL ret = 0;
    for (Node *p = pool + 1; p < sz; ++ p) {
      ret += (LL)p->cnt * p->deg;
    }
    printf("%lld\n", ret);
  }
}

char s[MAXN];

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    scanf("%s", s);
    int n = strlen(s);
    PT::build(s, n);
    PT::solve(PT::rt1);
    PT::calc(n);
  }
  return 0;
}
