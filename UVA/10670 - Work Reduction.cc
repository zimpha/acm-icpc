#include<cstdio>  
#include<cstdlib>  
#include<cstring>  
#include<algorithm>
#include<algorithm>
using namespace std;

struct Node {
	int A, B, V;  
	char name[20];
	bool operator < (const Node &rhs) const {
		if (V == rhs.V) return strcmp(name, rhs.name) < 0;
		else return V < rhs.V;
	}
} agency[102];

int main() {
	int T; scanf("%d", &T);
	for (int cas = 1; cas <= T; ++ cas) {
		char str[50];
		int N, M, num;  
		scanf("%d%d%d", &N, &M, &num);  
		for (int i = 0; i < num; ++ i) {
			scanf("%s", str);
			sscanf(str, "%[^:]:%d,%d", agency[i].name, &agency[i].A, &agency[i].B);
		}
		for (int i = 0; i < num; ++ i) {
			int tem_a = 0, tem_b = 0, n = N;
			while (n / 2 >= M && agency[i].A * (n / 2) > agency[i].B) {
				n /= 2;
				++ tem_b;
			}
			tem_a = n - M;
			agency[i].V = tem_b * agency[i].B + tem_a * agency[i].A;
		}
		sort(agency, agency + num);
		printf("Case %d\n", cas);
		for (int i = 0; i < num; i++) printf("%s %d\n", agency[i].name, agency[i].V);
	}
	return 0;
}  
