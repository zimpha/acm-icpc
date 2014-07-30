#include <cstdio>
#include <cstring>

const int MAXN = 600005;

int fa[MAXN], val[MAXN], size[MAXN];
int id[MAXN], N, M;

int find(int x) {
    if (x != fa[x]) {
		int tmp = fa[x];
		fa[x] = find(fa[x]);
		val[x] ^= val[tmp];
    }
    return fa[x];
}

void connect(int u, int v) {
    u = id[u]; v = id[v];
    int fu = find(u);
    int fv = find(v);
    if (fu != fv) {
		fa[fu] = fv;
		size[fv] += size[fu];
		val[fu] = val[u] ^ val[v] ^ 1;
    }
}

void destroy(int u) {
    N ++;
    int fu = find(id[u]); size[fu] --;
    id[u] = N; val[N] = 0; size[N] = 1; fa[N] = N;
}

void query(int u, int v) {
    u = id[u]; v = id[v];
    int fu = find(u);
    int fv = find(v);
    if (fu == fv) {
		if (val[u] == val[v]) printf("Same\n");
		else printf("Different\n");
    }
	else printf("Unknown\n");
}

void getsum(int u) {
    u = id[u];
    int fu = find(u);
    printf("%d\n", size[fu]);
}

int main() {
    while (scanf("%d%d", &N, &M) == 2) {
		for (int i = 0; i <= N; ++ i) {
	    	fa[i] = i;
	    	val[i] = 0;
	    	size[i] = 1;
	    	id[i] = i;
		}
		while (M --) {
	    	getchar();
	    	int u, v;
	    	char ch;
	    	ch = getchar();
	    	switch (ch) {
			case 'L':
		    	scanf("%d%d", &u, &v);
		    	connect(u, v);
		    	break;
			case 'D':
		    	scanf("%d", &u);
		    	destroy(u);
		    	break;
			case 'Q':
		    	scanf("%d%d", &u, &v);
		    	query(u, v);
		    	break;
			case 'S':
		    	scanf("%d", &u);
		    	getsum(u);
		    	break;
	    	}
		}
    }
    return 0;
}
