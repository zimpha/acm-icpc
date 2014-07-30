#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN=100;

string st;
int cipher[MAXN];
int plain[MAXN];
int N, K;

int main()
{
	while ((cin >> K)&&K)
	{
		cin >> st;
		N=st.length();
		for (int i=0; i<N; i++)
		{
			if (st[i]=='_') cipher[i]=0;
			else if (st[i]=='.') cipher[i]=27;
			else cipher[i]=st[i]-'a'+1;
		}
		for (int i=0; i<N; i++) plain[K*i%N]=(cipher[i]+i)%28;
		for (int i=0; i<N; i++)
		{
			if (plain[i]==0) cout << "_";
			else if (plain[i]==27) cout << ".";
			else cout << (char)(plain[i]+'a'-1);
		}
		cout << endl;
	}
	return 0;
}
