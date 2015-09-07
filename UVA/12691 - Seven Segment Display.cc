#include <bits/stdc++.h>
using namespace std;

vector<int> E[600];
int du[4];
int T, n, m;
bool flag;
vector<pair<int,int> > ans;

bool vis[600];

void dfs2(int k) {
    if (vis[k]) return;
    vis[k] = true;
    for (int i = E[k].size() - 1; i >= 0; -- i) dfs2(E[k][i]);
}

bool check() {
    for (int i = 1; i <= n; ++ i) vis[i] = false;
    dfs2(1);
    for (int i = 1; i <= n; ++ i) if (!vis[i]) return false;
    return true;
}

int dfs(int k, int pre) {
    if (E[k].size() == 2) {
        for (int i = 0; i < 2; ++ i) if (E[k][i] != pre)
            return 1 + dfs(E[k][i], k);
    }
    else return 1;
}

void gao0() {
    if (du[0] == 0 && du[1] == 0 && du[3] == 0) {
        if (du[2] >= 6 && ((du[2] % 6) == 0)) {
            ans.push_back(make_pair(0, (du[2] - 6) / 6));
        }
    }
}

void gao1() {
    if (du[0] == 0 && du[1] == 2 && du[3] == 0) {
        if ((du[2] % 2) == 1) {
            ans.push_back(make_pair(1, du[2] / 2));
        }
    }
}

void gao2() {
    if (du[0] == 0 && du[1] == 2 && du[3] == 0) {
        if ((du[2] >= 4) && (du[2] % 5 == 4)) {
            ans.push_back(make_pair(2, du[2] / 5));
        }
    }
}

void gao3() {
    if (du[0] == 0 && du[1] == 3 && du[3] == 1) {
        if ((du[2] >= 2) && (du[2] % 5 == 2)) {
            int x = 1;
            while (E[x].size() != 3) ++ x;
            int l[3];
            for (int i = 0; i < 3; ++ i) l[i] = dfs(E[x][i], x);
            sort(l, l + 3);
            if (l[1] != l[2]) return;
            if (l[0] * 2 != l[1]) return;
            if (l[0] + l[1] + l[2] + 1 != n) return;
                        
            ans.push_back(make_pair(3, du[2] / 5));
        }
    }
}

void gao4() {
    if (du[0] == 0 && du[1] == 3 && du[3] == 1) {
        if ((du[2] >= 1) && (du[2] % 4 == 1)) {
            int x = 1;
            while (E[x].size() != 3) ++ x;
            int l[3];
            for (int i = 0; i < 3; ++ i) l[i] = dfs(E[x][i], x);
            sort(l, l + 3);
            if (l[0] != l[1]) return;
            if (l[0] * 2 != l[2]) return;
            if (l[0] + l[1] + l[2] + 1 != n) return;
    
            ans.push_back(make_pair(4, du[2] / 4));
        }
    }
}

void gao5() {
    if (du[0] == 0 && du[1] == 2 && du[3] == 0) {
        if ((du[2] >= 4) && (du[2] % 5 == 4)) {
            ans.push_back(make_pair(5, du[2] / 5));
        }
    }
}

void gao6() {
    if (du[0] == 0 && du[1] == 1 && du[3] == 1) {
        if ((du[2] >= 4) && (du[2] % 6 == 4)) {
            int x = 1;
            while (E[x].size() != 3) ++ x;
            int l[3];
            for (int i = 0; i < 3; ++ i) l[i] = dfs(E[x][i], x);
            sort(l, l + 3);
            if (l[1] != l[2]) return;
            if (l[0] * 2 != l[2]) return;
            if (l[0] + l[1] != n) return;
 
            ans.push_back(make_pair(6, du[2] / 6));
        }
    }
}

void gao7() {
    if (du[0] == 0 && du[1] == 2 && du[3] == 0) {
        if ((du[2] >= 2) && (du[2] % 3 == 2)) {
            ans.push_back(make_pair(7, du[2] / 3));
        }
    }
}

void gao8() {
    if (du[0] == 0 && du[1] == 0 && du[3] == 2) {
        if ((du[2] >= 4) && (du[2] % 7 == 4)) {
            int x = 1;
            while (E[x].size() != 3) ++ x;
            int l[3];
            for(int i = 0; i < 3; ++ i) l[i] = dfs(E[x][i], x);
            sort(l, l + 3);
            if (l[1] != l[2]) return;
            if (l[0] * 3 != l[1]) return;
            if (l[0] + l[1] + l[2] - 1 != n) return;
                        
            ans.push_back(make_pair(8, du[2] / 7));
        }
    }
}

void gao9() {
    if (du[0] == 0 && du[1] == 1 && du[3] == 1) {
        if ((du[2] >= 4) && (du[2] % 6 == 4)) {
            int x = 1;
            while (E[x].size() != 3) ++ x;
            int l[3];
            for (int i = 0; i < 3; ++ i) l[i] = dfs(E[x][i], x);
            sort(l, l + 3);
            if (l[1] != l[2]) return;
            if (l[0] * 2 != l[2]) return;
            if (l[0] + l[1] != n) return;
                        
            ans.push_back(make_pair(9, du[2] / 6));
        }
    }
}

int main() {
    scanf("%d", &T);
    for(int cas = 1; cas <= T; ++ cas) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++ i) E[i].clear();
        for (int i = 0; i < m; ++ i) {
            int x, y; scanf("%d%d", &x, &y);
            E[x].push_back(y);
            E[y].push_back(x);
        }
        memset(du, 0, sizeof(du));
        flag = check();
        for (int i = 1; i <= n; ++ i) {
            int t = E[i].size();
            if (t >= 4) flag = false;
            du[t] ++;
        }
        ans.clear();
        if (flag) {
            gao0();
            gao1();
            gao2();
            gao3();
            gao4();
            gao5();
            gao6();
            gao7();
            gao8();
            gao9();
        }
        printf("Case %d: %d\n", cas, ans.size());
        sort(ans.begin(), ans.end());
        for(int i = 0; i < ans.size(); ++ i) {
            printf("%d %d\n", ans[i].first, ans[i].second);
        }
        if (cas < T) puts("");
    }
    return 0;
}
