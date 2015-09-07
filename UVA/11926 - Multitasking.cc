#include <cstdio>
#include <cstring>
#include <algorithm>
 
using namespace std;
 
int n, m, s, e, r;
bool conflict;
bool time[1000100];
 
bool check() {
    for(int i = s; i < e; i++) {
        if(time[i]) return false;
        time[i] = true;
    }
    return true;
}
 
int main() {
    for(;;) {
        scanf("%d %d", &n, &m);
        if(n == 0 && m == 0) break;
        conflict = false;
 
        memset(time, false, sizeof time);
        for(int i = 0; i < n; i++) {
            scanf("%d %d", &s, &e);
            if(!conflict && !check()) conflict = true;
        }
        for(int i = 0; i < m; i++) {
            scanf("%d %d %d", &s, &e, &r);
            while(!conflict && s < 1000000) {
                if(!check()) conflict = true;
                s += r;
                e = min(e + r, 1000000);
            }
        }
        if(!conflict) printf("NO CONFLICT\n");
        else printf("CONFLICT\n");
    }
}
