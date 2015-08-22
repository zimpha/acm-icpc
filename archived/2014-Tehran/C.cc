#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

struct Node {
  int team, prob, time, status;
  bool operator < (const Node &rhs) const {
    return time < rhs.time;
  }
  void read() {
    static char s[1000];
    scanf("%d%s", &team, s); 
    team --; prob = s[0] - 'A';
    int hh, mm, ss; scanf("%d:%d:%d", &hh, &mm, &ss);
    time = hh * 3600 + mm * 60 + ss;
    gets(s); status = s[1] == 'Y';
  }
};

Node sub[6000];
bool mp[200][20];
int team[200], prob[20];
int t, p, s;

bool check() {
  for (int i = 0; i < t; ++ i) {
    if (team[i] == 0 || team[i] == p) return false;
  }
  for (int i = 0; i < p; ++ i) {
    if (prob[i] == 0 || prob[i] == t) return false;
  }
  return true;
}

int main() {
  while (scanf("%d%d%d", &t, &p, &s) == 3 && t) {
    for (int i = 0; i < s; ++ i) sub[i].read();
    sort(sub, sub + s);
    memset(mp, 0, sizeof(mp));
    for (int i = 0; i < t; ++ i) team[i] = 0;
    for (int i = 0; i < p; ++ i) prob[i] = 0;
    int L(-1), R(-1);
    for (int i = 0; i < s; ++ i) if (sub[i].status) {
      if (mp[sub[i].team][sub[i].prob]) continue;
      mp[sub[i].team][sub[i].prob] = 1;
      int prev = check();
      team[sub[i].team] ++;
      prob[sub[i].prob] ++;
      int now = check();
      if (!prev && now) {
        assert(L == -1);
        L = sub[i].time;
      }
      if (prev && !now) {
        assert(R == -1);
        R = sub[i].time;
      }
    }
    if (L == -1) printf("--:--:-- ");
    else printf("%02d:%02d:%02d ", L / 3600, L % 3600 / 60, L % 3600 % 60);
    if (R == -1) printf("--:--:--\n");
    else printf("%02d:%02d:%02d\n", R / 3600, R % 3600 / 60, R % 3600 % 60);
  }
  return 0;
}

