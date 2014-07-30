#include <set>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 10005;

int A[MAXN], hit[MAXN], pocket[MAXN];
int N, M;

int main() {
	while (scanf("%d%d", &N, &M) == 2) {
		set<int> rest; rest.clear();
		for (int i = 1; i <= N; ++ i) {
			scanf("%d", &A[i]);
			rest.insert(A[i]);
		}
		int AP = 0, BP = 0;
		bool Alice = true;
		while (M --) {
			int p, q, target = *rest.begin();
			scanf("%d", &p);
			for (int i = 1; i <= p; ++ i) scanf("%d", &hit[i]);
			scanf("%d", &q);
			for (int i = 1; i <= q; ++ i) scanf("%d", &pocket[i]);
			bool cuein = false, targetin = false, targetfirst = false;
			int largestnum=0;
			for (int i = 1; i <= p; ++ i) {
				if (hit[i] == target) targetfirst = true;
				if (hit[i] > largestnum) largestnum = hit[i];
			}
			for (int i = 1; i <= q; ++ i) {
				if (pocket[i] == 0) cuein = true;
				if (pocket[i] == target) targetin = true;
			}
			bool foul = false;
			int penalty = 0, point = 0, objectin;
			if (cuein) objectin = q - 1;
			else objectin = q;
			for (int i = 1; i <= q; ++ i) point += pocket[i];
			//Cue ball do not hit any object ball.
			if (p == 0) foul = true, penalty = target;
			//Cue ball is not pocketed and hit at least one ball
			if (!cuein && p >= 1) {
				if (!targetfirst) foul = true, penalty = largestnum;
				if (p > 1) foul = true, penalty = largestnum;
			}
			//Cue ball is pocketed and hit at least one ball.
			if (cuein && p >= 1) foul = true, penalty = largestnum;
			if (foul) {
				if (Alice) BP += penalty;
				else AP += penalty;
				if (targetin) {
					if (Alice) BP += point;
					else AP += point;
				} 
				else {
					if (objectin >= 1) {
						if (Alice) BP += point;
						else AP += point;
					}
				}
				Alice = !Alice;
			}
			else {
				if (targetin) {
					if (Alice) AP += point;
					else BP += point;
				}
				else {
					if (objectin >= 1) {
						if (Alice) BP += point;
						else AP += point;
					}
					Alice = !Alice;
				}
			}
			for (int i = 1; i <= q; ++ i) rest.erase(pocket[i]);
		}
		printf("%d : %d\n", AP, BP);
	}
	return 0;
}
