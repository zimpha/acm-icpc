#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 100000 + 10;
int n, m;
int a[MAXN], C[MAXN], S[MAXN];

void add(int i) {
    for (; i <= n; i += i & -i) ++ S[i];
}

int sum(int i) {
    int ret = 0;
    for (; i; i -= i & -i) ret += S[i];
    return ret;
}

int main(){
    while (scanf("%d%d", &n, &m) == 2){
        for (int i = 1; i <= n; ++ i){
            scanf("%d", a + i);
            C[i] = a[i];
        }
        sort(C + 1, C + 1 + n);
        for (int i = 1; i <= n; ++ i) S[i] = 0;
        for (int i = 1; i <= n; ++ i) {
            a[i] = lower_bound(C + 1, C +1 + n, a[i]) - C;
        }
        long long ret = 0;
        for (int i = n; i >= 1; -- i) {
            ret += sum(a[i] - 1);
            add(a[i]);
        }
        ret = max(0ll, ret - m);
        cout << ret << endl;
    }
    return 0;
}
