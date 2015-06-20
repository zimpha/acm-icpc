#include <bits/stdc++.h>
using namespace std;

map<int, int> belong, cnt;
vector<int> ret, val;

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; ++ i) {
        int x; cin >> x;
        if (belong.count(x)) {
            ret.push_back(belong[x]); ret.push_back(x);
            ret.push_back(belong[x]); ret.push_back(x);
            belong.clear(); val.clear(); cnt.clear();
        }
        else {
            if (cnt.count(x)) {
                while (cnt[x] > 1 || val.back() != x) {
                    belong[val.back()] = x;
                    cnt[val.back()] --;
                    val.pop_back();
                }
            }
            cnt[x] ++; val.push_back(x);
        }
    }
    cout << ret.size() << endl;
    for (int i = 0; i < (int)ret.size(); ++ i) {
        if (i) cout << ' ';
        cout << ret[i];
    }
    cout << endl;
    return 0;
}
