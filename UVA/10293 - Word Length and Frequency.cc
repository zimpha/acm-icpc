#include <bits/stdc++.h>
using namespace std;

int cnt[50];

int main() {
    bool flag = false;
    while (!cin.eof()) {
        memset(cnt, 0, sizeof(cnt));
        char ch, prev;
        do {
            int len = 0; ch = cin.get(), prev = ch;
            if (cin.eof()) {
                flag = true;
                break;
            }
            while (ch != ' ' && ch != '?' && ch != '!' && ch != '.' && ch != ',') {
                if (ch == '#') break;
                if (ch == '\'' || ch == '-' || ch == '\n') {
                    if (ch == '\n' && prev != '-') break;
                    prev = ch; ch = cin.get();
                    continue;
                }
                ++ len; prev = ch; ch = cin.get();
            }
            ++ cnt[len];
        } while (ch != '#');
        if (flag) break;
        for (int i = 1; i < 50; ++ i) {
            if (cnt[i]) cout << i << " " << cnt[i] << endl;
        }
        cout << endl;
    }
    return 0;
}
