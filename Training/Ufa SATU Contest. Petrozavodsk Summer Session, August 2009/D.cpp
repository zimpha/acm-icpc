#include <bits/stdc++.h>
using namespace std;

struct Node {
    int idx, L, R, len, f;
    Node() {}
    Node(int i, int l, int r, int len) : idx(i), L(l), R(r), len(len) {
        if (L > R) f = -1;
        else if (L < R) f = 1;
        else f = 0;
    }
    bool operator < (const Node &rhs) const {
        if (f == -1 && rhs.f == -1) return R < rhs.R;
        if (f == 1 && rhs.f == 1) return L > rhs.L;
        return f < rhs.f;
    }
};

const int MAXN = 1000 + 10;
const int MAXM = 10000 + 10;

Node bracket[MAXN];
int dp[MAXN][MAXM], N, M;

int main() {
    cin >> N; M = 0;
    for (int i = 0; i < N; ++ i) {
        string s; cin >> s;
        stack<char> stk;
        for (int j = 0; j < (int)s.size(); ++ j) {
            char c = s[j];
            if (!stk.empty() && c == ')' && stk.top() == '(') stk.pop();
            else stk.push(c);
        }
        int l = 0, r = 0;
        while (!stk.empty()) {
            l += (stk.top() == '(');
            r += (stk.top() == ')');
            stk.pop();
        }
        M += l; bracket[i] = Node(i + 1, l, r, s.size());
    }
    sort(bracket, bracket + N);
    memset(dp[0], -1, sizeof(dp[0])); dp[0][0] = 0;
    for (int i = 0; i < N; ++ i) {
        const Node &x = bracket[i];
        for (int j = 0; j <= M; ++ j) dp[i + 1][j] = dp[i][j];
        for (int j = 0; j <= M; ++ j) {
            if (dp[i][j] == -1) continue;
            if (x.R <= j) {
                dp[i + 1][j - x.R + x.L] = max(dp[i + 1][j - x.R + x.L], dp[i][j] + x.len);
            }
        }
    }
    vector<int> ret;
    for (int i = N, j = 0; i; -- i) {
        if (dp[i][j] != dp[i - 1][j]) {
            const Node &x = bracket[i - 1];
            ret.push_back(x.idx);
            j = j - x.L + x.R;
        }
    }
    reverse(ret.begin(), ret.end());
    cout << dp[N][0] << " " << ret.size() << endl;
    for (int i = 0; i < (int)ret.size(); ++ i) {
        if (i) cout << " ";
        cout << ret[i];
    }
    cout << endl;
    return 0;
}
