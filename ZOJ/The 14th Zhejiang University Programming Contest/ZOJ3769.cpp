#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

const int MAXM = 50000 + 10;

unordered_map<string,int> equip_id={{"Head",1}, {"Shoulder",2}, {"Neck",3}, {"Torso",4}, {"Hand",5}, {"Wrist",6}, {"Waist",7}, {"Legs",8}, {"Feet",9},{"Finger",0}, {"Shield",10}, {"Weapon",11}, {"Two-Handed",12}};

struct Node {
	int D, T;
	Node() {}
	Node(int d, int t) : D(d), T(t) {}
};

int dp[13][MAXM];

inline void takemax(int &a, int b) {if (a < b) a = b;}

int main() {
	int T; cin >> T;
	while (T --) {
		int N, M; cin >> N >> M;
		vector<Node> E[13];
		for (int i = 0, a, b; i < N; ++ i) {
			string s;
			cin >> s >> a >> b;
			E[equip_id[s]].push_back(Node(a, b));
		}
		E[0].push_back(Node(0, 0));
		memset(dp, -1, sizeof(dp));
		dp[0][0] = 0;
		for (int i = 0; i < (int)E[0].size(); ++ i) {
			for (int j = 0; j < i; ++ j) {
				takemax(dp[0][min(E[0][i].T + E[0][j].T, M)], E[0][i].D + E[0][j].D);	
			}
		}
		int ret = -1;
		for (int i = 1; i <= 12; ++ i) {
			int p = (i == 12) ? 9 : i - 1;
			memcpy(dp[i], dp[p], sizeof(dp[p]));
			for (Node eq : E[i]) {
				for (int j = 0; j <= M; ++ j) {
					if (dp[p][j] < 0) continue;
					takemax(dp[i][min(j + eq.T, M)], dp[p][j] + eq.D);
				}
			}
			takemax(ret, dp[i][M]);
		}
		printf("%d\n", ret);
	}
	return 0;
}
