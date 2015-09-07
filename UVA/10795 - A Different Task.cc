#include <iostream>
#define MAXN 65

using namespace std;

typedef long long LL;
int start[MAXN],target[MAXN];
int n;

LL f(int *state,int n,int target)
{
    if (n==0) return 0;
    if (state[n]==target) return f(state,n-1,target);
    else return f(state,n-1,6-target-state[n])+(1LL << (n-1));
}

int main()
{
    int test=0;
    while (cin >> n)
    {
        if (!n) break;
        for (int i=1;i<=n;i++) cin>>start[i];
        for (int i=1;i<=n;i++) cin>>target[i];
        while (n&&start[n]==target[n]) n--;

        LL ans=0;
        if (n)
        {
            int other=6-start[n]-target[n];
            ans=f(start,n-1,other)+f(target,n-1,other)+1;
        }
        cout <<"Case "<<++test<<": "<<ans<<endl;
    }
    return 0;
}
