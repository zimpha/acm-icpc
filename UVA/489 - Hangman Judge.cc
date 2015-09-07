#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
	int round;
	while (cin>>round)
	{
		if (round==-1) break;
		string ans,tmp;
		int count=0,solve=0;
		cin>>ans>>tmp;
		for (int i=0;i<tmp.size();i++)
		{
			bool flag=0;
			for (int j=0;j<i;j++)
				if (tmp[i]==tmp[j]) flag=1;
			if (flag) continue;
			flag=0;
			for (int j=0;j<ans.size();j++)
			{
				if (ans[j]==tmp[i])
				{
					ans[j]=' ';
					flag=1;
					solve++;
				}
			}
			if (count==7) break;
			if (solve==ans.size()) break;
			if (!flag) count++;
		}
		cout<<"Round "<<round<<endl;
		if (count==7) cout<<"You lose."<<endl;
		else if (solve==ans.size()) cout<<"You win."<<endl;
		else cout<<"You chickened out."<<endl;
	}
	return 0;
}
