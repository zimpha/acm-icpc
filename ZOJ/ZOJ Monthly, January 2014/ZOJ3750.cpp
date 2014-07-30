#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN=45;
const int SIZE=1000;
const int dx[]={0, 0, 1, -1};
const int dy[]={1, -1, 0, 0};

struct node {
	int x, y, state;
};

int dis[SIZE][MAXN][MAXN];
bool visgrid[SIZE][MAXN][MAXN];
char grid[SIZE][MAXN][MAXN];
bool vistrigger[10];
int state[10000];
int stateid[100000];
node trigger[10];
int N, M, cnt, gridcount;
node st, ed;

bool connect(node st, node ed, int id) {
	queue<node> q;
	bool vis[MAXN][MAXN];
	memset(vis, 0, sizeof(vis));
	vis[st.x][st.y] = true; q.push(st);
	while (!q.empty()) {
		node now = q.front(), tmp; q.pop();
		for (int k = 0; k < 4; ++ k) {
			tmp.x = now.x + dx[k];
			tmp.y = now.y + dy[k];
			if (tmp.x < 1 || tmp.y < 1 || tmp.x > N || tmp.y > M) continue;
			if (vis[tmp.x][tmp.y]) continue;
			if (grid[id][tmp.x][tmp.y] == 'Y' || grid[id][tmp.x][tmp.y] == 'G' || grid[id][tmp.x][tmp.y] == '*') continue;
			vis[tmp.x][tmp.y] = true;
			if (tmp.x == ed.x && tmp.y == ed.y) return true;
			q.push(tmp);
		}
	}
	return false;
}

void destroy(node st, int id) {
	queue<node> q;
	bool vis[MAXN][MAXN];
	memset(vis, 0, sizeof(vis));
	vis[st.x][st.y] = true; q.push(st);
	while (!q.empty()) {
		node now = q.front(), tmp; q.pop();
		for (int k = 0; k < 4; ++ k) {
			tmp.x = now.x + dx[k];
			tmp.y = now.y + dy[k];
			if (tmp.x < 1 || tmp.y < 1 || tmp.x > N || tmp.y > M) continue;
			if (vis[tmp.x][tmp.y]) continue;
			vis[tmp.x][tmp.y] = true;
			if (grid[id][tmp.x][tmp.y] == 'Y' || grid[id][tmp.x][tmp.y] == 'G' || grid[id][tmp.x][tmp.y] == '*') continue;
			q.push(tmp);
		}
	}
	for (int i = 1; i <= N; ++ i)
		for (int j = 1; j <= M; ++ j)
			if (vis[i][j] && grid[id][i][j] == st.state) 
				grid[id][i][j] = '.';
}

void buildstate(int dep, int nowstate, int id) {
	if (dep >= cnt + 1) return;
	for (int i = 1; i <= cnt; ++ i)
		if (!vistrigger[i]) {
			vistrigger[i] = true;
			if (connect(st, trigger[i], stateid[nowstate])) {
				int tmpstate = nowstate * 10 + i;
				gridcount ++;
				stateid[tmpstate] = gridcount;
				state[gridcount] = tmpstate;
				memcpy(grid[gridcount], grid[id], sizeof(grid[id]));
				destroy(trigger[i], gridcount);
				buildstate(dep + 1, tmpstate, gridcount);
			}
			vistrigger[i] = false;
		}
}

int find(node a) {
	for (int i = 1; i <= cnt; ++ i)
		if (a.x == trigger[i].x && a.y == trigger[i].y) return i;
	return -1;
}

bool check(int index, int state) {
	while (state) {
		if (index == state % 10) return false;
		state /= 10;
	}
	return true;
}

void solve() {
	memset(visgrid, 0, sizeof(visgrid));
	memset(dis, 62, sizeof(dis));
	queue<node> q;
	st.state=0; q.push(st);
	dis[st.state][st.x][st.y] = 0;
	visgrid[st.state][st.x][st.y] = 1;
	while (!q.empty()) {
		node now = q.front(), tmp; q.pop();
		int id = stateid[now.state];
		for (int k = 0; k < 4; ++ k) {
			tmp.x = now.x + dx[k];
			tmp.y = now.y + dy[k];
			tmp.state = now.state;
			if (tmp.x < 1 || tmp.y < 1 || tmp.x > N || tmp.y > M) continue;
			if (grid[id][tmp.x][tmp.y] == 'G' || grid[id][tmp.x][tmp.y] == 'Y' || grid[id][tmp.x][tmp.y] == '*') continue;
			int index = find(tmp);
			if (index !=-1 && check(index, tmp.state)) tmp.state = tmp.state * 10 + index;
			if (dis[stateid[tmp.state]][tmp.x][tmp.y] > dis[id][now.x][now.y] + 1) {
				dis[stateid[tmp.state]][tmp.x][tmp.y] = dis[id][now.x][now.y] + 1;
				if (visgrid[stateid[tmp.state]][tmp.x][tmp.y]) continue;
				visgrid[stateid[tmp.state]][tmp.x][tmp.y]=true;
				q.push(tmp);
			}
		}
	}
	int ret = 1000000000;
	for (int i = 0; i <= gridcount; ++ i)
		if (dis[i][ed.x][ed.y] < ret)
			ret = dis[i][ed.x][ed.y];
	if (ret == 1000000000) puts("-1");
	else printf("%d\n", ret);
}

int main() {
	while (scanf("%d%d", &N, &M) == 2) {
		cnt = 0;
		for (int i = 1; i <= N; ++ i) {
			getchar();
			for (int j = 1; j <= M; ++ j) {
				grid[0][i][j] = getchar();
				if (grid[0][i][j] == 'y' || grid[0][i][j] == 'g') {
					cnt ++;
					trigger[cnt].x = i; trigger[cnt].y = j;
					trigger[cnt].state = grid[0][i][j] - 'a' + 'A';
					grid[0][i][j] = '.';
				}
				if (grid[0][i][j] == 's') st.x = i, st.y = j, grid[0][i][j] = '.';
				if (grid[0][i][j] == 'e') ed.x = i, ed.y = j, grid[0][i][j] = '.';
			}
		}
		memset(vistrigger, 0, sizeof(vistrigger));
		memset(state, -1, sizeof(state));
		memset(stateid, -1, sizeof(stateid));
		gridcount = 0; stateid[0] = 0; state[0] = 0;
		buildstate(1, 0, 0);
		solve();
	}
	return 0;
}

