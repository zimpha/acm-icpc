#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3000 + 10;
typedef pair<int, string> PIS;

int LCP[MAXN], n;
string uns[MAXN], S, P;
vector<PIS> vs;

inline bool same(char a, char b) {
    return a == b || a == '*' || b == '*';
}

size_t lcp(const string &A, const string &B) {
    for (size_t i = 0, j = 0; i < A.size() && j < B.size(); ++ i, ++ j) {
        if (!same(A[i], B[j])) return i;
    }
    return min(A.size(), B.size());
}

bool match(const string &A, const string &B) {
    return lcp(A, B) == A.size();
}

bool allmatch(int len, const string &msk) {
    int last = 0;
    for (auto &x : vs) {
        if (x.first - last > len) return false;
        if (match(msk, x.second)) last = x.first;
    }
    return true;
}

bool dfs(int len, string &msk, int dep = 0) {
    if (dep == (int)msk.size()) return allmatch(len, msk);
    msk[dep] = 'R'; if (dfs(len, msk, dep + 1)) return true;
    msk[dep] = 'G'; if (dfs(len, msk, dep + 1)) return true;
    msk[dep] = 'B'; if (dfs(len, msk, dep + 1)) return true;
    return false;
}

string solve() {
    for (int len = 1; len < n; ++ len) {
        if (LCP[n - len] < len) continue;
        P = S.substr(n - len); vs.clear();
        string msk = uns[n - len];
        for (int i = 0; i < len; ++ i) if (P[i] == '*') P[i] = S[i];
        int ml = msk.size(), cnt = 0, flag = 1;
        for (auto &x : P) cnt += (x == '*');
        for (int i = 0, last = -1; i <= n - len; ++ i) {
            if (i - last > len) {flag = 0; break;}
            if (LCP[i] < len) continue;
            string tmp = uns[i].substr(0, ml);
            if (match(msk, tmp)) {
                string cnd; last = i;
                for (int j = 0; j < ml; ++ j) if (msk[j] == '*') cnd += tmp[j];
                vs.push_back(PIS(i, cnd));
            }
        }
        if (!flag) continue;
        if (!cnt) return P;
        msk = string(cnt, ' ');
        if (!dfs(len, msk)) continue;
        for (size_t i = 0, j = 0; i < P.size(); ++ i) {
            if (P[i] == '*') P[i] = msk[j ++];
        }
        return P;
    }
    for (auto &x : S) if (x == '*') x = 'R';
    return S;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T; cin >> T;
    while (T --) {
        cin >> S; n = S.size();
        for (int i = 0; i < n; ++ i) {
            LCP[i] = 0; uns[i] = "";
            for (int j = 0; j < n - i; ++ j) {
                if (S[j] == '*') uns[i] += S[i + j];
                if (same(S[j], S[i + j])) LCP[i] ++;
                else break;
            }
        }
        cout << solve() << endl;
    }
    return 0;
}