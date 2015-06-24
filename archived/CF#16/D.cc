#include <bits/stdc++.h>
using namespace std;

int main() {
    int pre = -1, ret = 1, N, num = 0;
    scanf("%d " , &N);
    while (N --) {
        int hh, mm;
        char c, buf[100];
        scanf("[%d:%d %c.m.]:", &hh, &mm, &c);
        gets(buf);
        int t = hh * 60 + mm;
        if (hh == 12) t -= (c == 'a') ? 720 : 0;
        else t += (c == 'p') ? 720 : 0;
        if (t == pre) ++ num;
        else num = 0;
        if (num > 9) ++ ret, num = 0;
        if (t < pre) ++ ret;
        pre = t;
    }
    printf("%d\n", ret);
    return 0;
}
