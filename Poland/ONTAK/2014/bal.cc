#include <bits/stdc++.h>
using namespace std;
typedef map<int, int>::iterator Iter;
typedef pair<int, int> PII;
map<int, int> ball;
priority_queue<PII> Q;
vector<int> snowmen;

int main() {
    int T; scanf("%d", &T);
    while (T --) {
        int N; scanf("%d", &N); ball.clear();
        for (int i = 0; i < N; ++ i) {
            int x; scanf("%d", &x);
            ball[x] ++;
        }
        while (!Q.empty()) Q.pop();
        for (Iter it = ball.begin(); it != ball.end(); ++ it) {
            Q.push(PII(it->second, it->first));
        }
        for (snowmen.clear(); Q.size() > 2; ) {
            PII i1 = Q.top(); Q.pop();
            PII i2 = Q.top(); Q.pop();
            PII i3 = Q.top(); Q.pop();
            snowmen.push_back(i1.second); i1.first --;
            snowmen.push_back(i2.second); i2.first --;
            snowmen.push_back(i3.second); i3.first --;
            if (i1.first) Q.push(i1);
            if (i2.first) Q.push(i2);
            if (i3.first) Q.push(i3);
        }
        assert(snowmen.size() % 3 == 0);
        printf("%d\n", (int)snowmen.size() / 3);
        for (int i = 0; i < (int)snowmen.size(); i += 3) {
            sort(snowmen.begin() + i, snowmen.begin() + i + 3, greater<int>());
            printf("%d %d %d\n", snowmen[i], snowmen[i + 1], snowmen[i + 2]);
        }
    }
    return 0;
}
