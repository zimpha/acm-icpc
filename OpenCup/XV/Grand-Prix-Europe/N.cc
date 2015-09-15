#include <bits/stdc++.h>
using namespace std;

map<string, int> mp;
int n;

int toInt(string s) {
    int ret = 0;
    for (auto &c : s) ret = ret * 10 + c - '0';
    return ret;
}

void solve() {
    map<string, int> now;
    while (n) {
        -- n;
        string buf; getline(cin, buf);
        if (buf == "{") {
            solve();
        }
        else if (buf == "}") {
            for (auto &x : now) {
                mp[x.first] = x.second;
            }
            break;
        }
        else if (buf.substr(0, 4) == "int ") {
            string var = buf.substr(4);
            now[var] = mp[var];
        }
        else if (buf.substr(0, 6) == "print ") {
            string var = buf.substr(6);
            printf("%d\n", mp[var]);
        }
        else {
            int p = buf.find('=');
            string var = buf.substr(0, p);
            string tmp = buf.substr(p + 1);
            if (isdigit(tmp[0])) mp[var] = toInt(tmp);
            else mp[var] = mp[tmp];
        }
    }
}

int main() {
    scanf("%d", &n); getchar();
    solve();
    return 0;
}