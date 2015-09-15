#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500000 + 10;
int a[MAXN], b[MAXN], d[MAXN];
int s[30], t[30], n, m;

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++ i) s[i] = t[i] = -1;
    for (int i = 0; i < n; ++ i) {
        scanf("%d%d%d", a + i, b + i, d + i);
        if (s[d[i]] == -1 || b[s[d[i]]] > b[i]) s[d[i]] = i;
        if (t[d[i]] == -1 || a[t[d[i]]] < a[i]) t[d[i]] = i;
    }
    for (int i = 1; i <= m; ++ i) {
        if (s[i] == t[i] || b[s[i]] >= a[t[i]]) puts("NIE");
        else printf("TAK %d %d\n", s[i] + 1, t[i] + 1);
    }
}