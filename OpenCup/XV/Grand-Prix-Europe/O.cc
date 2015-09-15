#include <bits/stdc++.h>
using namespace std;

int main() {
    int T; scanf("%d", &T);
    while (T --) {
        char buf[100]; scanf("%s", buf);
        int cnt[10]; memset(cnt, 0, sizeof(cnt));
        for (int i = 0; buf[i]; ++ i) cnt[buf[i] - '0'] ++;
        string ret = "";
        for (int i = 0; i < 10; ++ i) 
            if (!cnt[i]) ret += string(1, '0' + i);
        if (ret == "") ret = "allo";
        cout << ret << endl;
    }
    return 0;
}