#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;

vector<PII> X, Z;
int p, q, l, r;

int check(int t) {
    for (int i = 0; i < p; ++ i) {
        int lz = Z[i].first, rz = Z[i].second;
        for (int j = 0; j < q; ++ j) {
            int lx = X[j].first + t, rx = X[j].second + t;
            if (lx <= lz && lz <= rx) return true;
            if (lx <= rz && rz <= rx) return true;
            if (lz <= lx && lx <= rz) return true;
            if (lz <= rx && rx <= rz) return true;
        }
    }
    return false;
}

int main() {
    cin >> p >> q >> l >> r;;
    for (int i = 0; i < p; ++ i) {
        int a, b; cin >> a >> b;
        Z.push_back(PII(a, b));
    }
    for (int i = 0; i < q; ++ i) {
        int a, b; cin >> a >> b;
        X.push_back(PII(a, b));
    }
    int ret = 0;
    for (int i = l; i <= r; ++ i) {
        ret += check(i);
    }
    cout << ret << endl;
    return 0;
}
