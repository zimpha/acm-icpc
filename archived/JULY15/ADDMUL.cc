#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
typedef long long LL;
#define lson (rt<<1)
#define rson (rt<<1|1)
#define mid ((l+r)>>1)

using namespace std;

const int MAXN=100005;
const int MOD=1e9 + 7;

struct node
{
  LL sum[2], add, mul, cover;
  bool flag;
};

node tree[MAXN*4];
int N, M;

inline void update(int rt)
{
  for (int i=0; i<2; i++)
    tree[rt].sum[i]=(tree[lson].sum[i]+tree[rson].sum[i])%MOD;
}

void build(int rt, int l, int r)
{
  tree[rt].mul=1; tree[rt].add=0; tree[rt].flag=false; tree[rt].cover=0;
  if (l==r)
  {
    tree[rt].sum[0]=1;
    scanf("%lld", &tree[rt].sum[1]);
    return;
  }
  build(lson, l, mid); build(rson, mid+1, r);
  update(rt);
}

inline void change12(int rt, int mul, int add)
{
  tree[rt].mul=(tree[rt].mul*mul)%MOD;
  tree[rt].add=(tree[rt].add*mul%MOD+add)%MOD;
  tree[rt].sum[1]=(tree[rt].sum[1]*mul%MOD+tree[rt].sum[0]*add%MOD)%MOD;
}

inline void change3(int rt, int x)
{
  tree[rt].cover=x; tree[rt].flag=true; tree[rt].mul=1; tree[rt].add=0;
  tree[rt].sum[1]=tree[rt].sum[0]*x%MOD;
}

inline void pushdown(int rt)
{
  if (tree[rt].flag)
  {
    change3(lson, tree[rt].cover);
    change3(rson, tree[rt].cover);
  }
  if (tree[rt].add!=0||tree[rt].mul!=1)
  {
    change12(lson, tree[rt].mul, tree[rt].add);
    change12(rson, tree[rt].mul, tree[rt].add);
  }
  tree[rt].flag=false; tree[rt].cover=tree[rt].add=0; tree[rt].mul=1;
}

void modify12(int rt, int l, int r, int ll, int rr, int mul, int add)
{
  if (ll<=l&&rr>=r)
  {
    change12(rt, mul, add);
    return;
  }
  pushdown(rt);
  if (ll<=mid) modify12(lson, l, mid, ll, rr, mul, add);
  if (rr>mid) modify12(rson, mid+1, r, ll, rr, mul, add);
  update(rt);
}

void modify3(int rt, int l, int r, int ll, int rr, int x)
{
  if (ll<=l&&rr>=r)
  {
    change3(rt, x);
    return;
  }
  pushdown(rt);
  if (ll<=mid) modify3(lson, l, mid, ll, rr, x);
  if (rr>mid) modify3(rson, mid+1, r, ll, rr, x);
  update(rt);
}

int query(int rt, int l, int r, int ll, int rr, int p)
{
  if (ll<=l&&rr>=r) return tree[rt].sum[p];
  pushdown(rt);
  int ret=0;
  if (ll<=mid) ret=(ret+query(lson, l, mid, ll, rr, p))%MOD;
  if (rr>mid) ret=(ret+query(rson, mid+1, r, ll, rr, p))%MOD;
  return ret%MOD;
}

int main() {
  while (scanf("%d%d", &N, &M)==2) {
    build(1, 1, N);
    while (M--) {
      int opt, l, r, x;
      scanf("%d%d%d", &opt, &l, &r);
      if (opt==1) {
        scanf("%d", &x);
        modify12(1, 1, N, l, r, 1, x);
      }
      else if (opt==2) {
        scanf("%d", &x);
        modify12(1, 1, N, l, r, x, 0);
      }
      else if (opt==3) {
        scanf("%d", &x);
        modify3(1, 1, N, l, r, x);
      }
      else {
        printf("%d\n", query(1, 1, N, l, r, 1));
      }
    }
  }
  return 0;
}
