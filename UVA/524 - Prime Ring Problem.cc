#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int n, visited[30], buffer[30], ans, flag;

bool is_prime(int x,int y) {
	int sum = x + y;
	for (int i = 2; i * i <= sum; ++ i) if (sum % i == 0) return 0;
	return 1;
}

void dfs(int cur) {
	visited[1] = 1;
	if (cur > n && is_prime(buffer[1], buffer[n])) {
        if (!flag) printf("Case %d:\n", ans), flag = 1;
        for (int i = 1; i < n; ++ i) printf("%d ", buffer[i]);
		printf("%d\n", buffer[n]);
    } else {
		for (int i = 2; i <= n; ++ i) {
			buffer[cur] = i;
			if (!visited[i] && is_prime(buffer[cur - 1], buffer[cur])) {
				visited[i] = 1;
				dfs(cur + 1);
				visited[i] = 0;
			}
		}
	}
}

int main() {
	ans = 0;
	while (scanf("%d", &n) == 1) {
		if (ans) puts("");
		ans ++;
		flag = 0;
		memset(visited, 0 ,sizeof(visited));
		buffer[1] = 1;
		dfs(2);
	}
	return 0;
}

