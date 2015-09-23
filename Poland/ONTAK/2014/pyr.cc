#include <bits/stdc++.h>
using namespace std;
typedef vector<int> VI;
set<VI> S;

void dfs(VI V) {
    if (S.count(V)) return;
    S.insert(V);
    VI tmp;
    for (int i = 0; i < (int)V.size(); ++ i) {
        if (V[i] == -1) {
            tmp = V;
            for (int j = 0; j < (int)V.size(); ++ j) {
                if (tmp[j] == i) tmp[j] = -1;
                else if (tmp[j] == -1 && j != i) tmp[j] = i;
            }
            dfs(tmp);
        }
    }
}

int main() {
    int n; scanf("%d", &n);
    VI V(n);
    for (int i = 0; i < n; ++ i) {
        scanf("%d", &V[i]); -- V[i];
    }
    dfs(V);
    printf("%d\n", (int)S.size());
}
