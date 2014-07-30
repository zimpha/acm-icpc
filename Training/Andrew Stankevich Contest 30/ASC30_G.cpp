#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef pair<int, int> PII;
typedef long long LL;

const int MAXN = 100000 + 10;

PII task[MAXN];
int n;

int main() {
	freopen("pulp.in", "r", stdin);
	freopen("pulp.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i) {
		scanf("%d%d", &task[i].first, &task[i].second);
	}
	priority_queue<LL, vector<LL>, greater<LL> > Q;
	sort(task, task + n);
	LL ret = 0, now;
	for (LL i = 0, pre = 0; i < n; ) {
		now = task[i].first;
		while (!Q.empty()) {
			LL time = Q.top(); Q.pop();
			if (now - pre >= time) {
				pre += time;
				ret += pre;
			}
			else {
				Q.push(time - (now - pre));
				break;
			}
		}
		while (i < n && task[i].first <= now) Q.push(task[i ++].second);
		pre = now;
	}
	while (!Q.empty()) {
		now += Q.top(); Q.pop();
		ret += now;
	}
	printf("%I64d\n", ret);
	fclose(stdin); fclose(stdout);
	return 0;
}
