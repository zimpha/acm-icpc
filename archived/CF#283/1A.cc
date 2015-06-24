#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100 + 10;
string s[MAXN];
bool eq[MAXN], te[MAXN];
int n, m;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++ i) cin >> s[i], eq[i] = true;
    int ret = 0;
    for (int j = 0; j < m; ++ j) {
        for (int i = 0; i < n; ++ i) te[i] = eq[i];
        for (int i = 1; i < n; ++ i) if (eq[i]) {
            if (s[i][j] < s[i - 1][j]) {
                ++ ret;
                for (int i = 0; i < n; ++ i) eq[i] = te[i];
                break;
            }
            else eq[i] = (s[i][j] == s[i - 1][j]);
        }
    }
    cout << ret << endl;
    return 0;
}
