#include <map>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int MAXN = 1000000 + 10;
typedef pair<int, int> PII;

map<PII, int> Cache;
char st[MAXN];
int N;

int main() {
	scanf("%s", st);	
	int N = strlen(st);
	Cache.clear(); Cache[make_pair(0, 0)] = 1;
	long long ret = 0;
	int AB = 0, BC = 0;
	for (int i = 0; i < N; ++ i) {
		if (st[i] == 'A') AB ++;
		else if (st[i] == 'B') AB --, BC ++;
		else BC --;
		PII sum = make_pair(AB, BC);
		if (Cache.find(sum) != Cache.end()) {
			ret += (long long)Cache[sum];
		}
		else Cache[sum] = 0;
		Cache[sum] ++;
	}
	printf("%lld\n", ret);
	return 0;
}
