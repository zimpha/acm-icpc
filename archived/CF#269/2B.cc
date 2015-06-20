#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10000;
typedef pair<int, int> PII;
int cnt[MAXN], n, tot;
PII a[MAXN];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++ i) {
        int x; cin >> x;
        a[i] = PII(x, i);
        if (cnt[x]) ++ tot;
        cnt[x] ++;
    }
    if (tot < 2) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    sort(a + 1, a + 1 + n);
    for (int _ = 0; _ < 3; ++ _) {
        for (int i = 1; i <= n; ++ i) cout << a[i].second << " \n"[i == n];
        for (int i = 1; i < n; ++ i) {
            if (a[i].first == a[i + 1].first && a[i].second < a[i + 1].second) {
                swap(a[i], a[i + 1]);
                break;
            }
        }
    }
    return 0;
}
