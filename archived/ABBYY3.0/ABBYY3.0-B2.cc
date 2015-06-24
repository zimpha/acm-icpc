#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000 + 10;

vector<int> chain[MAXN];
int a[MAXN], b[MAXN];
bool dp[MAXN];
int n, cnt, pos, x;

int main() {
    cin >> n >> x;
    for (int i = 1; i <= n; ++ i) {
        cin >> a[i];
        b[a[i]] = i;
    }
    pos = -1;
    for (int i = 1; i <= n; ++ i) {
        if (a[i] == 0) {
            chain[cnt].clear();
            bool flag = false;
            for (int j = i; j; j = b[j]) {
                chain[cnt].push_back(j);
                if (j == x) {
                    pos = chain[cnt].size();
                    flag = true;
                }
            }
            if (!flag) ++ cnt;
        }
    }
    memset(dp, 0, sizeof(dp)); dp[0] = true;
    for (int i = 0; i < cnt; ++ i) {
        for (int j = n; j >= (int)chain[i].size(); -- j) {
            dp[j] |= dp[j - chain[i].size()];
        }
    }
    for (int i = 0; i <= n; ++ i) {
        if (dp[i]) cout << i + pos << endl;
    }
    return 0;
}
